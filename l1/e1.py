import itertools;
n = int(input())
graph = []
for i in range(0, n):
    row = input()
    graph.append(row.split(" "))
min_distance = -1
route = []
for p in itertools.permutations(range(0, n)):
    d = 0
    for x, y in zip(p[:-1], p[1:]):
        d += int(graph[x][y])
    if min_distance == -1 or min_distance > d:
        min_distance = d
        route = p
print(min_distance, list(route))
