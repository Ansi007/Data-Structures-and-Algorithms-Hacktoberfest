
class Node:
    def __init__(self,value):
        self.value=value
        self.next=None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def insert(self,value):
        if self.head==None:
            self.head = Node(value)
            return
        temp = self.head
        while(temp.next!=None):
            temp = temp.next
        temp.next = Node(value)
    
    def delete_at(self,index):
        """
        Follows Zero Based Indexing
        """
        idx = 0
        temp = self.head
        while(temp.next!=None and idx<index-1):
            temp=temp.next
            idx+=1
        if index==0:
            self.head = self.head.next
            return
        if temp.next==None:
            print("Index out of Bound")
            return
        temp.next = temp.next.next

    def insert_at(self,index,value):
        """
        Follows Zero Based Indexing
        """
        idx = 0
        temp = self.head
        while(temp.next!=None and idx<index-1):
            temp=temp.next
            idx+=1
        if index==0:
            add = self.head
            self.head = Node(value)
            self.head.next=add
            return
        if temp.next==None:
            temp.next=Node(value)
            return
        add = temp.next
        temp.next = Node(value)
        temp.next.next = add
    
    def search_by_value(self,value):
        idx = 0
        temp = self.head
        while(temp.next!=None and temp.value!=value):
            idx+=1
            temp=temp.next
        if temp.value==value:
            print(f"Value found at index {idx}")
            return
        print("Value not Found")
    
    def search_by_index(self,index):
        """
        Follows Zero Based Indexing
        """
        idx = 0
        temp = self.head
        while(temp.next!=None and idx!=index):
            temp=temp.next;
            idx+=1
        if idx==index:
            print(f"Value at index {index} is {temp.value}")
            return
        print("Index out of bound")
    
    def print(self):
        temp = self.head
        while(temp.next!=None):
            print(temp.value,"-> ", end="")
            temp=temp.next
        print(temp.value)
    
ll = LinkedList()
ll.insert(5)
ll.insert(4)
ll.insert(3)
ll.search_by_index(0)
ll.print()
    
