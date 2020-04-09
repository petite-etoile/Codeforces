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

struct Eratosthenes{
    int N;
    vector<int> data;
    Eratosthenes(int N):N(N){
        data.assign(N+1,-1);
        for(int64 i=2;i*i<=N;i++){
            if(data[i]!=-1) continue;
            for (int j=i; j<=N; j+=i){
                data[j] = i;
            }
        }
    }

    map<int,int> prime_factorization(int X){
        map<int,int> pri;
        while (data[X]!=-1){
            int prime = data[X];
            pri[prime] += 1;
            X /= prime;
        }
        if(X!=1) pri[X] += 1;

        return pri;
    }

    bool is_prime(int n){
        return (n >= 2) and (data[n] == n or data[n] == -1);
    }

    int get_largest_prime_factor(int n){
        auto tmp = prime_factorization(n);
        int res = 0;
        for(auto& e:tmp) if(res < e.first) res = e.first;
        return res;
    }

    int get_smallest_prime_factor(int n){
        auto tmp = prime_factorization(n);
        int res = n;
        for(auto& e:tmp) if(res > e.first) res = e.first;
        return res;
    }

};

int64 pow(int a,int b,int mod){
    vector<bool> bit;
    for(b=b;b>0;b>>=1){
        bit.push_back(b&1);
    }
    vector<int64> fac(bit.size()); fac[0] = a;
    int64 res = 1;
    for(int i=1;i<bit.size();i++){
        fac[i] = (fac[i-1] * fac[i-1])%mod;
    }
    for(int i=0;i<bit.size();i++){
        if(bit[i]) res*=fac[i];
        res%=mod;
    }
    return res;
}


//mint
struct mint {
    int64 x;
    mint(int64 x=0):x((x+2*MOD)%MOD){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(int64 t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};
ostream& operator<<(ostream& os, mint a){
    os << a.x;
    return os;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    vector<int> cnt(71);
    for(auto a:A) cnt[a]++;
    vector<int> prime_factors;
    Eratosthenes E(70);
    REP(i,70){
        if(E.is_prime(i)) prime_factors.emplace_back(i);
    }
    size_t P_size = prime_factors.size();

    vector<int> factor_bit(71);
    for(int a=1;a<71;a++){
        if(not cnt[a]) continue;
        REP(j,P_size){
            int b = a;
            while(b%prime_factors[j] == 0){
                factor_bit[a] ^= (1 << j);
                b /= prime_factors[j];
            }
        }
    }   

    vector<vector<mint>> DP(2,vector<mint>(1<<P_size, 0));
    DP[1][0] = 1;
    REP(a,71){
        int c = cnt[a];
        if(not c) continue;
        DP[0] = DP[1];
        DP[1].assign(1<<P_size,0);
        mint power = mint(2).pow(c-1);
        REP(mask, 1<<P_size){
            DP[1][mask] += DP[0][mask] * power; //偶数個
            DP[1][mask ^ factor_bit[a]] += DP[0][mask] * power;
        }
    } 
    mint ans=DP[1][0] - 1;

    cout << ans << endl;
}