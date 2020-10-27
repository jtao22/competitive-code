#include <bits/stdc++.h> 
using namespace std;
struct daycost{
  int num;
  int cost;
};
int main(){
  int n; cin >> n;
  daycost arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i].num >> arr[i].cost;
  }
  int temptotal,currcost,total = 0;
  for (int i = 0; i < n; i++){
    temptotal = arr[i].num;
    currcost = arr[i].cost;
    while (true){
      if (arr[i+1].cost >= currcost && i+1 < n){
        temptotal+=arr[i+1].num;
        i++;
      }
      else{
        total+=currcost*temptotal;
        break;
      }
    }
  }
  cout << total << endl;
}
