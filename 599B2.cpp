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
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 60;
const int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
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
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> const&P){
    os << P.first;
    os << " ";
    os << P.second;
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
void solve(){
    int N;
    cin >> N;
    string s,t;
    cin >> s >> t;
    vector<int> alpha(26,0);
    REP(i,N){
        alpha[s[i]-'a']++;
        alpha[t[i]-'a']++;
    }
    REP(i,26){
        if(alpha[i]&1){//奇数
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    vector<pair<int,int>> ans;
    REP(i,N){
        if(s[i]==t[i]) continue;

        for(int j=i+1;j<N;j++){
            if(t[i]==t[j]){
                swap(s[i],t[j]);
                ans.push_back(mp(i+1,j+1));
                break;
            }
            if(t[i]==s[j]){
                swap(t[j],s[j]);
                ans.push_back(mp(j+1,j+1));
                swap(s[i],t[j]);
                ans.push_back(mp(i+1,j+1));
                break;
            }
        }
    }
    cout << ans.size() << endl;
    REP(i,ans.size()){
        cout << ans[i] << endl;
    }

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(q,N){
        solve();
    }

}