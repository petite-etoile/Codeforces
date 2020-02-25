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
ostream& operator<<(ostream& os, vector<T> &V){
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
    os << P.first;
    os << " ";
    os << P.second;
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
    int N; cin >> N;
    string S; cin >> S;
    map<pair<int,int>, int> cordinate_memo;
    cordinate_memo[mp(0,0)] = 0;
    int x = 0, y = 0;
    int dx,dy;
    int ans = inf;
    pair<int,int> res;
    REP(i,N){
        if(S[i]=='L'){
            dx = -1;
            dy = 0;
        }else if(S[i]=='R'){
            dx = 1;
            dy = 0;
        }else if(S[i]=='D'){
            dx = 0;
            dy = -1;
        }else if(S[i]=='U'){
            dx = 0;
            dy = 1;
        }else{
            debug("ERROR");
            return;
        }
        x += dx;
        y += dy;
        auto xy = mp(x,y);
        if(cordinate_memo.count(xy)){
            if(chmin(ans, i+1-cordinate_memo[xy])) res = mp(cordinate_memo[xy]+1,i+1);
        }
        cordinate_memo[xy] = i+1;
        
    }
    if(ans<inf){
        cout << res << bn;
    }else cout << -1 << bn;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(i,N)solve();
}