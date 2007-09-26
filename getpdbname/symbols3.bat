@rem = '--*-Perl-*--
@echo off
if "%OS%" == "Windows_NT" goto WinNT
perl -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
goto endofperl
:WinNT
perl -x -S "%0" %*
if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" goto endofperl
if %errorlevel% == 9009 echo You do not have Perl in your PATH.
goto endofperl
@rem ';
#!perl
#line 14

use IO::Handle;
use FCntl;

$newline = "\n";

sub StringIndex
{
    my($string, $index) = ($_[0], $_[1]);

    return substr($string, $index, 1);

}

sub GetFileSize
{
    my($file_handle) = ($_[0]);

    return -s $file_handle;
}

sub OpenAndReadEntireBinaryFileAsString
{
    my($path) = ($_[0]);
    my($handle);
    my($contents);

    $handle = IO::Handle->new();
    sysopen($handle, $path, O_RDONLY | O_BINARY) or die('error opening ' . $path . ': ' . $!);
    read($handle, $contents, GetFileSize($handle));

    return $contents;
}

$image_size_of_file_header = 20;
$image_size_of_rom_optional_header = 56;
$image_nt_optional_header_magic = 0x10b;
$image_nt_optional_header64_magic = 0x20b;
$image_rom_optional_header_magic = 0x107;
$image_file_machine_x86 = 0x014c;
$image_file_machine_ia64 = 0x200;
$image_file_machine_amd64 = 0x8664;
$image_optional_header64_unpack_string = '';
$image_optional_header_unpack_string = '';

sub ImageOpen
{
  my($path) = ($_[0]);
  my(%image);
  my($file_handle);
  my(%file_header);
  my(%nt_headers);
  my(%optional_header);
  my(@section_headers);
  my(%section_header);
  my($contents);
  my($offset_to_pe);
  my($mz_signature);
  my($pe_signature);
  my($offset_to_file_header);
  my($offset_to_optional_header);
  my($msdos_header);
  my($buffer);
  my($file_size);
  
  $image{'file_path'} = $path;
  $file_handle = IO::Handle->new();
  #sysopen($file_handle, $path, O_RDONLY | O_BINARY) || die('open ' . $path . ': ' . $!);
  open($file_handle, '<', $path) || die('open ' . $path . ': ' . $!);
  binmode($file_handle);
  $file_size = GetFileSize($path);
  $image{'file_size'} = $file_size;
  read($file_handle, $msdos_header, 64) || die('read ' . $path . ':' . $!);
  $mz_signature = substr($msdos_header, 0, 2); 
  if ($mz_signature ne 'MZ')
  {
    die('invalid MZ signature in ' . $path);
  }
  seek($file_handle, 60, 0) ;#|| die('seek ' . $path . ':' . $!);
  $offset_to_pe = unpack('V', substr($msdos_header, 60, 4));
  if ($offset_to_pe + 4 >= $file_size)
  {
     die('invalid offset_to_pe ' . $offset_to_pe . ' in ' . $path);
  }
  seek($file_handle, $offset_to_pe, 0) || die('seek ' . $path . ':' . $!);
  read($file_handle, $pe_signature, 4) || die('read ' . $path . ':' . $!);
  if ($pe_signature ne 'PE' . $nul . $nul)
  {
    die('invalid PE signature in ' . $path);
  }
  read($file_handle, $buffer, $image_size_of_file_header) || die('read ' . $path . ':' . $!);  
  ($file_header{'machine'},
   $file_header{'number_of_sections'},
   $file_header{'time_date_stamp'},
   $file_header{'pointer_to_symbol_table'},
   $file_header{'number_of_symbols'},
   $file_header{'size_of_optional_header'},
   $file_header{'characteristics'}
  ) = unpack('vvVVVvvv', $buffer); 
  read($file_handle, $buffer,2) || die('read ' . $path . ':' . $!);  
  $optional_header{'magic'} = unpack('v', $buffer);
  if ($optional_header{'magic'} == $image_nt_optional_header_magic)
  {
  }
  elsif ($optional_header{'magic'} == $image_nt_optional_header_magic)
  {
  }
  else
  {
    die('unknown optional_header.magic in ' . $path);
  }
  
  $image{'nt_headers'} = \%$nt_headers;
  $image{'file_header'} = \%file_header;
  $image{'optional_header'} = \%optional_header;
  $nt_headers{'file_header'} = \%file_header;
  $nt_headers{'optional_header'} = \%optional_header;
  return %image;
}

sub ByteStringToLittleEndianInteger
{
  my($s) = ($_[0]);
  my($result, $i, $length);

  $length = length($s);
  for ($i = 0 ; $i != $length ; ++$i)
  {
    $result <<= 8;
    $result |= ord(substr($s, $length - $i - 1, 1));
  }
  return $result;
}

$nul = "\0";

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

%image = ImageOpen($ARGV[0]);

__END__
:endofperl
