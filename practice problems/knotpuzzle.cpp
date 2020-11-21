#include <bits/stdc++.h> 
using namespace std;

int main(){
  int n,l; cin >> n >> l;
  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  vector<int>v;
  int left = 0, right = n-1;
  int goodleft, goodright;
  bool tf = false;
  for (int i = 1; i < n; i++){
    if (arr[i]+arr[i-1] >= l){
      tf = true;
      goodleft = i-1;
      goodright = i;
      break;
    }
  }
  if (tf){
    while (true){
      if (left != goodleft){
        v.push_back(left+1);
        left++;
      }
      if (right != goodright){
        v.push_back(right);
        right--;
      }
      if (left == goodleft && right == goodright){
        cout << "Possible" << endl;
        for (int i = 0; i < v.size(); i++){
          cout << v[i] << endl;
        }
        cout << goodright << endl;
        break;
      }
    }
  }
  else{
    cout << "Impossible" << endl;
  }
}