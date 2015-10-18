x = 0
y = 0
z = 1


print "x^y = " + str( x ^ y)
print "x^z = " + str(x ^ z ) 


key =   "aabbcc"
ctext = "tester"
cipher = ""

for i in range(len(ctext)):
	print ctext[i]
	cipher += chr(ord(ctext[i]) ^ ord(key[i]))


print "Cipher is ->" + cipher + "<-"



ct = ""
for i in range(len(ctext)):
	ct += chr(ord(cipher[i]) ^ ord(key[i]))




print "Decrypt is " + ct
