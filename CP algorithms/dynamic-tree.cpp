//Dynamiczne drzewo przedzialowe typu przedzial-przedzial przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE = 1e6, N = (1<<20);
class tree{
	class node{
		public:
		node *l, *r; ll s, t; int cnt;};
	node pool[SIZE];
	int A, B, ind; ll C;
	void makeChildren(node *u, int low, int high){
		if (!u->l) u->l=pool+(++ind), u->l->cnt=(high-low+1)/2;
		if (!u->r) u->r=pool+(++ind), u->r->cnt=(high-low+1)/2;;
	}
	void lazy(node *u, int low, int high){
		(u->s) += (u->t) * (high-low+1);
		if (low!=high) makeChildren(u, low, high), u->l->t+=u->t, u->r->t+=u->t;
		u->t=0;
	}
	void upd(node *u, int low=0, int high=N-1){
		lazy(u, low, high);
		if (low>B || high<A) return;
		if (A<=low && high<=B){ u->t+=C, lazy(u, low, high); return;}
		upd(u->l, low, (low+high)/2);
		upd(u->r, (low+high)/2+1, high);
		u->s = (u->l->s)+((u->l->t)*(high-low+1)/2) + (u->r->s)+((u->l->t)*(high-low+1)/2);
	}
	ll query(node *u, int low=0, int high=N-1){
		lazy(u, low, high);
		if (low>B || high<A) return 0;
		if (A<=low && high<=B) return u->s;
		ll L=query(u->l, low, (low+high)/2);
		ll R=query(u->r, (low+high)/2+1, high);
		return L+R;
	}
	public:
	void setup(){ pool->cnt=N;}
	void update(int a, int b, ll c){ A=a, B=b, C=c, upd(pool);}
	ll ask(int a, int b){ A=a, B=b; return query(pool);}
}T;

int main(){
	T.setup(); int q; cin>>q;
  for(int i = 0; i < q; i++){
    int o,a,b; cin>>o>>a>>b;
    if(o == 0){ll c; cin>>c; T.update(a,b,c);}
    if(o == 1){cout<<T.ask(a,b)<<"\n";}
  }
	return 0;
}
