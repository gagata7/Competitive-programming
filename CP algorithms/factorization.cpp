#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+3;
int f[SIZE];

void preprocessing(){
  for(int i = 2; i*i < SIZE; i++)
    if(!f[i])
      for(int j = i*i; j < SIZE; j+=i) f[j] = i;
}

int main(){
  preprocessing();
  int x; cin>>x;
  while(f[x] > 0) cout<<f[x]<<" ", x/=f[x];
  cout<<x<<endl;
  return 0;
}
