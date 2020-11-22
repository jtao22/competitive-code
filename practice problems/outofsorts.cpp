#include <bits/stdc++.h> 
using namespace std;
struct arrs{
  int val;
  int pos;
};
bool comp(arrs a, arrs b){
  if (a.val != b.val){
  return a.val < b.val;}
  return a.pos < b.pos;
}
int main(){
  int n,count =0;cin >> n;
  arrs arr[n]; 
  for (int i = 0; i < n; i++){
    cin >> arr[i].val;
    arr[i].pos = i;
  }
  sort(arr,arr+n,comp);
  for (int i = 0; i < n; i++){
    count = max(count, arr[i].pos-i);
  }
  cout << ++count << endl;
}