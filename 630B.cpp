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

//素因数分解
vector<int64> prime_factorization(int64 n){
    int64 copy = n;
    vector<int64> res;
    for(int64 i=2;i*i<=copy;i++){
        if(n%i==0){
            res.push_back(i);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1) res.push_back(n);
    return res;
}

string bin(int n){
    string s = "";
    while(n>0){
        string b = to_string(n%2);
        s = b+s;
        n>>=1;
    }
    return s;
}

vector<int> primes;
void solve(){
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    int M = primes.size();
    vector<int> ans(N);
    int mask = (1 << min(11,M)) - 1;
    while(mask < 1 << M){
        // debug(mask)
        // debug(bin(mask));
        ans.assign(N,-1);
        REP(i,N){
            int a = A[i];
            REP(j,M){
                if(mask >> j & 1){
                    // debug(mp(a,primes[j]))
                    if(a%primes[j] == 0){
                        ans[i] = j;
                        break;
                    }
                }
            }
        }
        bool ok = true;
        for(auto a:ans)
            if(a==-1){
                ok = false;
            }
        // debug(mp(ans,ok))
        if(ok){
            set<int> S;
            for(auto a:ans){
                S.insert(a);
            }
            vector<int> idx_dict(M,0);
            int idx = 0;
            for(auto it=S.begin(); it!=S.end(); it++){
                idx_dict[*it] = ++idx;
            }
            cout << S.size() << bn;
            for(auto& a:ans){
                a = idx_dict[a];
            }
            cout << ans;
            
            return;
        }

        int x = mask&-mask;
        int y = mask + x;
        mask = ((mask & ~y) / x >> 1) | y;
    }

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i=2;i*i<=1000;i++){
        if(prime_factorization(i).size() == 1){
            primes.push_back(i);
        }
    }
    debug(primes);

    int N;
    cin >> N;
    REP(i,N) solve();

}