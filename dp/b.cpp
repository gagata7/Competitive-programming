#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SIZE = 100003;
const ll inf = 1e15;
int n,ile;
ll dp[SIZE],k[SIZE];

void preprocessing(){
  for(int i = 2; i <= n; i++) dp[i] = inf;
  dp[1] = abs(k[1]-k[0]);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>ile;
  for(int i = 0; i < n; i++) cin>>k[i];
  preprocessing();
  for(int i = 2; i < n; i++)
    for(int j = max(0,i-ile); j <= i-1; j++)
      dp[i] = min(dp[j]+abs(k[j]-k[i]),dp[i]);
  cout<<dp[n-1]<<"\n";
  return 0;
}
