__author__ = 'pete'

def merge(l1, l2):

    i = 0
    j = 0
    thisList = []
    while i < (len(l1)) and j < len(l2):

       if l1[i] <= l2[j]:
           thisList.append(l1[i])
           i += 1
       else:
           thisList.append(l2[j])
           j += 1

    if i < ( len(l1)):
        thisList = thisList + l1[i:]
    else:
        thisList = thisList + l2[j:]

    return thisList

def sortList(listObject):

    if len(listObject) == 0:
        return listObject
    elif len(listObject) == 1:
        return listObject
    else:
        tlist1, tlist2 = splitList(listObject)
        t1 = sortList(tlist1)
        t2 = sortList(tlist2)
        return merge(t1, t2)

def splitList(listObject):
    midpoint = int(len(listObject) / 2)
    list1 = listObject[:midpoint]
    list2 = listObject[midpoint:]
    return list1, list2



list1 =  [ 12, 3, 2, 2, 15, 3, 5, 1, 6, 7, 8, 9]
testlist = [4, 2, 5, 2, 1]
#list2 =  [ 1, 2, 3, 4, 5]

# list3 = merge(list1, list2)
#print(list3)

l1, l2 = splitList(testlist)

tlist = sortList(l1)
tlist2 = sortList(l2)
fullSorted = merge(tlist, tlist2)
print(fullSorted)
#print(l2)


