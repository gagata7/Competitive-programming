#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SIZE = 100003;
ll n,W,w[SIZE],v[SIZE],max_v;
ll wynik, dp[SIZE];
const ll inf = 1e16;

void preprocessing(){
  for(int i = 1; i <= max_v; i++) dp[i] = inf;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>W;
  for(int i = 0; i < n; i++) cin>>w[i]>>v[i], max_v+=v[i];
  preprocessing();
  for(int i = 0; i < n; i++){
    for(ll j = max_v; j >= 0; j--){
      if(dp[j] != inf && j+v[i] <= max_v){
        dp[j+v[i]] = min(dp[j+v[i]],dp[j]+w[i]);
      }
    }
  }
  for(int i = 0; i <= max_v; i++)
    if(dp[i] <= W) wynik = i;
  cout<<wynik<<"\n";
  return 0;
}
