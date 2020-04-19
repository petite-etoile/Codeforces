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

int64 choose(int64 n,int64 k){
    int64 res = 1;
    REP(i,k){ res *= n-i; }
    REP(i,k){ res /= i+1; }
    return res;
}

// bool is_ok(vector<int>& A){
//     REP(i,A.size()) if(A[i]==i) return false;
//     return true;
// }

// int64 solve(int N){
//     vector<int> A(N);
//     REP(i,N) A[i]=i;
//     int64 res = 0;
//     while(next_permutation(ALL(A))){
//         res += is_ok(A);
//     }
//     return res;
// }
const MAX_K = 4;
vector<int64> fact(MAX_K+1);
void init(){
    fact[0] = 1;
    REP(k,MAX_K) fact[k+1] = fact[k]*(k+1);
}
int64 solve(int64 N){
    int64 res = fact[N];
    REP(i,N){
        
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    int64 ans=0;
    init();
    for(int k=1;k<=K;k++){
        ans += choose(N,k) * solve(k);
    }
    cout << ans+1 << endl;
}