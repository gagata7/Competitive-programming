//rozszerzony alg euklidesa
//sluzy do znajdywania rozwiazan rownan typu ax + bx = c
//UWAGA liczby a i b muszą być względnie pierwsze
//UWAGA2 rozwiazanie rownania istnieje tylko gdy c >= NWD(a,b)
#include <bits/stdc++.h>
using namespace std;

int a,b,c,pom2;

int nwd(int x, int y){
	if(x%y == 0) return y;
	return nwd(y,x%y);
}

pair<int,int> f(int A, int B){
	int x = 0, y = 0;
	// cerr<<"A = "<<A<<" B = "<<B<<" C = "<<C<<endl;
	if(B == 0) return {pom2,0};
	pair<int,int> pom = f(B,A%B);
	x = pom.second, y = pom.first - (A/B)*pom.second;
	// cerr<<"zwracam pare x = "<<x<<" i y = "<<y<<endl;
	return {x,y};
}

int main(){
	cout<<"podaj a i b"<<endl;
	cin>>a>>b;
	pom2 = nwd(a,b);
	pair<int,int>	wynik = f(a,b);
	cout<<wynik.first<<" "<<wynik.second<<endl;
	return 0;
}
