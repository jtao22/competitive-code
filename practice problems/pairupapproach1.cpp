#include <bits/stdc++.h> 
using namespace std;

int main(){
  freopen("pairup.in","r",stdin);
  freopen("pairup.out","w",stdout);
  int x,n,max = 0; cin >> n;
  map<int, int> m;
  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> x >> arr[i];
    m[arr[i]] = x;
  }
  sort(arr,arr+n);
  int maxx = n-1;
  for (int i = 0; i < n; i++){
    if (m[arr[i]] == 0){
      break;
    }
    while (m[arr[i]] > 0){
        for (int j = maxx; j >= i; j--){
          if (m[arr[j]] > 0){
            if (arr[i] + arr[j] >= max){
              max = arr[i]+arr[j];
            }
            m[arr[i]]--;
            m[arr[j]]--;
            break;
          }
          else{
            maxx--;
          }
        }
    }
  }
  cout << max << endl;
}
