/*
　　　∫ ∫ ∫
　　　ノヽ
　　（＿　 ）
　（＿　　　 ）
（＿＿＿＿＿＿ ）
　ヽ(´･ω･)ﾉ　
　　 |　 /
　　 UU
*/
#pragma region macro
#include <bits/stdc++.h>
typedef long long int64;
using namespace std;
using P = pair<int64, int64>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const int64 INF = 1LL << 62;
const int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
#define bn '\n'
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T,typename S>
ostream& operator<<(ostream& os, pair<T,S> const&P){
    os << "(";
    os << P.first;
    os << " , ";
    os << P.second;
    os << ")";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> &S){
    auto it=S.begin();
    while(it!=S.end()){
        os << *it;
        os << " ";
        it++;
    }
    os << "\n";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T> &q){
    for(auto it=q.begin();it<q.end();it++){
        os<<*it;
        os<<" ";
    }
     os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> three = {
        {6,8,9}, {3,2,5}, {1,7,4}
    };

    switch (N){
    case 1:
        cout << -1 << bn;
        break;
    case 2:
        cout << -1 << bn;
        break;
    case 3:
        cout << "9 8 6\n5 2 3\n4 7 1\n";
        break;
    default:
        vector<vector<int>> ans(N,vector<int>(N));
        int now = 0;
        int w;
        REP(h,N){
            REP(j,N){
                if(h&1){ w = N-j-1; }
                else{ w = j; }
                if((N&1) and h+3>=N and w+3>=N) continue;
                if(not (N&1) and h+3>=N and w<3) continue;

                now++;
                ans[h][w] = now;
            }
        }
        if(N&1){
            REP(i,3){
                REP(j,3){
                    int h = N-3+i;
                    int w = N-3+j;
                    ans[h][w] = now + three[i][j];
                }
            }
        }else{
            REP(i,3){
                REP(j,3){
                    int h = N-3+i;
                    int w = j;
                    ans[h][w] = now + three[i][j];
                }
            }
        }
        for(auto a:ans) cout << a;
        break;
    }

}

/*
#testing on 3*3


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

*/