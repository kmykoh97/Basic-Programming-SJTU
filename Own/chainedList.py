class Node:
    def __init__(self,data,nextNode = None,prevNode = None):
        self.data = data
        self.nextNode = nextNode
        self.prevNode = prevNode

    def get_next(self):
        return self.nextNode #get next Node

    def set_next(self,n):   #form connection with next Node
        self.nextNode = n

    def get_prev(self):
        return self.prevNode #get prev Nod

    def set_prev(self,p):   #form connection with previous Node
        self.prevNode = p

    def get_data(self):
        return self.data

class DoubleLinkedList:
    def __init__(self,h = None,t = None,l = None):
        self.head = h
        self.tail = t
        self.size = 0
        self.last_node = l

    def add(self,d):
        new_node = Node(d,self.head)
        if self.head != None:
            self.head.set_prev(new_node)
        self.head = new_node
        self.printData()
        self.size += 1

    def addTail(self,d):
        this_node = self.head
        tail_node = Node(d,self.tail)
        if self.head != None:
            while this_node!= None and this_node.get_next()!= None: #to avoid this node become None
                this_node = this_node.get_next()
            self.last_node = this_node
            tail_node.set_prev(self.last_node)
            self.last_node.set_next(tail_node)
        else:
            self.head = tail_node   #head -> tail_node -> None
        self.printData()
        self.size += 1

    def removeOne(self,d):
        this_node = self.search(d)
        nex = this_node.get_next()
        prev = this_node.get_prev()
        if nex:
            nex.set_prev(prev)
        if prev:
            prev.set_next(nex)
        else:
            self.head = nex
        self.size -= 1

    def removeOneTail(self,d):
        this_node = self.head
        while this_node != None and this_node.get_next()!= None:
            this_node = this_node.get_next()
        self.last_node = this_node  #to get the last_node before Tail

        while self.last_node != None:
            if self.last_node.get_data() == d:
                nex = self.last_node.get_next()
                prev = self.last_node.get_prev()
                if nex:
                    nex.set_prev(prev)
                if prev:
                    prev.set_next(nex)
                else:
                    self.head = nex
                self.size -= 1
                break
            else:
                self.last_node = last_node.get_prev() #access to each node reversely

    def search(self, d):
        this_node = self.head
        while self.head != None:
            if this_node.get_data() == d:
                return this_node
            else:
                this_node = this_node.get_next()


    def get_size(self):
        return self.size

    def empty(self):
        if self.size == 0:
            return True
        else:
            return False

    def printData(self):
        this_node = self.head
        sub = str(this_node.get_data())
        while this_node != None:
            this_node = this_node.get_next()
            if this_node != None:
                sub = sub + "<->"+ str(this_node.get_data())
        print "head" + "<->" + sub + "<->" + "tail"

class Stack:
    def __init__(self):
        self.stack = DoubleLinkedList()

    def empty(self):
        return self.stack.empty()

    def push(self,d):
        self.stack.add(d)

    def pop(self):
        x = self.stack.head.get_data()
        self.stack.removeOne(self.stack.head.get_data())
        return x

    def size(self):
        return self.stack.get_size()

class Queue:
    def __init__(self):
        self.queue = DoubleLinkedList()

    def empty(self):
        return self.queue.empty()

    def enqueue(self,d):
        self.queue.addTail(d)

    def dequeue(self):
        x = self.queue.head.get_data()
        self.queue.removeOne(self.queue.head.get_data())
        return x

    def size(self):
        return self.queue.get_size()

print"Under Class Double Linked List:"
mylist = DoubleLinkedList()
print "head" + "<->" + "tail"
mylist.add(1)
mylist.add(2)
mylist.addTail(2)
mylist.removeOne(2)
mylist.printData()
mylist.removeOneTail(2)
mylist.printData()
print mylist.get_size()
print mylist.empty()
print
print"Under Class Stack:"
s = Stack()
print s.empty()
print s.size()
s.push(1)
s.push(2)
print s.pop()
print s.size()
print s.pop()
print s.size()
print
print"Under Class Queue:"
q = Queue()
print q.empty()
print q.size()
q.enqueue(1)
q.enqueue(2)
print q.dequeue()
print q.size()
print q.dequeue()
print q.size()
