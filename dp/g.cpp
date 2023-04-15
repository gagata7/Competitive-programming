#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100005;
int n,m,dp[SIZE],wynik;
vector<int> s[SIZE];
bool czy[SIZE];

void dfs(int u){
  czy[u] = true;
  for(auto& v:s[u]){
    if(!czy[v]) dfs(v);
    dp[u] = max(dp[u],dp[v]+1);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin>>a>>b;
    s[a].push_back(b);
  }
  for(int i = 1; i <= n; i++)
    if(!czy[i]) dfs(i), wynik = max(dp[i],wynik);
  cout<<wynik<<"\n";
  return 0;
}
