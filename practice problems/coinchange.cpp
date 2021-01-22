#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,x;

int main(){
  cin >> n >> x;
  int val[n];
  int dp[x+1][n];
  for (int i = 0; i < n; i++){
    cin >> val[i];
  }
  for (int i = 0; i <= x; i++){
    for (int j = 0; j < n; j++){
      dp[i][j] = INT_MAX;
    }
    if(i%val[0] == 0){
      dp[i][0] = i/val[0];
    }
  }
  for (int i = 1; i < n; i++){
    for (int j = 0; j <= x; j++){
      if(j-val[i] < 0){
        dp[j][i] = dp[j][i-1];
      }
      else{
        dp[j][i] = min(dp[j-val[i]][i]+1, dp[j][i-1]);
      }
    }
  }
  cout << dp[x][n-1] << endl;
}
