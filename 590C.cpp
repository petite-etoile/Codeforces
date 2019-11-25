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
os << "\n";
return os;
}
int is_bar(char s){
    if(s=='1'||s=='2') return 1;
    else return 0;
}
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    int Q,N;
    cin >> Q;
    REP(i,Q){
        cin >> N;
        string S,T;
        cin >> S >> T;

        pair<int,int> can_go(1,0),next(0,0); //上、下
        REP(j,N){
            next=make_pair(0,0);
            if(is_bar(S[j])){next.first = can_go.first;} //棒
            if(is_bar(T[j])){next.second = can_go.second;} //棒
            if(!is_bar(S[j]) && !is_bar(T[j])){ //両方L字
                if(next.first==0) next.first=can_go.second;
                if(next.second==0) next.second=can_go.first;
            }
            can_go = next;
        }
        if (can_go.second) cout << "YES\n";
        else cout << "NO\n";
    }
}