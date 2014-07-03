#!/usr/bin/ruby
require 'rubygems'
require 'xlsx_writer'
doc = XlsxWriter.new

doc.quiet_booleans!

sheet1 = doc.add_sheet("People")
sheet1.freeze_top_left = 'A2'
shee1.add_row(["Test", "Test2"])

puts "OK"
