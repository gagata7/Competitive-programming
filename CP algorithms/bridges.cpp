//algorytm znajdujacy mosty
//graf - spojny
//krawedzie - nieskierowane, niewazone
//przygotowala: Agata Pokorska
//definicja: most - krawedz, po ktorej usunieciu, graf sie rozspojnia
//Most to krawedz, ktora nie lezy na zadnym cyklu prostym (nie jest krawedzia wtorna)
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5, inf = 1e8;
int n,m;//n - wierzcholkow i m-krawedzi
vector<int> s[SIZE];
bool czy[SIZE];
int czas,low[SIZE],d[SIZE],par[SIZE];

void dfs(int u, int p){
  czy[u] = true;
  d[u] = ++czas;
  par[u] = p;
  low[u] = d[u];
  for(auto& v:s[u]){
    if(!czy[v]) dfs(v,u), low[u] = min(low[u],low[v]);
    if(v != par[u]) low[u] = min(low[u],d[v]);
  }
}

int main(){
  cin>>n>>m;
  for(int i = 0; i < m; i++){int a,b; cin>>a>>b; s[a].push_back(b),s[b].push_back(a);}
  dfs(1,1);
  for(int i = 1; i <= n; i++)
    if(low[i] == d[i] && i != 1) cout<<"krawedz od "<<i<<" do "<<par[i]<<" jest mostem"<<endl;
  return 0;
}
