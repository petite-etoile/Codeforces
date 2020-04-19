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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M,K;
    cin >> N >> M >> K;
    vector<string> S(N);
    REP(i,N) cin >> S[i];
    vector<vector<int>> A(N);
    REP(i,N){
        REP(j,M){
            if(S[i][j] == '1') A[i].emplace_back(j);
        }
    }

    vector<vector<int>> DP1(N,vector<int>(K+1,0)); //DP1[i][k]:=i日目にkコマサボったときの最長削減時間
    int ans = 0;
    REP(i,N){
        if(A[i].empty()) continue;
        int origin = A[i].back()-A[i][0]+1;
        ans += origin;
        REP(k,K+1){ 
            if(k) chmax(DP1[i][k],DP1[i][k-1]);
            M = A[i].size();
            if(k>=M) DP1[i][k]=origin;
            REP(l,min(k+1,M)){
                int r = M-1-(k-l);
                if(l>r) break;
                // debug(mp(l,r))
                // debug(mp(A[i][l],A[i][r]))
                chmax(DP1[i][k], origin-(A[i][r]-A[i][l]+1));
            }   
        }
    }

    vector<vector<int>> DP2(N+1,vector<int>(K+1,0)); //DP2[i][k]:=i日目までにkコマサボったときの最長削減時間
    REP(i,N){
        REP(k,K+1){
            chmax(DP2[i+1][k],DP2[i][k]);
            REP(j,k+1){
                chmax(DP2[i+1][k], DP2[i][k-j] + DP1[i][j]);
            }
        }
    }
    // debug(DP1)
    // debug(DP2)
    ans = ans - *max_element(ALL(DP2.back()));
    cout << ans << endl;
}