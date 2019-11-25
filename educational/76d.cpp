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
template <typename T>
ostream& operator<<(ostream& os, deque<T> &q){
    for(auto it=q.begin();it<q.end();it++){
        os<<*it;
        os<<" ";
    }
     os<<endl;
    return os;
}
void solve(){
    int n,m; cin >> n;
    vector<int> mons(n); REP(i,n) cin >> mons[i];
    cin >> m; 
    vector<pair<int,int>> DA(m);
    int atk,def;
    REP(i,m){
        cin >> atk >> def;
        DA[i] = mp(def,atk);
    }
    sort(ALL(DA),greater<pair<int,int>>() ); //スタミナ順でsort
    set<int> S;//強さのset

    map<int,int> endurance;//endurance[i]:=強さi以上のHEROで、スタミナ最大
    REP(i,m){
        tie(d,a) = DA[i];
        chmax(endurance[a], d); //重複あるかもしれないのでmaxでとる
        S.insert(a);
        auto it = S.find(a);
        if(++it!=S.end()){
            chmax(endurance[a], endurance[*it]); //次に強い段階でのスタミナ最大と比較
        }
    }
    int i=0;//何体目？
    int ans = 1;
    int now_cnt = 0;//今日倒した数
    int strong = 0;//今日倒しているモンスターの中で最強
    while (i<n){
        auto it = S.lower_bound(max(mons[i],strong)); //必要な強さ(HEROの中で)
        if(it==S.end()){//倒せない
            cout << -1 << endl;
            return;
        }
        if (endurance[*it]>now_cnt){//そのまま倒して進む
            chmax(strong,mons[i]);
            now_cnt++;
            i++;
        }else{//スタミナ切れ！一旦ダンジョンから出る！
            now_cnt=0;
            ans++;
            if(now_cnt>=2) ans++;
            strong=0;
        }
    }
    cout << ans << endl;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(i,N){
        solve();
    }
}