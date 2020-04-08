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
ostream& operator<<(ostream& os, queue<T> q){
    while(q.size()){
        os << q.front() + 1; q.pop();
        if(q.size()) os << " " ;
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
    int64 N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    int max_operation = 0;

    vector<queue<int>> ans;
    while(true){
        queue<int> tmp;
        REP(i,N-1){
            if(S.substr(i,2) == "RL"){
                max_operation++;
                tmp.push(i);
                S[i] = 'L';
                S[++i] = 'R';
            }
        }   
        if(tmp.empty()) break;
        ans.emplace_back(tmp);
    }
    // debug(ans)
    // debug("A")
    // debug(mp(ans.size(), max_operation))
    if(ans.size() > K or max_operation < K){
        cout << -1 << bn;
        return 0;
    }else{
        int margin = K - ans.size();
        REP(i,ans.size()){
            while(margin and ans[i].size()){
                // debug(margin)
                cout << 1 << " " << ans[i].front() + 1 << bn;
                ans[i].pop();
                if(ans[i].size()) margin--;
            }
            if(ans[i].size()){
                cout << ans[i].size() << " " << ans[i];
            }
        }
    }
}