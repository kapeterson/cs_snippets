#!/usr/bin/ruby
require_relative 'TestClass'

puts "OK\n"
dSobj = Marshal.load(File.read('serializedobject.obj'))

puts "The name of the objecdt is #{dSobj.getName()}"

