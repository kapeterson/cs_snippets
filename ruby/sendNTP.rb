#!/usr/bin/ruby

require 'socket'


mysock = UDPSocket.new
#mysock.bind(nil, 45444)
dat = [0x17, 0x00, 0x03, 0x2a, 0x00, 0x00]
186.times do
	dat.push(0x00)
end
mysock.send(dat.pack('C*'), 0, '10.10.10.1', 123)
mysock.close
puts "byebye spnm"

