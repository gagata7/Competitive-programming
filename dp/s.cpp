#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SIZE = 1e4+8;
const ll mod = 1e9+7;
string k;
ll d;
ll dp[SIZE][103][3];

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cout.tie(0);
  cin>>k>>d;
  dp[0][0][1] = 1;
  ll pom = (int)k.size();
  for(ll i = 0; i < pom; i++){
    for(ll r = 0; r < d; r++){
      for(ll x = 0; x <= 9; x++){
        dp[i+1][(r+x)%d][0] = (dp[i+1][(r+x)%d][0]+dp[i][r][0])%mod;
        if(x < k[i]-'0') dp[i+1][(r+x)%d][0] = (dp[i+1][(r+x)%d][0]+dp[i][r][1])%mod;
        if(x == k[i]-'0') dp[i+1][(r+x)%d][1] = (dp[i+1][(r+x)%d][1]+dp[i][r][1])%mod;
      }
    }
  }
  ll wynik = (dp[pom][0][0]+dp[pom][0][1]-1+mod)%mod;
  cout<<wynik<<"\n";
  return 0;
}
