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
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> &P){
os << P.first;
os << " ";
os << P.second;
return os;
}
long long modpow(long long a, long long n, long long MOD) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    cin >> H >> W;
    vector<int> R(H),C(W);
    REP(i,H) cin >> R[i];
    REP(j,W) cin >> C[j];
    
    REP(h,H){
        REP(w,W){
            bool b1 = (w==R[h])&&(h<=C[w]-1);
            bool b2 = (h==C[w])&&(w<=R[h]-1);
            if( b1 || b2){
                cout << 0 << endl;
                exit(0);
            }
        }
    }


    int ans=0;
    int cnt = 0;
    REP(h,H){
        REP(w,W){
            if(h>C[w]&&w>R[h]){
                cnt++;
            }
        }
    }
    ans = modpow(2,cnt,MOD);

    cout << ans << endl;
}