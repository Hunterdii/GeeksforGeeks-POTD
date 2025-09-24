from collections import deque

class SpecialQueue:
    def __init__(self):
        self.q = deque()
        self.mn = deque()
        self.mx = deque()
    
    def enqueue(self, x):
        self.q.append(x)
        while self.mn and self.mn[-1] > x: self.mn.pop()
        self.mn.append(x)
        while self.mx and self.mx[-1] < x: self.mx.pop()
        self.mx.append(x)
    
    def dequeue(self):
        f = self.q.popleft()
        if f == self.mn[0]: self.mn.popleft()
        if f == self.mx[0]: self.mx.popleft()
    
    def getFront(self): return self.q[0]
    def getMin(self): return self.mn[0]
    def getMax(self): return self.mx[0]
