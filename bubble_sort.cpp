#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void bubblesort(int arr[], int x){
  int temp;
  for (int j = 0; j < x-1; j++){
  for (int i = 0; i < x-j-1; i++){
    if (arr[i] > arr[i+1]){
      temp = arr[i+1];
      arr[i+1] = arr[i];
      arr[i] = temp;
    }
  }
  }
}
int n;
int main(){
  //freopen("problemname.in","r",stdin);
  //freopen("problemname.out","w",stdout);
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  bubblesort(arr,n);
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
}
