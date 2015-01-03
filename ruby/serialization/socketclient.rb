#!/usr/bin/ruby
require 'socket'

hostname = 'localhost'
port = '2001'

puts "OK"

s = TCPSocket.open(hostname, port)

while line = s.gets
	puts line.chop

end

s.close
