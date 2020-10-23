#include <bits/stdc++.h> 
using namespace std;
int arr[100001];
int main(){
  int n,k,b,prev=1,count=0; cin >> n >> k >> b;
  int best = n;
  int broke[b];
  for (int i = 0; i < b; i++){
    cin >> broke[i];
  }
  sort(broke,broke+b);
  for (int i = 0; i < b; i++){
    for (int j = prev; j <broke[i]; j++){
      arr[j] = count;
    }
    count++;
    prev = broke[i];
  }
  for (int i = prev; i <= n; i++){
    arr[i] = count;
  }
  for (int i = 1; i <= n-k; i++){
    best = min(best,arr[i+k]-arr[i]);
  }
  cout << best << endl;
}
