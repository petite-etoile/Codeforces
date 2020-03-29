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

void solve(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> edge(N);

    int a,b;
    REP(i,M){
        cin >> a >> b;
        a--;b--;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }

    queue<int> q;
    q.push(0);
    vector<bool> visited(N,false);
    vector<vector<int>> nodes(2);

    int v; 
    REP(i,N){
        queue<int> tmp;
        while(not q.empty()){
            v = q.front(); q.pop();
            if(visited[v]) continue;
            nodes[i&1].emplace_back(v+1);
            visited[v] = true;
            for(auto to:edge[v]){
                if(visited[to]) continue;
                tmp.push(to);
            }
        }
        q = tmp;
    }
    if(nodes[0].size() < nodes[1].size()){
        cout << nodes[0].size() << bn;;
        cout << nodes[0];
    } else {
        cout << nodes[1].size() << bn;;
        cout << nodes[1];
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(i,N) solve();
}