#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SIZE = 3e3+7;
const ll inf = 1e18;
int n;
ll t[SIZE],dp[SIZE][SIZE];

void preproessing(){
  for(int i = 0; i <=n+1; i++)
    for(int j = 0; j <=n+1; j++) dp[i][j] = inf;
  for(int i = 0; i < n; i++) dp[i][i] = t[i];
}

ll f(int i, int j){
  // cerr<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
  if(dp[i][j] == inf) dp[i][j] = max(t[i]-f(i+1,j),t[j]-f(i,j-1));
  return dp[i][j];
}

int main(){
  cin>>n;
  for(int i = 0; i < n; i++) cin>>t[i];
  preproessing();
  cout<<f(0,n-1)<<"\n";
  return 0;
}
