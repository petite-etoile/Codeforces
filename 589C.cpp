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
vector<int> prime(int n){
    int copy = n;
    vector<int> res;
    for(int i=2;i*i<=copy;i++){
        if (n%i==0) res.push_back(i);
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1) res.push_back(n);
    return res;
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
    int X,n;
    cin >> X >> n;
    vector<int> primes;
    primes = prime(X);
    //debug(primes);
    int ans=1;
    for(auto x:primes){
        vector<int> cnt;
        //debug(x);
        int lo = log(n)/log(x) + 1;
        for(int c=1;c<=lo;c++){
            int a=pow(x,c);
            if( n/a==0) break;
            cnt.push_back(n/a);
        }
        //debug(cnt);
        int before=0;
        REP(i,cnt.size()){
            int j = cnt.size()-i-1;
            int x_i = modpow(x,j+1,MOD);
            //debug(x_i);
            ans *= modpow(x_i, cnt[j]-before,MOD);
            //debug(cnt[j]);
            //debug(before);

            ans %= MOD;
            before=cnt[j];
        }
    }


    cout << ans << endl;
}

//>>> 11**133 * 121**12 * 1331**1 *  647**2
//17564596871039814783221251827055778115121776771721579749021807404140180914046307322114115047405548246686362577715366003810785039672080390850188270175533941082771588523321009