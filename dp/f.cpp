#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1000003;
int n;
vector<int> v;
bool czy[SIZE];

void pierwsze(){
  for(int i = 2; i < SIZE; i++)
    if(!czy[i]){
      v.push_back(i);
      for(int j = i+i; j < SIZE; j+=i) czy[j] = true;
    }
}

int f(int x){
  int p = 0, k = (int)v.size()-1, s = 0;
  while(p < k){
    s = (p+k+1)/2;
    if(v[s] < x) p = s;
    else k = s-1;
  }
  // cerr<<"ostatnia liczba pierwsza < "<<x<<": "<<v[p]<<" ktora jest "<<p+1<<" w kolejnosci"<<endl;
  return p+1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pierwsze();
  cin>>n;
  for(int i = 0; i < n; i++){
    int a,b;
    cin>>a>>b;
    int p = f(a), k = f(b);
    if(a < 3) p = 0;
    int wynik = k-p;
    if(!czy[b]) wynik++;
    if(b == 1) wynik = 0;
    cout<<wynik<<"\n";
  }
  return 0;
}
