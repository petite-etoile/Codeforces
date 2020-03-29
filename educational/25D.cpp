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

map<char,int64> cnt_s,cnt_t;
bool is_ok(int64 x){
    int64 shortage_cnt = 0;
    char c;
    int64 need;
    for(auto e:cnt_t){
        tie(c,need) = e;
        need *= x;
        shortage_cnt+=max(0LL, need - cnt_s[e.first]);
    }
    return shortage_cnt <= cnt_s['?'];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T;
    cin >> S >> T;
    for(auto s:S){
        cnt_s[s]++;
    }
    for(auto t:T){
        cnt_t[t]++;
    }

    int ok = 0;
    int ng = 1e6+1;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        if(is_ok(mid)) ok = mid;
        else ng = mid;
    }
    stack<char> add_char;
    for(auto e:cnt_t){
        char c;
        int64 need;
        tie(c,need) = e;
        need *= ok;
        int shortage = max(0LL, need-cnt_s[c]);
        REP(i,shortage){
            add_char.push(c);
        }
    }

    REP(i,S.size()){
        if(S[i]=='?'){
            if(not add_char.empty()){
                S[i] = add_char.top();
                add_char.pop();
            }else{
                S[i] = 'y';
            }
        }
    }
    cout << S << bn;

}