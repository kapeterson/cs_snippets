#!/usr/bin/ruby
require 'socket'
require_relative 'TestClass'

server = TCPServer.open(2001)
newobj = TestClass.new('Fart')
sobj = Marshal.dump(newobj)

loop {

	client = server.accept
	client.puts(Time.now.ctime)
	client.puts "Closing the connection"
	client.puts sobj
	client.close
}
