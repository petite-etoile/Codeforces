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

template <typename T, typename L>
ostream& operator<<(ostream& os, map<T,L> &q){
    for(auto e:q){
        os<<e.first;
        os<<" ";
        os<<e.second;
        os<<bn;
    }
    os<<endl;
    return os;
}


vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

bool is_ok(map<char,int>& M){
    return M['X']==4 and M['.']==1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N = 10;
    vector<string> grid(N);
    REP(i,N) cin >> grid[i];

    //row
    REP(h,N){
        map<char,int> M;
        auto grid_h = grid[h];
        REP(i,5){
            M[grid_h[i]]++;
        }
        if(is_ok(M)){
            cout << "YES\n";
            return 0;
        }

        REP(i,5){
            M[grid_h[i]]--;
            M[grid_h[i+5]]++;
            if(is_ok(M)){
                cout << "YES\n";
                return 0;
            }
        }
    }

    //column
    REP(w,N){
        map<char,int> M;
        REP(h,5){
            M[grid[h][w]]++;
        }
        if(is_ok(M)){
            cout << "YES\n";
            return 0;
        }

        REP(h,5){
            M[grid[h][w]]--;
            M[grid[h+5][w]]++;
            if(is_ok(M)){
                cout << "YES\n";
                return 0;
            }
        }
    }
    //closs
    REP(h,N){
        REP(w,N){
            map<char,int> M;
            bool out_of_range = false;
            REP(i,5){
                if(i+h>=N or i+w>=N){
                    out_of_range = true;
                    break;
                }
                M[grid[h+i][w+i]]++;
            }
            if(out_of_range) continue;
            if(is_ok(M)){
                cout << "YES\n";
                return 0;
            }

            REP(i,5){
                if(i+h+5>=N or i+w+5>=N){
                    out_of_range = true;
                    break;
                }
                M[grid[h+i][w+i]]--;
                M[grid[h+i+5][w+i+5]]++;
                if(is_ok(M)){
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    //closs2
    REP(h,N){
        reverse(ALL(grid[h]));
    }
    REP(h,N){
        REP(w,N){
            map<char,int> M;
            bool out_of_range = false;
            REP(i,5){
                if(i+h>=N or i+w>=N){
                    out_of_range = true;
                    break;
                }
                M[grid[h+i][w+i]]++;
            }
            if(out_of_range) continue;
            if(is_ok(M)){
                cout << "YES\n";
                return 0;
            }

            REP(i,5){
                if(i+h+5>=N or i+w+5>=N){
                    out_of_range = true;
                    break;
                }
                M[grid[h+i][w+i]]--;
                M[grid[h+i+5][w+i+5]]++;
                if(is_ok(M)){
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO" << bn;
}