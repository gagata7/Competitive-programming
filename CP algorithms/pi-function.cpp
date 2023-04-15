//algorytm liczacy tablice KMP (pi) do obliczania okresu slowa
//najdluzszy prefikso-sufiks
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6;
string s;
int p[SIZE];

void policz_pi(){
  for(int i = 1; i < (int)s.size(); i++){
    int j = p[i-1];
    while(j > 0 && s[j] != s[i]) j = p[j-1];
    //to znaczy ze trzeba zmniejszyc brzuszek(do poprzedniego rozmiaru)
    if(s[j] == s[i]) j++;//mozna zwiekszyc rozmiar brzuszka
    p[i] = j;
  }
}

int main(){
  cin>>s;
  policz_pi();
  for(int i = 0; i < (int)s.size(); i++) cout<<p[i]<<" ";
  cout<<endl;
  return 0;
}
