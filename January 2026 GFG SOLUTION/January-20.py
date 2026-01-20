class Solution:
    def __init__(self):
        self.d = []
        self.r = []
    
    def append(self, x):
        self.d.append(x)
        self.r.clear()
    
    def undo(self):
        if self.d:
            self.r.append(self.d.pop())
    
    def redo(self):
        if self.r:
            self.d.append(self.r.pop())
    
    def read(self):
        return ''.join(self.d)
