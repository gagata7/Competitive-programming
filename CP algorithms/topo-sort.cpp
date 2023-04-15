//algorytm na sortowanie topologiczne
//graf - DAG
//krawedzie - skierowane, nieważone
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5;
int n,m,pre;
vector<int> s[SIZE],wynik;
bool czy[SIZE];

void dfs(int u){
  czy[u] = true;
  for(auto& v:s[u])
    if(!czy[v]) dfs(v);
  //najpierw odwiedzam wszystkich sasiadow, i daje ich na spod "stosu"
  //dopiero na gore daje wierzcholek u, ktory ma byc przed nimi
  wynik.push_back(u);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  //krawedz skierowana a->b
  for(int i = 0; i < m; i++){int a,b; cin>>a>>b; s[a].push_back(b);}
  for(int i = 1; i <= n; i++)
    if(!czy[i]) dfs(i);
  for(int i = n-1; i >= 0; i--) cout<<wynik[i]<<" ";//wypisuj od "gory" stosu
  cout<<"\n";
  return 0;
}
