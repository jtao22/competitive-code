#include <bits/stdc++.h> 
using namespace std;
bool binarysearch(int arr[], int q, int left, int right){
  if (right >= left){
    int mid = (right+left)/2;
    if (arr[mid] == q){
      return true;
    }
    else{
      if ( arr[mid] < q){
        return binarysearch(arr,q,mid+1,right);
      }
        return binarysearch(arr,q,left,mid-1);
    }
  }
  return false;
}
int main(){
  //freopen("problem.in","r",stdin);
  //freopen("problem.out","w",stdout);
  int n,q;
  int x; int arr[n]; cin >> n >> q;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr,arr+n);
  int min = arr[0], max = arr[n-1];
  for (int i = 0; i < q; i++){
    cin >> x;
    if (x < min || x > max){
      cout << "NO" << endl;
    }
    else{
    if (binarysearch(arr,x,0,n-1)){cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
    }
  }
}