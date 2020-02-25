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

//約数列挙
vector<int> divs(int n){
    int copy = n;
    vector<int> res;
    for(int i=1;i*i<=copy;i++){
        if(n%i==0){
            res.push_back(i);
            if(i*i!=n) res.push_back(n/i);
        }
    }
    return res;
}
void solve(){
    int A,B,C;
    cin >> A >> B >> C;
    int ans = inf;
    int ans_A,ans_B,ans_C;
    int cand_A,cand_B,cand_C;
    int c1,c2,c_dif;
    for(int b=1;b<=1e4;b++){
        if(C<=b){ 
            cand_C = b;
            c_dif = abs(C-b);    
        }else{
            int c1 = C/b*b;
            int c2 = (C/b+1)*b;

            if(abs(c1-C)<abs(c2-C)) cand_C = c1;
            else cand_C = c2;
            c_dif = min(abs(c1-C),abs(c2-C));
        }

        auto div_B = divs(b);
        int a_dif = inf;
        for(auto a:div_B){
            if(chmin(a_dif, abs(a-A))) cand_A=a;
        }
        int res = c_dif+a_dif+abs(B-b);
        if(chmin(ans, res)) ans_A=cand_A, ans_B = b, ans_C = cand_C;
    }
    cout << ans << bn << ans_A << " " << ans_B << " " << ans_C << bn;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(i,N) solve();
}