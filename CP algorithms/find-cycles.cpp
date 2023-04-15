//algorytm znajdujacy cykle w grafie, przygotowala: Agata Pokorska
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> graph[N];
vector<int> cycles[N];
void dfs_cycle(int u, int p, int color[], int mark[], int par[], int& cyclenumber){
	if (color[u] == 2) return; //juz kompletnie odwiedzony
	if (color[u] == 1){//wierzcholek byl juz odwiedzony ale nie calkowicie -> jest cykl
		cyclenumber++;
		int cur = p;
		mark[cur] = cyclenumber;
		while (cur != u) cur = par[cur], mark[cur] = cyclenumber;//backtrack po rodzicach
    //dopoki nie dotrzemy ponownie do tego samego wierzcholka
		return;
	}
	par[u] = p;
	color[u] = 1;//czesciowo odwiedzony - chcemy tu jeszcze wrocic
	for (int v : graph[u]){
		if (v == par[u]) continue;//nie chcemy odwiedzac ponownie rodzica wierzcholka u
		dfs_cycle(v, u, color, mark, par, cyclenumber);
	}
	color[u] = 2;//calkowicie odwiedzony, nie chcemy juz nic w nim robic
}
void addEdge(int u, int v){graph[u].push_back(v), graph[v].push_back(u);}
void printCycles(int edges, int mark[], int& cyclenumber){
	for (int i = 1; i <= edges; i++)
		if (mark[i] != 0) cycles[mark[i]].push_back(i);
	for (int i = 1; i <= cyclenumber; i++){
    //wypisuje wszystkie wierzcholki nalezace do tego samego cyklu
    if(cycles[i].size() > 0){
  		cout<<"Cykl "<<i<<": ";
  		for(int x : cycles[i]) cout<<x<<" ";
      cout<<endl;
    }
	}
}
int main(){
  int n,m;
  cin>>n>>m;
  for(int i = 0; i < m; i++){int a,b; cin>>a>>b; addEdge(a,b);addEdge(b,a);}
	int color[N];
	int par[N];//przechowuje numer wierzcholka ktory jest rodzicem wierzcholka i
	int mark[N];//zaznacza wierzcholki unikalnym kolorem dla kazdego cyklu
	int cyclenumber = 0;//przechowuje ile jest roznych cykli
	int edges = m;
	dfs_cycle(1, 0, color, mark, par, cyclenumber);//DFS ktory zaznacza cykle na jeden kolor
	printCycles(edges, mark, cyclenumber);//wypisuje wszystkie cykle
	return 0;
}
