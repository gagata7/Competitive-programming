//algorytm LCA - lowest common ancestor, przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6, LOG = 20;
int n,m;//n - wierzcholkow i m - krawedzi
int p[LOG][SIZE],poz[SIZE];
vector<int> s[SIZE];
bool czy[SIZE];

void dfs(int u){
  czy[u] = true;
  for(auto& v:s[u])
    if(!czy[v]) p[0][v] = u, poz[v] = poz[u]+1,dfs(v);
}
void preprocessing(){
  dfs(1);
  for(int i = 1; i < LOG; i++)
    for(int j = 1; j <= n; j++) p[i][j] = p[i-1][p[i-1][j]];
}
int jump(int x, int k){
  for(int i = 0; i < LOG; i++)
    if(k&(1<<i)) x = p[i][x];
  return x;
}

int lca(int a, int b){
  if(a == b) return a;
  if(poz[a] > poz[b]) swap(a,b);
  b = jump(b,poz[b]-poz[a]);
  for(int i = LOG-1; i >= 0; i--)
    if(p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
  if(a == b) return a;
  return p[0][a];
}

int main(){
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b; cin>>a>>b; s[a].push_back(b); s[b].push_back(a);}
  preprocessing();
  int q; cin>>q;
  for(int i = 0; i < q; i++){
    int a,b; cin>>a>>b;
    cout<<lca(a,b)<<"\n";
  }
  return 0;
}
