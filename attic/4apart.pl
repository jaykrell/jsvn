#!/usr/bin/perl

use IO::Handle;
use FCntl;

$newline = "\n";

$block0Signature = unpack('n', 'ER');
$partitionMapSignature = unpack('n', 'PM');

sub OpenBinaryFileReadOnly
{
	my($file_handle);
	my($file_path) = ($_[0]);
	
	$file_handle = IO::Handle->new();
	sysopen($file_handle, $file_path, O_RDONLY | O_BINARY) || return undef;
	
	return $file_handle;
}

sub SeekTo
{
    my($file_handle, $offset) = ($_[0], $_[1]);

    return seek($file_handle, $offset, 0);
}

sub SeekForward
{
    my($file_handle, $offset) = ($_[0], $_[1]);

    return seek($file_handle, $offset, 1);
}

sub SeekBackward
{
    my($file_handle, $offset) = ($_[0], $_[1]);

    return seek($file_handle, $offset, 2);
}

sub ReadFile
{
    my($file_handle, $buffer, $number_of_bytes_to_read) = ($_[0], $_[1], $_[2]);
    my($result);

    $result = read($file_handle, $$buffer, $number_of_bytes_to_read);

    return $result;
}

sub GetFileSize
{
    my($file_handle) = ($_[0]);

    return -s $file_handle;
}

sub NewHashRef { my(%x); return \%x; }

sub ReadBlock
{
    my($file_handle) = ($_[0]);
    my($buffer);
	
    ReadFile($file_handle, \$buffer, 512);	
	return $buffer;
}

sub UnpackPartitionMapEntry
{
#
# comments lost due to file system corruption..
#
#	pmBootSize: 		LongInt;	{size of boot code, in bytes}
#	pmBootAddr: 		LongInt;	{boot code load address}
#	pmBootAddr2: 		LongInt;	{reserved}
#	pmBootEntry: 		LongInt;	{boot code entry point}
#	pmBootEntry2: 		LongInt;	{reserved}
#	pmBootCksum: 		LongInt;	{boot code checksum}
#	pmProcessor:		PACKED ARRAY [0..15] OF Char; {processor type}
#	pmPad:				ARRAY [0..187] OF Integer; {reserved}}
# END;
    my($buffer) = ($_[0]);
    my($skip);
    my($x);
    (    
        $x->{'signature'},
		$skip,
		$x->{'number_of_blocks_in_partition_map'},
		$x->{'first_phyical_block_of_partition'},
		$x->{'number_of_blocks_in_partition'},
		$x->{'partition_name'},
		$x->{'partition_type'},
		$x->{'first_logical_block_of_data_area'},
		$x->{'number_of_blocks_in_data_area'},
		$x->{'status'},
		$x->{'first_logical_block_of_boot_code'},
		$x->{'size_of_boot_code_in_bytes'},
		$x->{'boot_code_load_address'},
		$skip,
		$x->{'boot_code_entry_point'},
		$skip,
		$x->{'boot_code_checksum'},
		$x->{'processor_type'}
    ) = unpack('nnNNNa31a31NNNNNNNNNNa31', $buffer);
	return $x;
}

sub UnpackBlock0
{
# TYPE Block0 = 
# PACKED RECORD
#	sbSig: 					Integer;				{device signature}
#	sbBlkSize: 				Integer;				{block size of the device}
#	sbBlkCount: 			LongInt;				{number of blocks on the device}
#	sbDevType: 				Integer;				{reserved}
#	sbDevId: 				Integer;				{reserved}
#	sbData: 				LongInt;				{reserved}
#	sbDrvrCount:			Integer;				{number of driver descriptor entries}
#	ddBlock: 				LongInt; 				{first driverÕs starting block}
#	ddSize: 				Integer; 				{size of the driver, in 512-byte blocks}
#	ddType: 				Integer; 				{operating system type (MacOS = 1)}
#	ddPad:					ARRAY [0..242] OF Integer; {additional drivers, if any}
# END;
#
# We do not read in the array of drivers.
#
    my($buffer) = ($_[0]);
    my($skip);
    my($x);
	$x = NewHashRef();
    (    
        $x->{'signature'},
        $x->{'block_size'},
        $x->{'block_count'},
		$skip,
		$skip,
		$skip,
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
	my($partition_map);
	
	$file_handle = OpenBinaryFileReadOnly($file_path);
	if (!$file_handle)
	{
		die('open ' . $file_path . ':'. $!);
	}
	$block0 = UnpackBlock0(ReadBlock($file_handle));
	$Data::Dumper($block0);
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
	print('ok');
}

Main($ARGV[0]);
