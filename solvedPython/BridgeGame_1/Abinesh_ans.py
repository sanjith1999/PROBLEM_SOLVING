import sys
from math import gcd
sys.setrecursionlimit(1000000)
mod = 10**9+7
tmr = 0
vertices = set()
n, m = [int(x) for x in input().split()]
game_space =[[] for i in range(n+1)]
lw = [float("Inf") for i in range(n+1)]
dc = [float("Inf") for i in range(n+1)]
chld = [0 for i in range(n+1)]
prnt = [-1 for i in range(n+1)]
marked = [False for i in range(n+1)]

for i in range(m):
    u, v = list(map(int,input().split()))
    game_space[u].append(v)
    game_space[v].append(u)
 
def build_bridge_tree(u):
    global tmr
    marked[u] = True
    dc[u] = tmr
    lw[u] = tmr
    chld[u] = 1
    tmr+=1
    for v in game_space[u]:
        if not marked[v]:
            prnt[v] = u
            chld[u] += build_bridge_tree(v)
            lw[u] = min(lw[u], lw[v])
            if lw[v] > dc[u]:
                vertices.add((min(u, v), max(u,v)))
        elif v != prnt[u]:
            lw[u] = min(lw[u], lw[v])
    return chld[u]
 
build_bridge_tree(1)
even_count = 0
length_of_vertices = len(vertices)
if length_of_vertices == 0:
    print(0, 0)
elif n % 2 != 0:
    print(0, 1)
else:
    for (a,b) in vertices:
        num = min(chld[a], chld[b])
        if num & 1 == 0:even_count+=1
    length_of_vertices %= mod
    odd_count = (length_of_vertices-even_count)%mod
    even_count %= mod
    cmn = gcd(length_of_vertices, even_count)
    print((even_count//cmn) * pow(length_of_vertices//cmn, mod-2, mod) % mod, end = ' ')
    cmn = gcd(length_of_vertices, odd_count)
    print((odd_count//cmn) * pow(length_of_vertices//cmn, mod-2, mod) % mod)