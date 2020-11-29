#include <bits/stdc++.h> 
using namespace std;
map<long long,int> dp;
int main(){
  int n; cin >> n;
  int arr[n+1];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int best = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < i; j++){
      if (arr[j] < arr[i]){
        dp[i] = max(dp[i],dp[j]+1);
        best = max(dp[i],best);
      }
    }
  }
  cout << best+1 << endl;
}