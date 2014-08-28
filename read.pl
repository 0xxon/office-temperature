#! /usr/bin/env perl

use 5.16.1;
use strict;
use warnings;

use Carp;
use autodie;
use Device::SerialPort;

my $port = tie(*FH, 'Device::SerialPort', 'portconfig') || die ("cannot set up serial port");
START:
while ( my $line = <FH> ) {
	chomp($line);
	say($line);
	if ( $line =~ m#^Temp: (\d+\.\d+)# ) {
		burp("temp", "$1C at ".localtime."\n");
	}
}
sleep(1);
goto START;

sub burp {
	my $fn = shift;
	open (my $fh, ">", $fn);
	print $fh @_;
	close($fh);
}
