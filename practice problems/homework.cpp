#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;

int main(){
  freopen("homework.in","r",stdin);
  freopen("homework.out","w",stdout);
  cin >> n;
  ll arr[n];
  ll min[n];
  ll sum[n];
  
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  min[n-1] = arr[n-1];
  sum[n-1] = arr[n-1];
  for (int i = n-2; i >= 0; i--){
    if (arr[i] <= min[i+1]){
      min[i] = arr[i];
    }
    else{
      min[i] = min[i+1];
    }
    sum[i] = sum[i+1]+arr[i];
  }
  ll maxsum = 0, maxsumnum = 1;
  for (int i = 1; i <= n-2; i++){
    if ((sum[i]-min[i])*maxsumnum > maxsum * (n-i-1)){
      maxsumnum = n-i-1;
      maxsum = sum[i]-min[i];
    }
  }
  for (int i = 1; i <= n-2; i++){
    if ((sum[i]-min[i])*maxsumnum == maxsum * (n-i-1)){
      cout << i << endl;
    }
  }
  return 0;
}