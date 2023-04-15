#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SIZE = 1e5+8;
int n,k,a[SIZE];
ll dp[102][SIZE],s[102][SIZE];
const ll mod = 1e9+7;

void ustaw(int x){
  s[x][0] = dp[x][0];
  for(int i = 1; i < SIZE; i++) s[x][i] = s[x][i-1]+dp[x][i];
}

void preprocessing(){
  dp[0][0] = 1, s[0][0] = 1, ustaw(0);
}

int main(){
  cin>>n>>k;
  for(int i = 1; i <= n; i++) cin>>a[i];
  preprocessing();
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= k; j++){
      int pom = j-a[i]-1;
      if(pom < 0) dp[i][j] = s[i-1][j]%mod;
      else dp[i][j] = (s[i-1][j]-s[i-1][pom])%mod;
      // cerr<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
    }
    ustaw(i);
  }
  cout<<dp[n][k]<<"\n";
  return 0;
}
