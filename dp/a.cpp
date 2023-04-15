#include <bits/stdc++.h>
using namespace std;

long long n,k[100003];
long long dp[100003];

int main(){
  cin>>n;
  for(int i = 0; i < n; i++) cin>>k[i];
  dp[0] = 0, dp[1] = abs(k[1]-k[0]);
  for(int i = 2; i < n; i++){
    dp[i] = min(dp[i-1]+abs(k[i]-k[i-1]),dp[i-2]+abs(k[i]-k[i-2]));
    //cerr<<"dp["<<i<<"] = "<<dp[i]<<endl;
  }
  cout<<dp[n-1]<<"\n";
  return 0;
}
