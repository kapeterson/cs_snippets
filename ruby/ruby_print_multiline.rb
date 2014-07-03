#!/usr/bin/ruby


puts "test"

puts '
# Note: BBNMS will pre-provisioning the required subscriber SAPs for this Grp-Inf.
#---------------------------------
#
# Note: Copy and repeat the following Group Interface configuration for each access node.
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" create icmp no mask-reply
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" description "$VRAD_ID_00n$-LAG-$nnn$-$VRAD00n_MGMT_IP$"
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" icmp redirects 10 60
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" icmp unreachables 10 60
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" icmp ttl-expired 500 1
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" ipv6 router-advertisements managed-configuration
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" ipv6 router-advertisements no shutdown
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" ipv6 dhcp6 proxy-server renew-timer days 7
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" ipv6 dhcp6 proxy-server rebind-timer days 10
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" ipv6 dhcp6 proxy-server valid-lifetime days 14
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" ipv6 dhcp6 proxy-server preferred-lifetime days 14
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" ipv6 dhcp6 proxy-server no shutdown
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" arp-populate
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" dhcp proxy-server lease-time min 5
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" dhcp proxy-server no shutdown
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" dhcp no option
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" dhcp trusted
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" dhcp lease-populate 1
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" dhcp no shutdown
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" authentication-policy "radius1"
configure service ies $IES_ID_95x$ subscriber-interface "$NODES_LSW0x_NODESYSTEMID$" group-interface "$VRAD_ID_nnn$" no shutdown
#
#---------------------------------
# Note: BBNMS will pre-provisioning the required subscriber SAPs for this Grp-Inf.
#---------------------------------
#
exit all

#--------------------------------------------------
echo "Port Configuration - adding RoutedScheduler"
#--------------------------------------------------
# Hairpin Ports
configure port 1/2/3 ethernet egress-scheduler-policy "RoutedSched30"
configure port 1/2/4 ethernet egress-scheduler-policy "RoutedSched30"
configure port 2/2/3 ethernet egress-scheduler-policy "RoutedSched30"
configure port 2/2/3 ethernet egress-scheduler-policy "RoutedSched30"
#
# Note: The RoutedSched10 is default profile for all access ports
# Note: Comment configuration for any unequipped MDAs.
# Note: Comment configuration for IPDSLAM, 7342-GPON ports which should use RoutedSched20.
configure port 3/1/1 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/2 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/3 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/4 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/5 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/6 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/7 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/8 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/9 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/1/10 ethernet egress-scheduler-policy "RoutedSched10"
#
configure port 3/2/1 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/2 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/3 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/4 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/5 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/6 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/7 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/8 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/9 ethernet egress-scheduler-policy "RoutedSched10"
configure port 3/2/10 ethernet egress-scheduler-policy "RoutedSched10"
#
configure port 4/1/1 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/2 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/3 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/4 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/5 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/6 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/7 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/8 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/9 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/1/10 ethernet egress-scheduler-policy "RoutedSched10"
#
configure port 4/2/1 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/2 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/3 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/4 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/5 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/6 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/7 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/8 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/9 ethernet egress-scheduler-policy "RoutedSched10"
configure port 4/2/10 ethernet egress-scheduler-policy "RoutedSched10"
#
configure port 5/1/1 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/2 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/3 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/4 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/5 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/6 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/7 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/8 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/9 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/1/10 ethernet egress-scheduler-policy "RoutedSched10"
#
configure port 5/2/1 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/2 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/3 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/4 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/5 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/6 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/7 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/8 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/9 ethernet egress-scheduler-policy "RoutedSched10"
configure port 5/2/10 ethernet egress-scheduler-policy "RoutedSched10"
#
#
# Note: Uncomment the following configuration for only IPDSLAM,7342-GPON ports that require RoutedSched20.
# configure port 3/1/1 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/2 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/3 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/4 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/5 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/6 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/7 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/8 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/9 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/1/10 ethernet egress-scheduler-policy "RoutedSched20"
#
# configure port 3/2/1 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/2 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/3 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/4 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/5 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/6 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/7 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/8 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/9 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 3/2/10 ethernet egress-scheduler-policy "RoutedSched20"
#
# configure port 4/1/1 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/2 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/3 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/4 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/5 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/6 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/7 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/8 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/9 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/1/10 ethernet egress-scheduler-policy "RoutedSched20"
#
# configure port 4/2/1 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/2 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/3 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/4 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/5 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/6 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/7 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/8 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/9 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 4/2/10 ethernet egress-scheduler-policy "RoutedSched20"
#
# configure port 5/1/1 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/2 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/3 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/4 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/5 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/6 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/7 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/8 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/9 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/1/10 ethernet egress-scheduler-policy "RoutedSched20"
#
# configure port 5/2/1 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/2 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/3 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/4 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/5 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/6 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/7 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/8 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/9 ethernet egress-scheduler-policy "RoutedSched20"
# configure port 5/2/10 ethernet egress-scheduler-policy "RoutedSched20"
'

