import sys
import re

class Node:
    def __init__(self,data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    def printList (self):
        pList = self.head
        while pList is not None:
            print (pList.data, end = '')
            pList = pList.next
    def printListReversed (self): #actually ended up not needing this but I'll leave it here)
        temp = self.head
        reverseList = LinkedList()
        while temp is not None:
            reverseList.push(temp)
            temp = temp.next
        reverseList.printList()

    def push (self, newData):
        newNode = Node(newData)
        newNode.next = self.head
        self.head = newNode
    def addLL(self, first, second):
        temp1 = first
        temp2 = second
        remainder = 0
        while (temp1 is not None or temp2 is not None):
            if temp1 is None: temp1 = Node(0)
            if temp2 is None: temp2 = Node(0)
            sum = temp1.data + temp2.data + remainder
            # The head should be the 1's digit (smallest digit)
            remainder = 1 if sum >= 10 else 0
            if remainder == 1:
                sum = sum - 10
            # if I use push, the head would be the largest digit here. which is fine for outputting. I just need to make a reverse linked list for outputting the other LLs
            self.push (sum)
            # go next value
            if temp1 is not None: temp1 = temp1.next
            if temp2 is not None: temp2 = temp2.next
        if remainder > 0:
            self.push (remainder)

#For the above code, I referenced https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

def main():
    # need to read from an input file 1 line at a time, store the two LLs, add them, then output that line?
    filenameWithInput = sys.argv[-1]
    # I need to parse input=add.txt to just add.txt. Just use filename[1]
    filename = filenameWithInput.split("=")
    f = open(filename[1], "r")
    errorCheck = 0
    # lineTemp[1] and lineTemp[2] should hold the numbers. As a string though. So convert to LL
    for line in f:
        lineTemp = re.split("[,()]", line)
        firstLL = LinkedList()
        secondLL = LinkedList()
        finalLL = LinkedList()
        x = 0
        while  x < len(lineTemp[1]):
            num = int(lineTemp[1][x])
            if num%1 != 0:
                errorCheck = 1
                break
            if x > 40:
                errorCheck = 1
                break
            firstLL.push(num)
            x += 1
        y = 0
        while  y < len(lineTemp[2]):
            num2 = int(lineTemp[2][y])
            if num2%1 != 0:
                errorCheck = 1
                break
            if y > 40:
                errorCheck = 1
                break
            secondLL.push(num2)
            y += 1
# I pushed into the 2 LLs, now i have to add and finish up
        finalLL.addLL(firstLL.head, secondLL.head)
        print ('add(' + lineTemp[1] + ',' + lineTemp[2] + ')=', end = '')
        if errorCheck == 0:
            finalLL.printList()
        else:
            print ("error")
        print('\n', end='')
    f.close()

main()