#! /usr/bin/env perl

use 5.16.1;
use strict;
use warnings;

use Carp;
use autodie;
use Device::SerialPort;

my $port = Device::SerialPort->new("/dev/ttyU0");
$port->baudrate(9600);
$port->databits(8);
$port->parity("none");
$port->stopbits(1);
$port->save('portconfig');
