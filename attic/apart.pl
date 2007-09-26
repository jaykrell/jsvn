#!/usr/bin/perl

use strict;
use IO::Handle;
use FCntl;
use Data::Dumper;

my $newline = "\n";

my $block0Signature = unpack('n', 'ER');
my $partitionMapSignature = unpack('n', 'PM');
my $partitionMapEntrySignature = $partitionMapSignature;

sub OpenBinaryFileForWrite
{
    my($file_handle);
    my($file_path) = ($_[0]);
    
    $file_handle = IO::Handle->new();
    #sysopen($file_handle, $file_path, O_RDWR | O_BINARY | O_CREAT) || return undef;
    open($file_handle, '> ' . $file_path) || return undef;
    binmode($file_handle);
    
    return $file_handle;
}

sub OpenBinaryFileForRead
{
    my($file_handle);
    my($file_path) = ($_[0]);
    
    $file_handle = IO::Handle->new();
    #sysopen($file_handle, $file_path, O_RDONLY | O_BINARY) || return undef;
    open($file_handle, '< ' . $file_path) || return undef;
    binmode($file_handle);

    return $file_handle;
}

sub SeekTo
{
    my($file_handle, $offset) = ($_[0], $_[1]);

    return sysseek($file_handle, $offset, 0);
}

sub SeekForward
{
    my($file_handle, $offset) = ($_[0], $_[1]);

    return sysseek($file_handle, $offset, 1);
}

sub SeekBackward
{
    my($file_handle, $offset) = ($_[0], $_[1]);

    return sysseek($file_handle, $offset, 2);
}

sub ReadFile
{
    my($file_handle, $buffer, $number_of_bytes) = ($_[0], $_[1], $_[2]);
    my($result);

    $result = sysread($file_handle, $$buffer, $number_of_bytes);

    return $result;
}

sub WriteFile
{
    my($file_handle, $buffer, $number_of_bytes) = ($_[0], $_[1], $_[2]);
    my($result);

    $result = syswrite($file_handle, $$buffer, $number_of_bytes);

    return $result;
}

sub GetFileSize
{
    my($file_handle) = ($_[0]);

    return -s $file_handle;
}

sub NewHashRef { my(%x); return \%x; }

my $block_size = 512;

sub ReadBlock
{
    my($file_handle) = ($_[0]);
    my($buffer);
    
    ReadFile($file_handle, \$buffer, $block_size);    
    return $buffer;
}

sub SeekToBlock
{
    my($file_handle, $offset) = ($_[0], $_[1]);

    return SeekTo($file_handle, $offset * $block_size);
}

sub UnpackPartitionMapEntry
{
# /* Partition Map Entry */
# struct Partition {
#   UInt16              pmSig;                  /* unique value for map entry blk */
#   UInt16              pmSigPad;               /* currently unused */
#   UInt32              pmMapBlkCnt;            /* # of blks in partition map */
#   UInt32              pmPyPartStart;          /* physical start blk of partition */
#   UInt32              pmPartBlkCnt;           /* # of blks in this partition */
#   UInt8               pmPartName[32];         /* ASCII partition name */
#   UInt8               pmParType[32];          /* ASCII partition type */
#   UInt32              pmLgDataStart;          /* log. # of partition's 1st data blk */
#   UInt32              pmDataCnt;              /* # of blks in partition's data area */
#   UInt32              pmPartStatus;           /* bit field for partition status */
#   UInt32              pmLgBootStart;          /* log. blk of partition's boot code */
#   UInt32              pmBootSize;             /* number of bytes in boot code */
#   UInt32              pmBootAddr;             /* memory load address of boot code */
#   UInt32              pmBootAddr2;            /* currently unused */
#   UInt32              pmBootEntry;            /* entry point of boot code */
#   UInt32              pmBootEntry2;           /* currently unused */
#   UInt32              pmBootCksum;            /* checksum of boot code */
#   UInt8               pmProcessor[16];        /* ASCII for the processor type */
#   UInt16              pmPad[188];             /* ARRAY[0..187] OF INTEGER; not used */
# };
# typedef struct Partition                Partition;
    my($buffer) = ($_[0]);
    my($x);
    my($first_logical_block_of_data_area);
    my($first_logical_block_of_boot_code);
    (    
        $x->{'signature'},
        $x->{'unused1'},
        $x->{'number_of_blocks_in_partition_map'},
        $x->{'first_physical_block_of_partition'},
        $x->{'number_of_blocks_in_partition'},
        $x->{'partition_name'},
        $x->{'partition_type'},
        $x->{'first_logical_block_of_data_area'},
        $x->{'number_of_blocks_in_data_area'},
        $x->{'status'},
        $x->{'first_logical_block_of_boot_code'},
        $x->{'size_of_boot_code_in_bytes'},
        $x->{'boot_code_load_address'},
        $x->{'unused2'},
        $x->{'boot_code_entry_point'},
        $x->{'unused3'},
        $x->{'boot_code_checksum'},
        $x->{'processor_type'}
    ) = unpack('nnNNNZ32Z32NNNNNNNNNNZ32', $buffer);
       return $x;
}

sub UnpackBlock0
{
# /* Driver Descriptor Map */
# struct Block0 {
#   UInt16              sbSig;                  /* unique value for SCSI block 0 */
#   UInt16              sbBlkSize;              /* block size of device */
#   UInt32              sbBlkCount;             /* number of blocks on device */
#   UInt16              sbDevType;              /* device type */
#   UInt16              sbDevId;                /* device id */
#   UInt32              sbData;                 /* not used */
#   UInt16              sbDrvrCount;            /* driver descriptor count */
#   UInt32              ddBlock;                /* 1st driver's starting block */
#   UInt16              ddSize;                 /* size of 1st driver (512-byte blks) */
#   UInt16              ddType;                 /* system type (1 for Mac+) */
#   UInt16              ddPad[243];             /* ARRAY[0..242] OF INTEGER; not used */
# };
# typedef struct Block0                   Block0;
#
# /* Driver descriptor */
# struct DDMap {
#   UInt32              ddBlock;                /* 1st driver's starting block */
#   UInt16              ddSize;                 /* size of 1st driver (512-byte blks) */
#   UInt16              ddType;                 /* system type (1 for Mac+) */
# };
# typedef struct DDMap                    DDMap;
#
# We do not read in the array of drivers.
#
    my($buffer) = ($_[0]);
    my($x);
    $x = NewHashRef();
    (    
        $x->{'signature'},
        $x->{'block_size'},
        $x->{'block_count'},
        $x->{'device_type'},
        $x->{'device_id'},
        $x->{'unused1'},
        $x->{'driver_count'},
        $x->{'first_driver_start'},
        $x->{'first_driver_size'},
        $x->{'first_driver_type'}
    ) = unpack('nnNnnNnNnn', $buffer);
    return $x;
}

sub Main
{
    my($file_path) = ($_[0]);
    my($file_handle);
    my($block0);
    my($partition_map_entry);
    my(@partition_map);
    my($number_of_partitions);
    my($i);
    my($buffer);
    my($partition_name);
    my($partition_file_handle);
    my($start);
    my($size);
    my($type);
    
    $file_handle = OpenBinaryFileForRead($file_path);
    if (!$file_handle)
    {
        die('open ' . $file_path . ':'. $!);
    }
    $block0 = UnpackBlock0(ReadBlock($file_handle));
    if ($block0->{'signature'} != $block0Signature)
    {
        die('invalid block0 signature 0x' . hex($block0->{'signature'}));
    }
    $buffer = ReadBlock($file_handle);
    $partition_map_entry = UnpackPartitionMapEntry(ReadBlock($file_handle));
    if ($partition_map_entry->{'signature'} != $partitionMapEntrySignature)
    {
        die('invalid partition map entry signature 0x' . hex($partition_map_entry->{'signature'}));
    }
    $partition_map[0] = $partition_map_entry;
    $number_of_partitions = $partition_map_entry->{'number_of_blocks_in_partition_map'};
    for ($i = 1 ; $i < $number_of_partitions - 1; ++$i)
    {
        $partition_map_entry = UnpackPartitionMapEntry(ReadBlock($file_handle));
        if ($partition_map_entry->{'signature'} != $partitionMapEntrySignature)
        {
            die('invalid partition map entry signature 0x' . hex($partition_map_entry->{'signature'}));
        }
        if ($partition_map_entry->{'number_of_blocks_in_partition_map'} != $number_of_partitions)
        {
            die('mismatched number_of_blocks_in_partition_map');
        }
        $partition_map[$i] = $partition_map_entry;
    }
    for $partition_map_entry (@partition_map)
    {
        if ($partition_map_entry->{'first_logical_block_of_data_area'} != 0)
        {
            die('first_logical_block_of_data_area is not zero, I do not know what this means.');
        }
        if ($partition_map_entry->{'number_of_blocks_in_partition'}
                != $partition_map_entry->{'number_of_blocks_in_data_area'})
        {
            die('number_of_blocks_in_partition not equal number_of_blocks_in_data_area, I do not know what this means.');
        }
        $partition_name = $partition_map_entry->{'partition_name'};
        $start = $partition_map_entry->{'first_physical_block_of_partition'}
                + $partition_map_entry->{'first_logical_block_of_data_area'};
        $size = $partition_map_entry->{'number_of_blocks_in_data_area'};
        $type = $partition_map_entry->{'partition_type'};
        my $SizeBytes = ($size * $block_size);
        print("name=$partition_name, type=$type, size=$size blocks, $SizeBytes bytes\n");
        
        #print(Dumper($partition_map_entry));
        $partition_file_handle = OpenBinaryFileForWrite($partition_name);
        if (!$partition_file_handle)
        {
            die('open failed:' . $!);
        }
        
        SeekTo($file_handle, $start * $block_size) || die('seek failed:' . $!);
        my $BlocksRead;
        for ($BlocksRead = 0 ; $BlocksRead != $size ; $BlocksRead += 1)
        {
            if (!ReadFile($file_handle, \$buffer, $block_size))
            {
           		print("read failed:$!\n");
           		last;
           	}
            if (!WriteFile($partition_file_handle, \$buffer, $block_size))
            {
           		print("write failed:$!\n");
           		last;
           	}
        }      
        print("name=$partition_name done\n");
        if ($BlocksRead != $size)
        {
        	printf("read %d out of %d blocks, %d out of %d bytes\n",
        		$BlocksRead, $size, $BlocksRead * $block_size, $SizeBytes);
        }
    }
}

Main($ARGV[0]);
