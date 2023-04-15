//algorytm Union-Find
//graf - nieskierowany
//krawedzie - niewazone
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6;
int p[SIZE],n,q;//n - liczba wierzcholkow, q - liczba zapytan/polaczen

void preprocessing(){
  for(int i = 1; i < SIZE; i++) p[i] = i;
}

int Find(int x){
  if(p[x] == x) return x;
  p[x] = Find(p[x]);
  return p[x];
}

void Union(int a, int b){
  p[Find(a)] = Find(b);
}

int main(){
  preprocessing();
  cin>>n>>q;
  for(int i = 0; i < q; i++){
    int o,a,b;
    cin>>o>>a>>b;
    if(o == 0) Union(a,b);
    else
      if(Find(a) == Find(b)) cout<<"wierzcholki "<<a<<" i "<<b<<" sa polaczone\n";
      else cout<<"wierzcholki "<<a<<" i "<<b<<" nie sa polaczone\n";
  }
  return 0;
}
