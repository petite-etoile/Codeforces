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


//エラトステネスの篩
vector<int> Eratosthenes(int n){
    vector<int> Eratos(n+1,-1);
    for(int i=2;i*i<=n;i++){
        if(Eratos[i]!=-1) continue;
        for(int j=2*i;j<=n;j+=i){
            if(Eratos[j]!=-1) continue;
            Eratos[j]=i;
        }
    }
    return Eratos;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int64 max_A = 2750131;
    
    auto Eratos = Eratosthenes(max_A);
    vector<int> B(2*N);
    vector<int> prime,not_prime,prime_seq;
    for(int i=2;i<=max_A;i++){
        if(Eratos[i]==-1) prime_seq.emplace_back(i);
    }

    REP(i,2*N){
        cin >> B[i];
        if(Eratos[B[i]] == -1) prime.emplace_back(B[i]);
        else not_prime.emplace_back(B[i]);
    } 

    sort(ALL(prime));
    sort(ALL(not_prime), greater<int>());

    vector<int> ans;
    vector<int> del(max_A+1,0);
    for(auto x:not_prime){
        if(del[x]){
            del[x]--;
            continue;
        }
        ans.emplace_back(x);
        del[x/Eratos[x]]++;
    }
    for(auto x:prime){
        if(del[x]){
            del[x]--;
            continue;
        }
        ans.emplace_back(x);
        del[prime_seq[x-1]]++;
    }


    cout << ans;
}