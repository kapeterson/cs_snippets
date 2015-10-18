import argparse
parser = argparse.ArgumentParser(description='Encrypt/Decrypt example.')
parser.add_argument('--text', "-t", required=True, help='text to enctyp')
args = parser.parse_args()

print "text is " + args.text

x = 0
y = 0
z = 1


print "x^y = " + str( x ^ y)
print "x^z = " + str(x ^ z ) 


key =   "aabbcc"
ctext = args.text
cipher = ""

for i in range(len(ctext)):
	#print ctext[i]
	cipher += chr(ord(ctext[i]) ^ ord(key[i % len(key)]))


print "Cipher is ->" + cipher + "<-"



ct = ""
for i in range(len(ctext)):
	ct += chr(ord(cipher[i]) ^ ord(key[i % len(key)]))




print "Decrypt is " + ct
