//Najdluzszy wspolny podciag
//bierze 2 slowa i znajduje ich najdluzszy podciag niekoniecznie spojny
//Autor: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3002;
string s,t;
int dp[SIZE][SIZE];
string wynik;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>s>>t; s = '#'+s; t = '$'+t;
  for(int i = 1; i < (int)s.size(); i++){
    for(int j = 1; j < (int)t.size(); j++){
      if(s[i] != t[j]) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      else dp[i][j] = dp[i-1][j-1]+1;
    }
  }
  int i = (int)s.size()-1, j = (int)t.size()-1;
  while(i > 0 && j > 0){
    if(s[i] == t[j]) wynik.push_back(s[i]), i--, j--;
    else if(dp[i][j-1] > dp[i-1][j]) j--;
    else i--;
  }
  reverse(wynik.begin(),wynik.end());
  cout<<wynik<<endl;
  return 0;
}
