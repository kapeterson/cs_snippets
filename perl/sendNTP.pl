#!/usr/bin/perl --
# AUTHOR k109p@att.com
# Author: kp109p@att.com
# WARNING:  DO not execute the script in production without testing properly in a lab environment.

use IO::Socket;
use strict;

my $ip1 = $ARGV[0];

if ( !defined $ip1) {
        print "Format: ./sendNTP.pl <ip> \n";
        print "sends a packet to ip|\n";
        exit 1;
}

my $sock = IO::Socket::INET->new(
    Proto    => 'udp',
    PeerPort => 123,
    PeerAddr => $ip1,
) or die "Could not create socket: $!\n";

my $s = pack('H*', "1700032a0000");
$sock->send($s) or die "Send error: $!\n";
print "sent to $ip1\n";