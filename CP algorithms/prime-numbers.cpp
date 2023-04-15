#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+3;
bool czy[SIZE];

void policz_pierwsze(){
  for(int i = 2; i*i < SIZE; i++)
    if(!czy[i])
      for(int j = i*i; j < SIZE; j+=i) czy[j] = true;
}

int main(){
  policz_pierwsze();
  int n; cin>>n;
  for(int i = 2; i <= n; i++)
    if(!czy[i]) cout<<i<<" ";
  cout<<"\n";
  return 0;
}
