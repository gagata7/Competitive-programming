#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SIZE = 2e5+3, N = (1<<18);
int n,h[SIZE];
ll w[SIZE],t[2*N],dp[SIZE],wynik;

void update(int poz, ll x){
  int v = poz+N;
  t[v] = x;
  while(v > 1) v/=2, t[v] = max(t[2*v],t[2*v+1]);
}

ll query(int a, int b){
  ll zwroc = 0;
  int vl = a+N-1, vr = b+N+1;
  while(vl/2 != vr/2){
    if(vl%2 == 0) zwroc = max(zwroc,t[vl+1]);
    if(vr%2 != 0) zwroc = max(zwroc,t[vr-1]);
    vl/=2, vr/=2;
  }
  return zwroc;
}

int main(){
  cin>>n;
  for(int i = 1; i <= n; i++) cin>>h[i];
  for(int i = 1; i <= n; i++) cin>>w[i];
  // for(int i = 1; i <= n; i++) update(i,w[i]);
  for(int i = 1; i <= n; i++){
    dp[i] = query(1,h[i]-1)+w[i];
    // cerr<<"maximum na przedziale od pozycji 1 do "<<h[i]<<" w drzewie to: "<<query(1,h[i]-1)<<endl;
    // cerr<<"dp["<<i<<"] = "<<query(1,h[i]-1)<<" + "<<w[i]<<" = "<<dp[i]<<endl;
    update(h[i],dp[i]);
    // cerr<<"robie update w drzewie na pozycji "<<h[i]<<" na "<<dp[i]<<endl;
    wynik = max(wynik,dp[i]);
  }
  cout<<wynik<<"\n";
  return 0;
}
