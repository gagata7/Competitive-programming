//algorytm znajdujacy silnie-spojne skladowe
//graf skierowany
//krawedzie - niewazone
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6;
int q,n,m;//n - liczba wierzcholkow, m - liczba krawedzi
bool czy[SIZE];
vector<int> s[SIZE],s2[SIZE],post;
int ptr = 1,C[SIZE];//tablica silnie spojnych skladowych

void dfs(int u){
  czy[u] = true;
  for(auto& v:s[u])
    if(!czy[v]) dfs(v);
  post.push_back(u);
}

void dfs2(int u, int k){
  czy[u] = false, C[u] = k;
  for(auto& v:s2[u])
    if(czy[v]) dfs2(v,k);
}

int main(){
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b; cin>>a>>b;
    //stworz krawedz a->b w grafie i b->a w odwroconym grafie
    s[a].push_back(b), s2[b].push_back(a);
  }
  for(int i = 1; i <= n; i++)
    if(!czy[i]) dfs(i);//puszczam dfs z kazdego wierzcholka
  for(int i = (int)post.size()-1; i >= 0; i--)
    if(czy[post[i]]) dfs2(post[i],ptr++);//puszczam dfs2 z uzupelnieniem spojnych skladowych (ptr)
  cin>>q;
  for(int i = 0; i < q; i++){
    int x; cin>>x;
    cout<<"wierzcholek "<<x<<" nalezy do silnie-spojnej o numerze "<<C[x]<<endl;
  }
  return 0;
}
