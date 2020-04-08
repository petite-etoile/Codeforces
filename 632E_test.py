from itertools import permutations

N = 3

def rook(grid):
    res = 0
    dictionary = dict()
    for i in range(N):
        for j,g in enumerate(grid[i]):
            dictionary[g] = (i,j)
    now = dictionary[0]
    visited = set()
    while len(visited) != N*N:
        visited.add(now)
        candidate = []
        for i in range(N):
            if (now[0],i) not in visited:
                candidate.append(grid[now[0]][i])
            if (i,now[1]) not in visited:
                candidate.append(grid[i][now[1]] )
            
        candidate.sort()
        if(candidate):
            now = dictionary[candidate[0]]
        else:
            res += 1
            for i in range(N*N):
                if (dictionary[i] not in visited):
                    now = dictionary[i]
                    break
        visited.add(now)
        
    return res
def queen(grid):
    res = 0
    dictionary = dict()
    for i in range(N):
        for j,g in enumerate(grid[i]):
            dictionary[g] = (i,j)
    now = dictionary[0]
    visited = set()
    while len(visited) != N*N:
        visited.add(now)
        candidate = []
        for i in range(N):
            if (now[0],i) not in visited:
                candidate.append(grid[now[0]][i])
            if (i,now[1]) not in visited:
                candidate.append(grid[i][now[1]])
            if (((now[0]+i), (now[1]+i)) not in visited  and (now[0]+i) < N  and  (now[1]+i) < N ) :
                candidate.append(grid[(now[0]+i)][ (now[1]+i)])
            if (((now[0]-i), (now[1]-i)) not in visited  and (now[0]-i) >= 0  and  (now[1]-i) >= 0 ) :
                candidate.append(grid[(now[0]-i)][ (now[1]-i)])
            if (((now[0]+i), (now[1]-i)) not in visited and now[0]+i<N and now[1]-i>=0):
                candidate.append(grid[(now[0]+i)][ (now[1]-i)])
            if (((now[0]-i), (now[1]+i)) not in visited and now[0]-i>=0 and now[1]+i<N):
                candidate.append(grid[(now[0]-i)][ (now[1]+i)])
        candidate.sort()
        if(candidate):
            now = dictionary[candidate[0]]
        else:
            res += 1
            for i in range(N*N):
                if (dictionary[i] not in visited):
                    now = dictionary[i]
                    break
        visited.add(now)
        
    return res

for it in permutations(range(N*N)):
    *it, = it
    grid = [it[N*i:N*i+N] for i in range(3)]
    cost_rook, cost_queen = rook(grid), queen(grid)
    if(cost_rook < cost_queen):
        print(cost_rook, cost_queen )
        print(*grid,"", sep="\n")
