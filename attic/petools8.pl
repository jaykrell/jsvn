#!/usr/bin/perl

use strict;
use warnings;
use bytes;
use IO::Handle;
use Getopt::Long;
use Fcntl;

use constant image_size_of_file_header => 20;
use constant image_size_of_rom_optional_header => 56;
# Remember optional header size can vary fairly arbitrarily.
use constant image_size_of_standard_optional_header => 28;
use constant image_size_of_nt_optional_header => 224;
use constant image_size_of_nt_optional64_header => 240;
use constant image_nt_optional_header32_magic => 0x10b;
use constant image_nt_optional_header64_magic => 0x20b;
use constant image_rom_optional_header_magic => 0x107;
use constant image_file_machine_x86 => 0x014c;
use constant image_file_machine_ia64 => 0x200;
use constant image_file_machine_amd64 => 0x8664;
use constant image_directory_entry_export       => 0;
use constant image_directory_entry_import       => 1;
use constant image_directory_entry_resource     => 2;
use constant image_directory_entry_exception    => 3;
use constant image_directory_entry_security     => 4;
use constant image_directory_entry_basereloc    => 5;
use constant image_directory_entry_debug        => 6;
use constant image_directory_entry_architecture => 7;
use constant image_directory_entry_globalptr      => 8;
use constant image_directory_entry_tls            => 9;
use constant image_directory_entry_load_config    => 10;
use constant image_directory_entry_bound_import   => 11;
use constant image_directory_entry_iat            => 12;
use constant image_directory_entry_delay_import   => 13;
use constant image_directory_entry_com_descriptor => 14;
# typedef struct _IMAGE_OPTIONAL_HEADER {
#    standard fields
#    unsigned short  Magic;                         v
#    unsigned char   MajorLinkerVersion;            C
#    unsigned char   MinorLinkerVersion;            C
#    unsigned long   SizeOfCode;                    V
#    unsigned long   SizeOfInitializedData;         V
#    unsigned long   SizeOfUninitializedData;       V
#    unsigned long   AddressOfEntryPoint;           V
#    unsigned long   BaseOfCode;                    V
#    unsigned long   BaseOfData;                    V
#    nt fields
#    unsigned long   ImageBase;                     V
#    unsigned long   SectionAlignment;              V
#    unsigned long   FileAlignment;                 V
#    unsigned short  MajorOperatingSystemVersion;   v
#    unsigned short  MinorOperatingSystemVersion;   v
#    unsigned short  MajorImageVersion;             v
#    unsigned short  MinorImageVersion;             v
#    unsigned short  MajorSubsystemVersion;         v
#    unsigned short  MinorSubsystemVersion;         v
#    unsigned long   Win32VersionValue;             V
#    unsigned long   SizeOfImage;                   V
#    unsigned long   SizeOfHeaders;                 V
#    unsigned long   CheckSum;                      V
#    unsigned short  Subsystem;                     v
#    unsigned short  DllCharacteristics;            v
#    unsigned long   SizeOfStackReserve;            V
#    unsigned long   SizeOfStackCommit;             V
#    unsigned long   SizeOfHeapReserve;             V
#    unsigned long   SizeOfHeapCommit;              V
#    unsigned long   LoaderFlags;                   V
#    unsigned long   NumberOfRvaAndSizes;           V
#    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
#} IMAGE_OPTIONAL_HEADER, *PIMAGE_OPTIONAL_HEADER;
#
#typedef struct _IMAGE_OPTIONAL_HEADER64 {
#    unsigned short          Magic;                         v
#    unsigned char           MajorLinkerVersion;            C
#    unsigned char           MinorLinkerVersion;            C
#    unsigned long           SizeOfCode;                    V
#    unsigned long           SizeOfInitializedData;         V
#    unsigned long           SizeOfUninitializedData;       V
#    unsigned long           AddressOfEntryPoint;           V
#    unsigned long           BaseOfCode;                    V
#    unsigned __int64        ImageBase;                     VV
#    unsigned long           SectionAlignment;              V
#    unsigned long           FileAlignment;                 V
#    unsigned short          MajorOperatingSystemVersion;   v
#    unsigned short          MinorOperatingSystemVersion;   v
#    unsigned short          MajorImageVersion;             v
#    unsigned short          MinorImageVersion;             v
#    unsigned short          MajorSubsystemVersion;         v
#    unsigned short          MinorSubsystemVersion;         v
#    unsigned long           Win32VersionValue;             V
#    unsigned long           SizeOfImage;                   V
#    unsigned long           SizeOfHeaders;                 V
#    unsigned long           CheckSum;                      V
#    unsigned short          Subsystem;                     v
#    unsigned short          DllCharacteristics;            v
#    unsigned __int64        SizeOfStackReserve;            VV
#    unsigned __int64        SizeOfStackCommit;             VV
#    unsigned __int64        SizeOfHeapReserve;             VV
#    unsigned __int64        SizeOfHeapCommit;              VV
#    unsigned long           LoaderFlags;                   V
#    unsigned long           NumberOfRvaAndSizes;           V
#    IMAGE_DATA_DIRECTORY    DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
#} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

use constant image_optional_header32_without_magic_unpack_format_string => 'CCVVVVVVVVVvvvvvvVVVVvvVVVVVV';
use constant image_optional_header64_without_magic_unpack_format_string => 'CCVVVVVVVVVvvvvvvVVVVvvVVVVVVVVVV';
use constant image_optional_header32_unpack_format_string => 'v' . image_optional_header32_without_magic_unpack_format_string;
use constant image_optional_header64_unpack_format_string => 'v' . image_optional_header64_without_magic_unpack_format_string;

use constant image_section_flag_writable => 0x80000000;

use constant newline => "\n";
use constant nul => "\0";

sub DebugPrint { print($_[0]); }
sub DebugExit { exit; }

sub IntegerToString
{
    my $integer = shift;
    return '' . $integer;
}

sub ImageDirectoryIndexToString
{
    my $index = shift;
    my $known =
        ['export        ',
         'import        ',
         'resource      ',
         'exception     ',
         'security      ',
         'basereloc     ',
         'debug         ',
         'architecture  ',
         'globalptr     ',
         'tls           ',
         'load_config   ',
         'bound_import  ',
         'iat           ',
         'delay_import  ',
         'com_descriptor'
        ];
    if ($index < length($known))
    {
        return $$known[$index];
    }
    return IntegerToString($index);
}

sub ImageSubsystemToString
{
    my $index = shift;
    my $known =
        ['unknown                 ', # 0
         'native                  ', # 1
         'windows_gui             ', # 2
         'windows_console         ', # 3
         '4                       ', # 4
         'os2_console             ', # 5
         '6                       ', # 6
         'posix_console           ', # 7
         '8                       ', # 8
         'windows_ce_gui          ', # 9
         'efi_application         ', # 10
         'efi_boot_service_driver ', # 11
         'efi_runtime_driver      ', # 12
         'efi_rom                 ', # 13
         'xbox                    ', # 14
        ];
    if ($index < length($known))
    {
        return $$known[$index];
    }
    return IntegerToString($index);
}

sub StringIndex
{
    my $string = shift;
	my $index = shift;

    return substr($string, $index, 1);
}

sub SeekTo
{
    my $file_handle = shift;
	my $offset = shift;

    return seek($file_handle, $offset, 0);
}

sub SeekForward
{
    my $file_handle = shift;
	my $offset = shift;

    return seek($file_handle, $offset, 1);
}

sub SeekBackward
{
    my $file_handle = shift;
	my $offset = shift;

    return seek($file_handle, $offset, 2);
}

sub ReadFile
{
    my $file_handle = shift;
    my $buffer = shift;
    my $number_of_bytes_to_read = shift;

    my $result = read($file_handle, $$buffer, $number_of_bytes_to_read);

    return $result;
}

sub GetFileSize
{
    my $file_handle = shift;

    return -s $file_handle;
}

#sub OpenAndReadEntireBinaryFileAsString
#{
#    my($file_path) = ($_[0]);
#    my($handle);
#    my($contents);
#
#    $handle = IO::Handle->new();
#    sysopen($handle, $file_path, O_RDONLY | O_BINARY) or die('error opening ' . $file_path . ': ' . $!);
#    ReadFile($handle, \$contents, GetFileSize($handle));
#
#    return $contents;
#}

sub ComputeUnpackBufferSize
{
    my $unpack_format = shift;
    my $index;
    my $character;
    my $result;

    $result = 0;
    #DebugPrint($unpack_format . newline);
    for ($index = 0 ; $index != length($unpack_format) ; ++$index)
    {
        $character = substr($unpack_format, $index, 1);
        if ($character eq 'v')
        {
            $result += 2;
        }
        elsif ($character eq 'V')
        {
            $result += 4;
        }
        elsif ($character eq 'C')
        {
            $result += 1;
        }
        elsif ($character eq 'A')
        {
            # assume a single digit width
			$index += 1;
            $result += substr($unpack_format, $index, 1) - '0';
        }
        else
        {
            die('unknown format character ' . $character);
        }
        #DebugPrint($character . newline);
        #DebugPrint($result . newline);
    }
    #DebugPrint($result . newline);
    return $result;
}

sub NewHashRef { my %x; return \%x; }
sub NewArrayRef { my @x; return \@x; }


sub ImageDump
{
    my $image = shift;
    my $file_header = $image->{file_header};
    my $optional_header = $image->{optional_header};
    my $section_headers = $image->{section_headers};
    my $i;
    my $j;

    foreach my $key (sort(keys(%$optional_header)))
    {
        if ($key eq 'data_directory')
        {
            my($data_directory_array) = ($optional_header->{data_directory});
            $j = length($data_directory_array);
            for ($i = 0 ; $i != $j ; ++$i)
            {
                my($data_directory) = ($data_directory_array->[$i]);
                my($virtual_address) = $data_directory->{virtual_address};
                my($size) = $data_directory->{size};
                if ($size != 0 || $virtual_address != 0)
                {
                    DebugPrint(sprintf('data_directory[' . ImageDirectoryIndexToString($i) . '].virtual_address 0x%x' . newline, $virtual_address));
                    DebugPrint(sprintf('data_directory[' . ImageDirectoryIndexToString($i) . '].size            0x%x' . newline, $size));
                }
            }
        }
        else
        {
            DebugPrint(sprintf($key . ' 0x%x' . newline, $optional_header->{$key}));
        }
    }
    $j = $file_header->{number_of_sections};
    for ($i = 0 ; $i != $j ; ++$i)
    {
        my $section_header = $$section_headers[$i];
        DebugPrint('section header' . newline);
        DebugPrint('  name: ' . $section_header->{name} . newline);
        DebugPrint(sprintf('  virtual_size: 0x%x' . newline, $section_header->{virtual_size}));
        DebugPrint(sprintf('  virtual_address: 0x%x' . newline, $section_header->{virtual_address}));
        DebugPrint(sprintf('  size_of_raw_data: 0x%x' . newline, $section_header->{size_of_raw_data}));
        DebugPrint(sprintf('  pointer_to_relocations: 0x%x' . newline, $section_header->{pointer_to_relocations}));
        DebugPrint(sprintf('  pointer_to_line_numbers: 0x%x' . newline, $section_header->{pointer_to_line_numbers}));
        DebugPrint(sprintf('  number_of_relocations: 0x%x' . newline, $section_header->{number_of_relocations}));
        DebugPrint(sprintf('  number_of_line_numbers: 0x%x' . newline, $section_header->{number_of_line_numbers}));
        DebugPrint(sprintf('  characteristics: 0x%x' . newline, $section_header->{characteristics}));
    }

    my $file_path = $image->{file_path};
	my $number_of_writable_sections = 0;
	my $number_of_readonly_sections = 0;
    $j = $file_header->{number_of_sections};
	for ($i = 0 ; $i != $j ; ++$i)
	{
		my $section_header = $$section_headers[$i];
		my $characteristics = $section_header->{characteristics};
		if (($characteristics & image_section_flag_writable) != 0)
		{
			print(sprintf("file %s section %s is writable\n", $file_path, $section_header->{name}));
			$number_of_writable_sections += 1;
		}
		else
		{
			print(sprintf("file %s section %s is not writable\n", $file_path, $section_header->{name}));
			$number_of_readonly_sections += 1;
		}
	}
	print(sprintf("file %s has %d readonly sections and %d writable sections\n",
		$file_path,
		$number_of_readonly_sections,
		$number_of_writable_sections
		));
}

sub ImageOpen
{
    my $file_path = shift;
    my $offset_to_file_header;
    my $offset_to_optional_header;
    my $buffer;
    my $unpack_format_string;
    my $i;
    my $j;
    
    my $image = NewHashRef();
    my $section_headers = NewArrayRef();
    my $section_header = NewHashRef();
    my $file_header = NewHashRef();
    my $optional_header = NewHashRef();
    my $nt_headers = NewHashRef();
        
    $image->{file_path} = $file_path;
    my $file_handle = IO::Handle->new();
    # DebugPrint($file_path . newline);
    sysopen($file_handle, $file_path, O_RDONLY | O_BINARY) || die('open ' . $file_path . ': ' . $!);
    my $file_size = GetFileSize($file_path);
    $image->{file_size} = $file_size;

    #
    # read 64 bytes, first two bytes are MZ signature, last 4 bytes are offset_to_pe
    #    
    SeekTo($file_handle, 0) || die('seek ' . $file_path . ':' . $!);
    ReadFile($file_handle, \$buffer, 64) || die('read ' . $file_path . ':' . $!);
    my $mz_signature = substr($buffer, 0, 2);
    if ($mz_signature ne 'MZ')
    {
        die('invalid MZ signature (' . $mz_signature . ') in ' . $file_path);
    }
    my $offset_to_pe = unpack('V', substr($buffer, 60, 4));
    if ($offset_to_pe + 4 >= $file_size)
    {
        die('invalid offset_to_pe ' . $offset_to_pe . ' in ' . $file_path);
    }
    $image->{offset_to_pe} = $offset_to_pe;
    
    #
    # seek to PE signature
    # 4 byte PE signature, 20 byte file_header, 32bit or 64bit optional_header with initial 2 byte magic
    #
    #DebugPrint($offset_to_pe . newline);
    SeekTo($file_handle, $offset_to_pe) || die('seek ' . $file_path . ':' . $!);
    ReadFile($file_handle, \$buffer, image_size_of_file_header + 4 + 2) || die('read ' . $file_path . ':' . $!);
    my $pe_signature = substr($buffer, 0, 4);
    #DebugPrint($pe_signature . newline);
    if ($pe_signature ne 'PE' . nul . nul)
    {
        die('invalid PE signature (' . $pe_signature . ') in ' . $file_path);
    }
    (
        $file_header->{machine},
        $file_header->{number_of_sections},
        $file_header->{time_date_stamp},
        $file_header->{pointer_to_symbol_table},
        $file_header->{number_of_symbols},
        $file_header->{size_of_optional_header},
        $file_header->{characteristics}
    ) = unpack('vvVVVvv', substr($buffer, 4, image_size_of_file_header));
    my $optional_header_magic = unpack('v', substr($buffer, 4 + image_size_of_file_header, 2));
    $optional_header->{magic} = $optional_header_magic;
    if ($optional_header_magic == image_nt_optional_header32_magic)
    {
        $unpack_format_string = image_optional_header32_without_magic_unpack_format_string;
        ReadFile($file_handle, \$buffer, ComputeUnpackBufferSize($unpack_format_string)) || die('read ' . $file_path . ':' . $!);
        (
            $optional_header->{major_linker_version},
            $optional_header->{minor_linker_version},
            $optional_header->{size_of_code},
            $optional_header->{size_of_initialized_data},
            $optional_header->{size_of_uninitialized_data},
            $optional_header->{address_of_entry_point},
            $optional_header->{base_of_code},
            $optional_header->{base_of_data},
            $optional_header->{image_base},
            $optional_header->{section_alignment},
            $optional_header->{file_alignment},
            $optional_header->{major_operating_system_version},
            $optional_header->{minor_operating_system_version},
            $optional_header->{major_image_version},
            $optional_header->{minor_image_version},
            $optional_header->{major_subsystem_version},
            $optional_header->{minor_subsystem_version},
            $optional_header->{win32_version_value},
            $optional_header->{size_of_image},
            $optional_header->{size_of_headers},
            $optional_header->{checksum},
            $optional_header->{subsystem},
            $optional_header->{dll_characteristics},
            $optional_header->{size_of_stack_reserve},
            $optional_header->{size_of_stack_commit},
            $optional_header->{size_of_heap_reserve},
            $optional_header->{size_of_heap_commit},
            $optional_header->{loader_flags},
            $optional_header->{number_of_rva_and_sizes}
        ) = unpack($unpack_format_string, $buffer);
        $optional_header->{image_base_high} = 0;
        $optional_header->{size_of_stack_reserve_high} = 0;
        $optional_header->{size_of_stack_commit_high} = 0;
        $optional_header->{size_of_heap_reserve_high} = 0;
        $optional_header->{size_of_heap_commit_high} = 0;
        
        #DebugPrint($optional_header->{size_of_code} . newline);
        #DebugExit();
    }
    elsif ($optional_header_magic == image_nt_optional_header64_magic)
    {
        $unpack_format_string = image_optional_header64_without_magic_unpack_format_string;
        ReadFile($file_handle, \$buffer, ComputeUnpackBufferSize($unpack_format_string)) || die('read ' . $file_path . ':' . $!);
        (
            $optional_header->{major_linker_version},
            $optional_header->{minor_linker_version},
            $optional_header->{size_of_code},
            $optional_header->{size_of_initialized_data},
            $optional_header->{size_of_uninitialized_data},
            $optional_header->{address_of_entry_point},
            $optional_header->{base_of_code},
            $optional_header->{image_base},
            $optional_header->{image_base_high},
            $optional_header->{section_alignment},
            $optional_header->{file_alignment},
            $optional_header->{major_operating_system_version},
            $optional_header->{minor_operating_system_version},
            $optional_header->{major_image_version},
            $optional_header->{minor_image_version},
            $optional_header->{major_subsystem_version},
            $optional_header->{minor_subsystem_version},
            $optional_header->{win32_version_value},
            $optional_header->{size_of_image},
            $optional_header->{size_of_headers},
            $optional_header->{checksum},
            $optional_header->{subsystem},
            $optional_header->{dll_characteristics},
            $optional_header->{size_of_stack_reserve},
            $optional_header->{size_of_stack_reserve_high},
            $optional_header->{size_of_stack_commit},
            $optional_header->{size_of_stack_commit_high},
            $optional_header->{size_of_heap_reserve},
            $optional_header->{size_of_heap_reserve_high},
            $optional_header->{size_of_heap_commit},
            $optional_header->{size_of_heap_commit_high},
            $optional_header->{loader_flags},
            $optional_header->{number_of_rva_and_sizes}
        ) = unpack($unpack_format_string, $buffer);
    }
    else
    {
        die('unknown optional_header.magic in ' . $file_path);
    }
    $j = $optional_header->{number_of_rva_and_sizes};
    if ($j != 0)
    {
        #DebugPrint($j . newline);
        ReadFile($file_handle, \$buffer, $j * 8) || die('read ' . $file_path . ':' . $!);

        for ($i = 0 ; $i != $j ; ++$i)
        {
            (
                $optional_header->{data_directory}[$i]{virtual_address},
                $optional_header->{data_directory}[$i]{size}
            ) = unpack('VV', substr($buffer, $i * 8, 8));
        }
    }

    $unpack_format_string = 'A8VVVVVVvvV';
    my $section_header_size = ComputeUnpackBufferSize($unpack_format_string);
    #DebugPrint($file_header->{size_of_optional_header} . newline);
    #DebugPrint($offset_to_pe + 4 + image_size_of_file_header + $file_header->{size_of_optional_header} . newline);
    SeekTo($file_handle, $offset_to_pe + 4 + image_size_of_file_header + $file_header->{size_of_optional_header}) || die('seek ' . $file_path . ':' . $!);
    $j = $file_header->{number_of_sections};
    ReadFile($file_handle, \$buffer, $j * $section_header_size) || die('read ' . $file_path . ':' . $!);
    for ($i = 0 ; $i != $j ; ++$i)
    {
        $section_header = NewHashRef();
        (
            $section_header->{name},
            $section_header->{virtual_size},
            $section_header->{virtual_address},
            $section_header->{size_of_raw_data},
            $section_header->{pointer_to_raw_data},
            $section_header->{pointer_to_relocations},
            $section_header->{pointer_to_line_numbers},
            $section_header->{number_of_relocations},
            $section_header->{number_of_line_numbers},
            $section_header->{characteristics},
        ) = unpack($unpack_format_string, substr($buffer, $i * $section_header_size, $section_header_size));
        $$section_headers[$i] = $section_header;
    }
    #DebugPrint($$section_headers[0]);
    #DebugPrint($$section_headers[12]);
    #DebugExit();

    $nt_headers->{file_header} = $file_header;
    $nt_headers->{optional_header} = $optional_header;
    $image->{nt_headers} = $nt_headers;
    $image->{file_header} = $file_header;
    $image->{optional_header} = $optional_header;
    $image->{section_headers} = $section_headers;
    return $image;
}

sub ByteStringToLittleEndianInteger
{
    my $s = shift;
    my $result = 0;

    my $length = length($s);
    for (my $i = 0 ; $i != $length ; ++$i)
    {
        $result <<= 8;
        $result |= ord(substr($s, $length - $i - 1, 1));
    }
    return $result;
}

sub ImageSectionIndexFromRelativeVirtualAddress
{
}

sub ImageSectionIndexFromVirtualAddress
{
}

sub ImageFileOffsetFromVirtualAddress
{
}

sub ImageFileOffsetFromRelativeVirtualAddress
{
}

sub ImageReportAboutAddingDataDirectory
{
}

my @argv_files = ();
my @argv_options = ();

foreach my $arg (@ARGV)
{
	if ($arg =~ /^-/)
	{
		push(@argv_options, $arg);
	}
	else
	{
		push(@argv_files, $arg);
	}
}

my $dump = 0;
my $report_about_adding_data_directory = 0;

GetOptions(
	"dump" => \$dump,
    "report_about_adding_data_directory" => \$report_about_adding_data_directory
	);

foreach my $image_file_path (@ARGV)
{
	my $image = ImageOpen($image_file_path);
	if ($dump)
	{
		ImageDump($image);
	}
	if ($report_about_adding_data_directory)
	{
		ImageReportAboutAddingDataDirectory($image);
	}
}
