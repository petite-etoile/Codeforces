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
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;

    set<int> S;
    deque<int> q;
    REP(i,N){
        int a;
        cin >> a;
        if(S.find(a)==S.end()){
            q.push_back(a);
            S.insert(a);
            if(q.size() > K){
                int f = q.front();
                q.pop_front();
                S.erase(f);
            }
        }
    }
    int ans = q.size();

    cout << ans << endl;
    for(auto it=q.rbegin();it<q.rend();it++){
        cout << *it << " ";
    }
    
}