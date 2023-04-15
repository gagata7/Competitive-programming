#include <bits/stdc++.h>
using namespace std;

int n,t[100003][4],dp[100003][4];

int main(){
  cin>>n;
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < 3; j++) cin>>t[i][j];
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < 3; j++){
      if(j == 0) dp[i][j] = t[i][j]+max(dp[i-1][1],dp[i-1][2]);
      if(j == 1) dp[i][j] = t[i][j]+max(dp[i-1][0],dp[i-1][2]);
      if(j == 2) dp[i][j] = t[i][j]+max(dp[i-1][1],dp[i-1][0]);
    }
  cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<"\n";
  return 0;
}
