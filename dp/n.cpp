#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SIZE = 403;
int n;
ll t[SIZE];

ll f(int p, int k){
  ll wynik = 0;
  for(int i = p; i < k; i++)
    wynik = max(wynik,f(p,i-1)+f(i+1,k)+t[i]+t[i+1]);
  return wynik;
}

int main(){
  cin>>n;
  for(int i = 1; i <= n; i++) cin>>t[i];
  cout<<f(1,n)<<"\n";
  return 0;
}
