#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
const int SIZE = 1e5+3;
int n;
vector<int> s[SIZE];
bool czy[SIZE];
ll dp[SIZE][3];

void preprocessing(){
  for(int i = 0; i < SIZE; i++) dp[i][0] = dp[i][1] = 1;
}

void dfs(int u){
  czy[u] = true;
  for(auto& v:s[u])
    if(!czy[v]) dfs(v), dp[u][0] = (dp[u][0]*(dp[v][0]+dp[v][1]))%mod, dp[u][1] = (dp[u][1]*dp[v][0])%mod;
  // cerr<<"jestem w wierzcholku "<<u<<" dp["<<u<<"][0] = "<<dp[u][0]<<"  dp["<<u<<"][1] = "<<dp[u][1]<<endl;
}

int main(){
  preprocessing();
  cin>>n;
  for(int i = 0; i < n-1; i++){int x,y; cin>>x>>y; s[x].push_back(y), s[y].push_back(x);}
  dfs(1);
  ll wynik = (dp[1][0]+dp[1][1])%mod;
  cout<<wynik<<endl;
  return 0;
}
