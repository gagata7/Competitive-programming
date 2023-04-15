#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1003;
const long long mod = 1e9+7;
int n,m;
long long dp[SIZE][SIZE];
char t[SIZE][SIZE];

int main(){
  cin>>n>>m; dp[1][1] = 1;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) cin>>t[i][j];
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(t[i][j] == '.'){
        if(t[i-1][j] == '.') dp[i][j]+= dp[i-1][j];
        if(t[i][j-1] == '.') dp[i][j]+= dp[i][j-1];
        dp[i][j]%=mod;
      }
  cout<<dp[n][m]<<"\n";
  return 0;
}
