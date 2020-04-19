#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int mod = 998244353;
ll dp[3010][3010];

int main(){
    string s,t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for(int i=0; i<n-m; i++) t.push_back('@'); //文字列sと同じサイズになるまで'@'を追加
    for(int i=0; i<n+1; i++) dp[i][0] = 1; //dp配列の初期化

    for(int j=0; j<n+1; j++){
        for(int i=0; i<n+1; i++){
            int r = i+j; //右に文字を追加するときの追加場所
            if(r<n && (s[j]==t[r] || t[r]=='@')) (dp[i][j+1] += dp[i][j]) %= mod; //右に追加
            if(i>0 && (s[j]==t[i-1] || t[i-1]=='@')) (dp[i-1][j+1] += dp[i][j]) %= mod; //左に追加
        }
    }
    
    ll ans = 0;
    for(int i=m; i<n+1; i++) (ans += dp[0][i]) %= mod; //0番目からm文字以上一致する場合の数を加算
    cout << ans << endl;
}