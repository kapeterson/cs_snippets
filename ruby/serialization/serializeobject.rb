#!/usr/bin/ruby
require 'rubygems'
require_relative('TestClass')

puts "OK\n";
newclass = TestClass.new("donkey")
puts "The name is #{newclass.getName()}"

str = Marshal.dump("thing")

#sObj = Marshal.dump(newclass)
f = File.open('serializedobject.obj','w')
f.write(Marshal.dump(newclass))
#puts sObj

#dSobj = Marshal.load(sObj)

#puts "The updated object has name #{dSobj.getName()}"
#puts "\n\n\n"
