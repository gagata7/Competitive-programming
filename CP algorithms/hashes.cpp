//algorytm znajdujacy hasze slowa s
//wykorzystuje modulo (dokladny ale wolny)
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int SIZE = 1000006, baza = 29, m = 1000000009;
string s;
int q;
ll pot[SIZE],hasz[SIZE];

void preprocessing(){
  pot[0] = 1;
  for(int i = 1; i < SIZE; i++) pot[i] = (pot[i-1]*baza)%m;
}

void zrob_hasze(){
  for(int i = 1; i <= (int)s.size(); i++) hasz[i] = ( (hasz[i-1]*baza) + (s[i]-'a'+1) )%m;
}

ll hashonseg(int x, int y){
  return (((hasz[y]-hasz[x-1]*pot[y-x+1])%m)+m)%m;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  preprocessing();
  cin>>s>>q;
  // zrob_hasze();
  for(int i = 0; i < q; i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(hashonseg(a,b) == hashonseg(c,d))
      cout<<"fragmenty od "<<a<<" do "<<b<<" oraz od "<<c<<" do "<<d<<" sa identyczne"<<endl;
  }
  return 0;
}
