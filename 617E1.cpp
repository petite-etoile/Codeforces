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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    vector<pair<char,int>> SI(N);
    REP(i,N){
        SI[i] = mp(S[i],i);
    }
    sort(ALL(SI));

    string ans(N,'5');
    // vector<char> ans(N);
    int idx;
    char s;
    REP(i,N){
        tie(s,idx) = SI[i];
        if(idx<i) ans[idx]='1';
        else ans[idx]='0';
        int now = -1;
        for(int j=i+1;j<=idx;j++){
            int idx2 = SI[j].second;
            if(idx2 < now){
                cout << "NO" << bn;
                return 0;
            }
            now = idx2;
        }
    }
    cout << "YES" << bn;
    cout << ans << bn;
    
    // string T = S;
    // sort(ALL(T));

    // vector<queue<int>> char_idx(26);
    // REP(i,N){
    //     auto c = T[i];
    //     char_idx[c-'a'].push(i);
    // }

    // string ans(N,'5');
    // REP(i,N){
    //     auto s = S[i];
    //     int go_idx = char_idx[s-'a'].front(); char_idx[s-'a'].pop();
    //     if (go_idx<i){
    //         ans[i]='0';
    //         char now = 'a';
    //         for(int j=go_idx; j<i; j++){
    //             if(S[j]<now){
    //                 debug(go_idx)
    //                 cout << i << " " << j << bn;
    //                 cout << "NO" << bn; return 0;
    //             }
    //             now = S[j];
    //             ans[j] = '1';
    //         }
    //     }
    // }
    // cout << ans << bn;

    
}