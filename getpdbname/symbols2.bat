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

sub ImageOpenAndRead
{
    my($path) = ($_[0]);
    my(%image);

    $image{'path'} = $path;
    $image{'contents'} = OpenAndReadEntireBinaryFileAsString($path);

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
    $result |= ord(substr($s, $length - $i - 1, 1);
  }
  return $result;
}

sub ImageGetHeaders
{
  my($image) = ($_[0]);
  my(%file_header);
  my(%nt_headers);
  my(%optional_header);
  my(@section_headers);
  my(%section_header);
  my($contents);
  my($path);

  $path = $image{'path'};
  $contents = $image{'contents'};
  if (substr($contents, 0, 2) ne "MZ")
  {
    die('missing MZ header in ' . $path);
  }
  $offset_to_pe = ByteStringToLittleEndianInteger(substr($contents, 60, 4));
  print('offset to PE is ' . $offset_to_pe . $newline); 
}

%image = ImageOpenAndRead($ARGV[0]);
ImageGetHeaders(\%image);
__END__
:endofperl
