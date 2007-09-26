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

$newline = "\n";

sub StringIndex
{
    return substr($_[0],$_[1],1);
}

sub ImageOpenAndRead
{
    my($path) = ($_[0]);
    my(%image);
    local(*file_handle); # my does not work for file handles
    my($contents);

    sysopen(file_handle, $path, O_RDONLY | O_BINARY) or die('error opening ' . $path . ': ' . $!);

    $image{'path'} = $path;
    $contents = <file_handle>;

    $image{'file_contents'} = $contents;

    return \%image;
}

$image = ImageOpenAndRead($ARGV[0]);
$contents = $$image{'file_contents'};
print(StringIndex($contents,1));

__END__
:endofperl
