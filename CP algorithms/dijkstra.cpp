//algorytm Dijkstry - znajduje najkrotsza odleglosc od 1 do dowolnego innego wierzcholka
//graf - nieskierowany
//krawedzie - wazone
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

int n,m;//n - wierzcholkow, m - krawedzi
const int SIZE = 1e6, inf = 1e8;
vector<pair<int,int> > s[SIZE];
int dp[SIZE];//tablica z najkrotsza odlegloscia od wierzcholka i do 1
priority_queue<pair<int,int> > pq;//para(waga,wierzcholek do ktorego prowadzi krawedz)

void preprocessing(){
  for(int i = 2; i < SIZE; i++) dp[i] = inf;
}

int main(){
  preprocessing();
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b,c; cin>>a>>b>>c; s[a].push_back({b,c}),s[b].push_back({a,c});
    // pq.insert(c,a), pq.insert(c,b);
  }
  pq.push({0,1});//wstawiam pierwszy element na kolejke
  while(!pq.empty()){
    int u = pq.top().second; pq.pop();
    for(auto& v:s[u]){
      if(dp[v.first] > dp[u]+v.second){
        dp[v.first] = dp[u]+v.second;
        pq.push({-v.second,v.first});
      }
    }
  }
  for(int i = 1; i <= n; i++) cout<<"dystans od "<<i<<" do 1: "<<dp[i]<<endl;
  return 0;
}
