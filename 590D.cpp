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
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<set<int>> Sets(26);
    REP(i,S.size()){
        Sets[S[i]-'a'].insert(i+1);
    }
    REP(i,Q){
        int q;
        cin >> q;
        if(q==1){
            char c;
            int index;
            cin >> index >> c;
            Sets[S[index-1]-'a'].erase(index);
            Sets[c-'a'].insert(index);
            S[index-1]=c;
            
        }else{
            int l,r;
            cin >> l >> r;
            int ans = 0;
            
            REP(j,26){
                auto left = Sets[j].lower_bound(l);
                auto right = Sets[j].upper_bound(r);
                if(left!=right) ans++;
            }
            cout << ans << endl;
        }
    }
}