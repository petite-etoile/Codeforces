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

class BigCombination{
private:
    const int MAX = 1000'000;
    mint fac[1100000], inv[1100000];
public:
    BigCombination(){
        fac[0] = fac[1] = 1;
        for(int i=2; i<MAX; i++){
            fac[i] = fac[i-1] * i;
        }
        inv[MAX-1] = fac[MAX-1].inv();
        for(int i=MAX-1;i>0;i--){
            inv[i-1] = inv[i] * i;
        }
    }

    mint combination(int n,int r){
        if(n<r) return 0;
        if(n<0 || r<0) return 0;
        if(n==r) return 1;
        return fac[n] * inv[r] * inv[n-r];
    }

    mint factorial(int n){
        return fac[n];
    }

    mint inv_factorial(int n){
        return inv[n];
    }
};

template <typename T>
struct SegmentTree{
    /*
    ~~~~1-indexで実装~~~~
            1
        2       3
      4   5   6    7

    ~~~~親・兄弟・子へのアクセスの仕方~~~~
                i>>1
            i           i^1
    i<<1|0   i<<1|1
    */


    using F = function<T(T,T)>;
    int N;
    F func; //関数(minとか)
    T identity; //単位元
    vector<T> data; //上から添字 2*Nくらいのノード
    SegmentTree(){}
    SegmentTree(F f,T identity):func(f),identity(identity){}

    void init(int n_){
        N=1;
        while(N<n_) N<<=1; //完全二分木がいいので2^k個にする
        data.assign(N<<1, identity); //2N個のノード
    }

    //木を構成(vectorを元に各ノードの値を計算)
    void build(const vector<T>& v){
        int n_ = v.size();
        init(n_);
        for(int i=0; i<n_; i++){
            data[N+i] = v[i]; //葉
        }
        for(int i=N-1; i; i--){
            data[i] = func(data[i<<1], data[(i<<1)+1] ); //子をみて親を更新
        }
    }

    //k番目の値をxに変える
    void set_val(int k, T x){
        k+=N; //indexをセグ木でのindexに変換
        data[k] = x; //値の書き換え(葉)
        while(k>>=1){ //右シフトして0にならない間
            data[k] = func(data[k<<1], data[(k<<1)+1] );
        }
    }

    //https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf
    //閉開区間[left,right)で
    T query(int left,int right){
        T left_val=identity, right_val=identity; 
        for(int l=left+N,r=right+N; l<r; l>>=1,r>>=1){
            if(l&1) left_val = func(left_val, data[l++] );
            if(r&1) right_val = func(data[--r], right_val);
        }
        return func(left_val, right_val);
    }

    //葉の値を取得する
    T get_val(int idx){
        return data[idx+N];
    }
};
template <typename T>
ostream& operator<<(ostream& os, SegmentTree<T> &S){
    int N = S.data.size();
    int cnt = 0;
    int up = 1;
    for(int i=1;i<N;i++){
        if(S.data[i]!=S.identity){
            os << S.data[i];
        }else os << "単";
        os << " ";
        cnt++;
        if (cnt == up){
            os << "\n\n";
            up<<=1;
            cnt=0;
        }else if (cnt%2==0) os<<",";
    }
    os << "\n";
    return os;
};

BigCombination B;
//Sの順列でTより辞書順が速いものの数
mint f(string S, string T){
    size_t N = S.size();

    vector<int> cnt(26);
    for(auto s:S){
        cnt[s-'a']++;
    }

    mint res = 0;
    REP(i,N){
        mint remain_permutaion = B.factorial(N-i-1);
        REP(k,26) remain_permutaion *= B.inv_factorial(cnt[k]);
        REP(k,T[i] - 'a'){
            if(cnt[k]){
                res += remain_permutaion * B.factorial(cnt[k]) * B.inv_factorial(cnt[k]-1);
            }
        }
        cnt[T[i]-'a']--;
        if(cnt[T[i]-'a'] < 0) break;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    string S,T;
    cin >> S >> T;
    auto ans = f(S,T) - f(S,S);
    cout << ans - 1 << bn;
}