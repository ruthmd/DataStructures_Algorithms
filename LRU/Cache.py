from collections import deque
class LRU:
    def __init__(self, capacity):
        self.Q = deque(maxlen=capacity)

    def put(self, key):
        if key in self.Q:
            # if key exists push to the top
            self.Q.remove(key)
        self.Q.appendleft(key)

    def get(self, key):
        if key not in self.Q:
            return False
        # move recetly used key to the top
        self.Q.remove(key)
        self.Q.appendleft(key)
        return True

    def refer(self, key):
        if not self.get(key):
            self.put(key)

    def display(self):
        print(self.Q)

if __name__ == "__main__":
    cache = LRU(5)
    cache.refer(1)
    cache.refer(11)
    cache.refer(14)
    cache.refer(1)
    cache.refer(18)
    cache.refer(17)
    cache.refer(15)
    cache.refer(14)
    cache.refer(13)
    cache.display()