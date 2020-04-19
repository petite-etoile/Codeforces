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
template <typename T,typename S>
ostream& operator<<(ostream& os, map<T,S> const&M){
    for(auto e:M){
        os<<e;
    }
    os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

void add(set<char>& odd, char c){
    if(odd.find(c)!=odd.end()) odd.erase(c);
    else odd.insert(c);
}

//dまでそのまま
bool check(int d, set<char> odd,const string& S,string& ans){
    int N = S.size();
    int remain = N - d;
    string res = S.substr(0,d) + string(remain,'?');
    if(odd.size()>remain){
        return false;
    }else{
        assert(res.size() == S.size());
        if(odd.size() == remain){
            for(auto it=odd.rbegin();it!=odd.rend();it++){
                if(S[d]>*it){
                    res[d] = *it;
                    add(odd,res[d]);
                    break;
                }
            }
            if(res[d] == '?') return false;
        }else{
            if(S[d]=='0' or (d==0 and S[d]=='1')) return false;
            res[d] =  S[d]-1;
            add(odd,res[d]);
        }
        for(int i=N-1; odd.size()>0; i--){
            assert(res[i] == '?');
            res[i] = *odd.begin();
            add(odd,res[i]);
        }
    }
    REP(i,N){
        if(res[i]=='?') res[i] = '9';
    }
    assert(odd.size()==0);
    ans = res;
    return true;
}
void solve(){
    string S;
    cin >> S;

    set<char> odd; //奇数個ある文字
    
    bool less = false;
    string ans(S.size()-2,'9');
    for(auto s:S) add(odd,s);
    REP(i,S.size()){
        int idx = S.size() - i - 1;
        add(odd,S[idx]);
        if(check(idx,odd,S,ans)) break;
    }
    cout << ans << bn;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    REP(i,N) solve();
}