def dfs_traversal(visited, GRAPH, vertices):
    if(vertices not in visited):
        our_set.add(vertices)
        visited.add(vertices)
        for neighbour in GRAPH[vertices]:
            dfs_traversal(visited, GRAPH, neighbour)


inp_n = int(input())
visited = set()
our_set = set()
GRAPH = {}
for iterator in range(1, inp_n+1):
    temp_list = list(map(int, input().split()))
    if(temp_list[0] not in GRAPH):
        GRAPH[temp_list[0]] = []
    GRAPH[temp_list[0]].append(temp_list[1])

inp_n = int(input())
y = list(map(int, input().split()))
for source in y:
    dfs_traversal(visited, GRAPH, source)
print(len(our_set))
