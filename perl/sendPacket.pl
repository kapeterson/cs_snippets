#!/usr/bin/perl --
# AUTHOR k109p@att.com
# Author: kp109p@att.com
# WARNING:  DO not execute the script in production without testing properly in a lab environment.
#
# Requirements:
# DESCRIPTION: This script is just a simple Wireshark script to demonstrate parsing
# through a .pcap file.  It will print ou tthe packet nujmber, timestamp, ip and TCP SEQ and ACK
# No function other than printing that information
# Sample USage: pcapParser.pl capture.pcap
use strict;
require Net::Pcap;
use Net::PcapUtils;
use NetPacket::Ethernet qw(:strip);
use NetPacket::IP;
use NetPacket::UDP;
use NetPacket::TCP;
# use Net::Packet;
use Net::Packet::IPv4;

my $file = $ARGV[0];

if ( !defined $file) {
        print "Format: sendPacket.pl  \n";
        print "sends a packet|\n";
        exit 1;
}


# Build IPv4 header
my $ip = Net::Packet::IPv4->new(dst => '192.168.0.1');

# Build TCP header
   my $tcp = Net::Packet::TCP->new(dst => 22);

# Assamble frame, it will also open a Net::Packet::DescL3 descriptor
# and a Net::Packet::Dump object
my $frame = Net::Packet::Frame->new(l3 => $ip, l4 => $tcp);

$frame->send;