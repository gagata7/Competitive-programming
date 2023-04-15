#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100003;
int n,W,w[103],v[103];
long long dp[SIZE],wynik;

void preprocessing(){
  for(int i = 1; i < SIZE; i++) dp[i] = -1;
}

int main(){
  preprocessing();
  cin>>n>>W;
  for(int i = 0; i < n; i++) cin>>w[i]>>v[i];
  for(int i = 0; i < n; i++){
    for(int j = W; j >= 0; j--)//bo jednorazowo mozemy uzyc danego przedmiotu
      if(dp[j] != -1 && j+w[i] <= W) dp[j+w[i]] = max(dp[j+w[i]],dp[j]+v[i]);
  }
  for(int i = 0; i <= W; i++) wynik = max(wynik,dp[i]);
  cout<<wynik<<"\n";
  return 0;
}
