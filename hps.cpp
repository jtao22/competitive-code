#include <bits/stdc++.h> 
using namespace std;
pair<int,int> arr[100000][4];
int main(){
  freopen("hps.in","r",stdin);
  freopen("hps.out","w",stdout);
  int n; cin >> n;
  char str[n];
  for (int i = 0; i < n; i++){
    cin >> str[i];
  }
  if (str[0] == 'H'){
    arr[0][0].first = 1;
  }
  else if (str[0] == 'P'){
    arr[0][1].first = 1;
  }
  else{
    arr[0][2].first = 1;
  }
  if (str[n-1] == 'H'){
    arr[n-1][0].second = 1;
  }
  else if (str[n-1] == 'P'){
    arr[n-1][1].second = 1;
  }  
  else{
    arr[n-1][2].second = 1;
  }
  for (int i = 1; i < n; i++){
    if (str[i] == 'H'){
      arr[i][0].first = arr[i-1][0].first+1;
      arr[i][1].first = arr[i-1][1].first;
      arr[i][2].first = arr[i-1][2].first;
    }
    else if (str[i] == 'P'){
      arr[i][1].first = arr[i-1][1].first+1;
      arr[i][0].first = arr[i-1][0].first;
      arr[i][2].first = arr[i-1][2].first;
    }
    else{
      arr[i][2].first = arr[i-1][2].first+1;
      arr[i][0].first = arr[i-1][0].first;
      arr[i][1].first = arr[i-1][1].first;
    }
  }
  for (int i = n-2; i >= 0; i--){
    if (str[i] == 'H'){
      arr[i][0].second = arr[i+1][0].second+1;
      arr[i][1].second = arr[i+1][1].second;
      arr[i][2].second = arr[i+1][2].second;
    }
    else if (str[i] == 'P'){
      arr[i][1].second = arr[i+1][1].second+1;
      arr[i][0].second = arr[i+1][0].second;
      arr[i][2].second = arr[i+1][2].second;
    }
    else{
      arr[i][2].second = arr[i+1][2].second+1;
      arr[i][0].second = arr[i+1][0].second;
      arr[i][1].second = arr[i+1][1].second;
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 3; j++){
      if (arr[i][j].first >= arr[i][3].first){
        arr[i][3].first = arr[i][j].first;
      }
      if (arr[i][j].second >= arr[i][3].second){
        arr[i][3].second = arr[i][j].second;
      }
    }
  }
  int best = 0;
  for (int i = 0; i < n; i++){
    int foo = arr[i][3].first + arr[i][3].second;
    if (foo >= best){
      best = foo;
    }
  }
  cout << best << endl;
}
