from ZODB import FileStorage, DB
import transaction, BTrees.OOBTree
import testclass


storage = FileStorage.FileStorage("odb.fs")

db = DB(storage)

conn = db.open()

root = conn.root()

root.classes = BTrees.OOBTree.BTree()

root.classes['01']=testclass.TestClass()
root.classes['02'] = testclass.TestClass()
root.classes['01'].setColor('gold')
root.classes['01'].addItem("test")
root.classes['01'].addItem("test2")


transaction.commit()

db.close()
conn.close()
storage.close()

print "we good"

