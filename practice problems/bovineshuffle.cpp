#include <bits/stdc++.h> 
using namespace std;
bool has[100001];
int val[100001];
int main(){
  int n; cin >> n;
  int arr[n+1];
  for (int i = 1; i <=  n; i++){
    cin >> arr[i];has[i] = true;
    val[i] = 1;
  }
  int prevcount = 0, count = n;
  while (prevcount != count){
    prevcount = count;

    for (int i = 1; i <= n; i++){
      if (val[i] > 0){
        val[i]--; val[arr[i]]++;
      }
    }
    for (int i = 1; i <= n; i++){
      if (val[i] == 0 && has[i]){
        has[i] = false;
        count--;
      }
      else if(val[i] > 1){
        val[i] = 1;
      }
    }
  }
  cout << count << endl;
}