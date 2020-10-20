#include <bits/stdc++.h> 
using namespace std;

int main(){
  int n,q,a,b,sum=0; cin >> n >> q;
  int arr[n+1];
  arr[0] = 0;
  for (int i = 1; i <= n; i++){
    cin >> a;
    sum+=a;
    arr[i] = sum;
  }

  for (int i = 0; i < q; i++){
    cin >> a >> b;
    cout << arr[b]-arr[a-1] << endl;
  }
}