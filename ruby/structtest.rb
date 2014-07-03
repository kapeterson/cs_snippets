#!/usr/bin/ruby


puts "Structure Test"

Struct.new("IMPM", :enabled, :bwPolicy)

thisIMPM = Struct::IMPM.new(false, "IOMbPolicy")

puts "IMPM Enabled is " + thisIMPM.enabled.to_s
puts "IMPM BWPolicy is " + thisIMPM.bwPolicy

puts "changing policy to 'default'"

thisIMPM.bwPolicy = "default"
puts "REtrieving changed policy value of " + thisIMPM.bwPolicy
