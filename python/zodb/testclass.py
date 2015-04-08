import persistent

class TestClass(persistent.Persistent):
	
	def __init__(self):
		self.size = 0
		self.color = 'red'
		self.itemlist = []

	def addItem(self, item):
		self.itemlist.append(item)

	def getItems(self):
		return self.itemlist

	def getSize(self):
		return self.size
	
	def getColor(self):
		return self.color

	def setColor(self, col):
		self.color = col
