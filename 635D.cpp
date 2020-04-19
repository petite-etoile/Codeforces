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
template <typename T,typename S>
ostream& operator<<(ostream& os, map<T,S> const&M){
    for(auto e:M){
        os<<e;
    }
    os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

int64 f(int64 r,int64 g,int64 b){
    return (r-g)*(r-g)+(b-g)*(b-g)+(r-b)*(r-b);
}

int64 g(vector<int64>& A,vector<int64>& B,vector<int64>& C){
    int64 res = INF;
    for(auto r:A){
        int64 g_left = 0 , g_right =  0;
        auto it_g = lower_bound(ALL(B),r);
        if(it_g!=B.end()) g_right = *it_g;
        if(it_g!=B.begin()) {
            g_left = *--it_g;
        }

        int64 b_left = 0, b_right =  0;
        auto it_b = lower_bound(ALL(C),r);
        if(it_b!=C.end()) b_right = *it_b;
        if(it_b!=C.begin()) {
            b_left = *--it_b;
        }

        //左左
        if(g_left and b_left) chmin(res, f(r,g_left,b_left));
        //右右
        if(g_right and b_right) chmin(res, f(r,g_right,b_right));
        //右左
        if(g_right and b_left) chmin(res, f(r,g_right,b_left));
        //左右
        if(g_left and b_right) chmin(res, f(r,g_left,b_right));
    }
    return res;
}

void solve(){
    int64 ans = INF;
    int Rn,Gn,Bn;
    cin >> Rn >> Gn >> Bn;
    vector<int64> R(Rn),G(Gn),B(Bn);
    REP(i,Rn) cin >> R[i];
    REP(i,Gn) cin >> G[i];
    REP(i,Bn) cin >> B[i];
    sort(ALL(R));
    sort(ALL(G));
    sort(ALL(B));

    chmin(ans, g(R,G,B));
    chmin(ans, g(G,R,B));
    chmin(ans, g(B,G,R));
    cout << ans << bn;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(i,N) solve();

}