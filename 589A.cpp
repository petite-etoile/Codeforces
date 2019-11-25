#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
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
ostream& operator<<(ostream& os, pair<T,T> &P){
os << P.first;
os << " ";
os << P.second;
os << " 1";
return os;
}
bool ok(int x){
    string S = to_string(x);
    int d[10] = {0};
    for(auto s:S){

        //cout << s << " " << d[s-'0'] << " " << s << endl;
        if(d[s-'0']==0) d[s-'0']++;
        else return false;
    }
    return true;
}
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int l,r;
    cin >> l >> r;
    int ans=-1;
    FOR(x,l,r+1){
        if(ok(x)){
            ans = x;
            break;
        }
    }

    cout << ans << endl;
}