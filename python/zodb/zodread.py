from ZODB import FileStorage, DB
import testclass

storage = FileStorage.FileStorage("odb.fs")

db = DB(storage)

conn = db.open()

root = conn.root()

for key in root.classes.keys():
	print "KEY : " + key
	if type(root.classes[key]) is testclass.TestClass:
		print "     Color: " + root.classes[key].getColor()
		print "     Size : " + str(root.classes[key].getSize())
		print "     ITEMS: "
		for item in root.classes[key].getItems():
			print "          " + item
	else:
		print "ERROR: Not a testclass"

