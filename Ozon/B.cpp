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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();
    // int ans = 0;
    // int l_cnt = 0;
    // vector<int> ans_vec;
    // REP(i,N){
    //     if(S[i]=='(') l_cnt++;
    //     else{
    //         if(l_cnt){
    //             l_cnt--;
    //             ans++;
    //             ans_vec.emplace_back(i+1);
    //         }
    //     }
    // }
    // l_cnt = ans;
    // REP(i,N){
    //     if(S[i]=='('){
    //         if(l_cnt){ ans_vec.emplace_back(i+1); l_cnt--;}
            
    //     }
    // }

    // sort(ALL(ans_vec));
    // if(ans){
    //     cout << 1 << bn;
    //     cout << ans*2 << bn;
    //     cout << ans_vec;
    // }else cout << 0 << bn;
    vector<int> cumsum(N),cumsum_rev(N);
    int before = 0, before_rev = 0;
    int mid = 0;
    REP(i,N){
        int rev_i = N-i-1;
        cumsum[i] = before;
        cumsum_rev[rev_i] = before_rev;
        if(S[i]=='(') cumsum[i]++;
        if(S[rev_i]==')') cumsum_rev[rev_i]++;
        before = cumsum[i];
        before_rev = cumsum_rev[rev_i];
    }
    int ans = 0;
    REP(i,N){
        if(chmax(ans, min(cumsum[i],cumsum_rev[i]))) mid = i;
    }
    if(ans==0) {cout << 0 << bn; return 0;}

    cout << 1 << bn;
    cout << ans*2 << bn;
    vector<int> ans_vec;
    int cnt = ans;
    REP(i,mid+1){
        if(S[i]=='(' and cnt){
            cnt--;
            ans_vec.emplace_back(i+1);
        }
    }
    cnt = ans;
    for(int i=N-1;i>=mid;i--){
        if(S[i]==')' and cnt){
            cnt--;
            ans_vec.emplace_back(i+1);
        }
    }
    sort(ALL(ans_vec));
    cout << ans_vec;

}

