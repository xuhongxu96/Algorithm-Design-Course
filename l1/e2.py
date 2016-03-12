class Knight:
    W = 8
    H = 8
    _dir = [(-1, 0), (1, 0), (0, 1), (0, -1)]
    def __init__(self, m, n):
        self.m = m
        self.n = n
        self._succ = False
        self.g = []
    def _go(self, x, y, i):
        if self._succ:
            return
        if i == Knight.W * Knight.H:
            for r in self.g:
                print(r)
            print('--')
            self._succ = True
            return
        for dx, dy in Knight._dir:
            tx = x + dx
            ty = y + dy
            if tx < 0 or ty < 0 or tx >= Knight.W or ty >= Knight.H:
                continue
            if self.g[tx][ty] == 0:
                self.g[tx][ty] = i + 1
                self._go(tx, ty, i + 1)
                self.g[tx][ty] = 0
    def go(self):
        self._succ = False
        self.g = [[0 for x in range(0, Knight.W)] for x in range(0, Knight.H)]
        self.g[m][n] = 1
        self._go(m, n, 1)
    

if __name__ == "__main__":
    m = int(input())
    n = int(input())
    k = Knight(m, n)
    k.go()
    
    

