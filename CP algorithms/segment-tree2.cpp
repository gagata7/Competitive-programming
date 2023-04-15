//drzewo typu przedzial-przedzial
//wariant +/suma
//przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int q;
const int N = (1<<20);

class tree{
  int a,b;
  ll c;
  ll t[2*N],s[2*N];//t -> wartosc lazy, s -> wartosc rzeczywista
  void lazy(int u, int low, int high){
    s[u]+=t[u]*(high-low+1);
    if(u < N) t[2*u]+=t[u], t[2*u+1]+=t[u];
    t[u] = 0;
  }
  void upd(int u = 1, int low = 0, int high = N-1){
    lazy(u,low,high);
    if(low > b || high < a) return;
    if(low >= a && high <= b){t[u]+=c, lazy(u,low,high); return;}
    upd(u*2,low,(low+high)/2);
    upd(u*2+1,(low+high)/2+1,high);
    s[u] = s[2*u]+(t[2*u]*(high-low+1)/2)+s[2*u+1]+(t[2*u+1]*(high-low+1)/2);
  }
  ll que(int u = 1, int low = 0, int high = N-1){
    lazy(u,low,high);
    if(low > b || high < a) return 0;
    if(low >= a && high <= b) return s[u];
    ll L = que(u*2,low,(low+high)/2);
    ll R = que(u*2+1,(low+high)/2+1,high);
    return L+R;
  }
public:
  void update(int A, int B, ll C){a = A, b = B, c = C, upd();}
  ll query(int A, int B){a = A, b = B; return que();}
}T;

int main(){
  cin>>q;
  for(int i = 0; i < q; i++){
    int o; cin>>o;
    //0 - dodaj wartosc na przedziale
    //1 - podaj sume na przedziale
    if(o == 0){int a,b; ll c; cin>>a>>b>>c; T.update(a,b,c);}
    else{int a,b; cin>>a>>b; cout<<T.query(a,b)<<"\n";}
  }
  return 0;
}
