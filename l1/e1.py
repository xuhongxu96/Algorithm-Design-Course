def permutation(l):
    n = len(l)
    yield l
    indices = list(range(0, n))
    while True:
        for i in reversed(range(0, n - 1)):
            if indices[i] < indices[i + 1]:
                for j in reversed(range(0, n)):
                    if indices[j] > indices[i]:
                        indices[i], indices[j] = indices[j], indices[i]
                        indices[i+1:] = reversed(indices[i+1:])
                        yield [l[i] for i in indices]
                        break
                break
        else:
            break


if __name__ == "__main__":
    n = int(input())
    graph = []
    for i in range(0, n):
        row = input()
        graph.append(row.split(" "))
    min_distance = -1
    route = []
    for p in permutation(range(0, n)):
        d = 0
        for x, y in zip(p[:-1], p[1:]):
            d += int(graph[x][y])
        if min_distance == -1 or min_distance > d:
            min_distance = d
            route = p
    print(min_distance, route)

