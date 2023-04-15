#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3003;
int n;
double p[SIZE],dp[SIZE][SIZE],suma;

int main(){
  cin>>n;
  for(int i = 1; i <= n; i++) cin>>p[i];
  for(int i = 0; i <= n; ++i) dp[i][0] = 1;
  for(int i = 1; i <= n; i++)
    for(int d = 1; d < SIZE-1; d++)
      dp[i][d] = dp[i-1][d]*(1-p[i])+dp[i-1][d-1]*p[i];
  printf("%.10lf\n", dp[n][n/2+1]);
  return 0;
}
