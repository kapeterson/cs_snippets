#!/usr/bin/ruby

class TestClass

	def initialize()
		@price = 1
	end
	
	def setPrice(val)
	  @price = val
	end

	def getPrice
		return @price
	end
end

puts "Assigning x = neww"
x = TestClass.new

puts "Assigning y = x"
y = x

puts "VAlue of y is #{y.getPrice()}"

puts "chaning price of x to 10"
x.setPrice(10)

puts "VAlue of y is now #{y.getPrice()}"
