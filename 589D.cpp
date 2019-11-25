#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
template <typename T>
ostream& operator<<(ostream& os, vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
bool visit(vector<int> &group, vector<vector<int>>& edge,int group_id,int start){
    int now = start;
    debug(edge[now]);
    for(auto to:edge[now]){
        if (group[to]==group_id-2) continue;
        group[to]=group_id;
    }
    debug(group);
    return true;
}
bool check(vector<int> group,vector<vector<int>> edge){
    int n=edge.size();
    REP(a,n){
        for(auto b:edge[a]){
            if(group[a]==group[b]){return false;}
        }
    }
    return true;
}
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<vector<int>> edge(N);
    REP(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> group(N,1);
    int j=0;
    visit(group,edge,2,j);//0から到達可能を2にする
    while(group[j]==1) {j++; if(j==N){cout<<-1<<endl;exit(0);}} //0から到達可能だった点をjにする
    visit(group,edge,3,j);

    int ans=0;
    if (check(group,edge)) cout << group;
    else cout << -1 << endl;


}