#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+6;
int n,k,x,mini = SIZE;
bool dp[SIZE];
vector<int> A;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i = 0; i < n; i++){
    cin>>x;
    A.push_back(x), mini = min(mini,x); //dp[x] = true;
  }
  for(int i = 0; i <= k; i++)
    if(!dp[i])
      for(auto& a:A) dp[i+a] = true;
  if(dp[k]) cout<<"First"<<"\n";
  else cout<<"Second"<<"\n";
  return 0;
}
