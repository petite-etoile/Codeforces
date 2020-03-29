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
    int N,K;
    string S;
    cin >> N >> K >> S;

    //答えに追加可能なときのみ、queue.pushが発生し、K<=100よりかなり高速？
    queue<string> remain;
    set<string> s;
    s.insert(S);
    remain.push(S);

    int64 ans=0;
    while(s.size() < K and not remain.empty()){ //K個求まるか、不可能になるまで
        string now = remain.front(); remain.pop(); //queueの先頭
        REP(i,now.size()){ //i番目を消した部分文字列について調べる
            string now_copy = now; 
            now_copy.erase(i,1); //消す

            if(s.find(now_copy) == s.end()){ //これがまだSに追加されてないなら,Sにaddする
                ans += N - now_copy.size(); 
                s.insert(now_copy);
                remain.push(now_copy);
                if(s.size()>=K) break;
            }
        }
    }
    if(s.size()==K){
        cout  << ans << bn;
    }else{
        cout << -1 << bn;
    }

}