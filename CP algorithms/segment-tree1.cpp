//drzewo typu punkt-przedzial
//wariant +/suma
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int q;//liczba zapytan
const int N = (1<<20);
ll t[2*N];

void update(int poz, ll x){
  int v = poz+N;
  t[v]+=x;
  while(v > 1) v/=2, t[v] = t[2*v]+t[2*v+1];
}

ll query(int p, int k){
  int vl = p+N-1, vr = k+N+1;
  ll wynik = 0;
  while(vl/2 != vr/2){
    if(vl%2 == 0) wynik+=t[vl+1];
    if(vr%2 != 0) wynik+=t[vr-1];
    vl/=2, vr/=2;
  }
  return wynik;
}

int main(){
  cin>>q;
  for(int i = 0; i < q; i++){
    int o,a,b;//o - jaka operacja (+/suma)
    cin>>o>>a>>b;
    if(o == 0) update(a,b);//dodaj wartosc b na pozycji a
    else cout<<query(a,b)<<"\n";//wypisz sume na przedziale od a do b
  }
  return 0;
}
