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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int64 N;
    cin >> N;
    vector<int64> A(N);
    REP(i,N) cin >> A[i];
    map<int64,int64> last;
    vector<int64> cumsum(N,0);
    REP(i,N){
        if(i) cumsum[i] = cumsum[i-1];
        cumsum[i] += A[i];
        last[cumsum[i]]=-2;
    }
    last[0] = 0;
    int64 ans=N*(N+1)/2;
    int64 last_left=-1;
    REP(i,N){
        // ans -= cnt[cumsum[i+1]];
        // cerr << bn;
        // debug(mp(cumsum[i],last[cumsum[i]]))
        if(last[cumsum[i]] != -2){
            if(last[cumsum[i]]-last_left >= 0){
                ans -= (last[cumsum[i]]-last_left) * (N-i);
                // debug(mp(last_left,last[cumsum[i]]))
                // debug(((last[cumsum[i]]-last_left) * (N-i)))
                // debug(ans)
                last_left = last[cumsum[i]];
            }
        }
        last[cumsum[i]] = i+1;
        // debug(N-i)
        // debug(cumsum[i+1])
        // cnt[cumsum[i+1]]++;
    }
    cout << ans << endl;
}