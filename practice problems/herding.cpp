#include <bits/stdc++.h> 
using namespace std;

int main(){
  //freopen("herding.in","r",stdin);
  //freopen("herding.out","w",stdout);
  int n; cin >> n;
  int arr[n];
  int temp[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
    temp[i] = arr[i];
  }
  sort(arr,arr+n);
  sort(temp,temp+n);
  int count = 0;
  while (true){
    if (arr[n-1]-arr[0] == n-1){
      break;
    }
    for (int i = 1; i < n-1; i++){
      if (arr[i+1]-arr[i] > 1){
        arr[0] = arr[i+1]-1;
        break;
      }
    }
    for (int i = 0; i <n; i++){
      cout << arr[i] << endl;
    }
    cout << "" << endl;
    sort(arr,arr+n);
    count++;
  }
  int count2 = 0;
  while (true){
    if (temp[n-1]-temp[0] == n-1){
      break;
    }
    for (int i = n-2; i > 0; i--){
      if (temp[i]-temp[i-1] > 1){
        temp[n-1] = temp[i]-1;
        break;
      }
    }
    sort(temp,temp+n);
    count2++;
  }
  cout << min(count,count2) << " " << max(count,count2) << endl;
}
