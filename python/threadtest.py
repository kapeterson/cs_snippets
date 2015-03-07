#!/usr/bin/python
import threading
import thread
import time

def thread_function():
	for i in range(0, 10):
		time.sleep(2)
		print("In the thread " + str(thread.get_ident()) + " brah")



print "Going to start threads"

tlist = []

for i in range(0,3):
	tlist.append(threading.Thread(target=thread_function))

for t in tlist:
	t.start()


print "Done"
