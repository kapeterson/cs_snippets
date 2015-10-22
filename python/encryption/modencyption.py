import math

m = 2

n = 33
pu = 7
pr = 3

cipher = (m ** pu ) % n

print "Cipher is " + str(cipher)

message = ( cipher ** pr ) % n

print "Decrypt is " + str(message)
