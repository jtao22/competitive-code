#include <bits/stdc++.h> 
using namespace std;
int dp[4005];
int main(){
  int n; int l[3]; cin >> n;
  for (int i = 0; i < 3; i++){
    cin >> l[i];
    dp[l[i]] = 1;
  }
  sort(l,l+3);
  for (int i = 0; i <= n; i++){
    if (dp[i] > 0){
    for (int j = 0; j < 3; j++){
      if (i+l[j] <= n){
        dp[i+l[j]] = max(dp[i+l[j]],dp[i]+1);
      }
    }
    }
  }

  cout << dp[n] << endl;
}