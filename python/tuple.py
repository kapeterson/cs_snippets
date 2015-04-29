
tup1 = ("10.10.10.1", 80)

print "The tuple is :" 
print tup1
print "\r\n"


tt = ("10.10.10.1", 80)

if set(tt) == set(tup1):
	print "They are equal"


flowlist = []
flowlist.append(tup1)


if tt in flowlist:
	print "We good"


print "\r\n"
