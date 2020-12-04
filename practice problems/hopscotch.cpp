#include <bits/stdc++.h>
using namespace std;
long long path[100][100];
int main(){
  queue<pair<int,int>>q;
  int r,c,k; cin >> r >> c >> k;
  int arr[r][c];
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> arr[i][j];
    }
  }
  long val = 1000000007;
  path[0][0] = 1;
  int tempi = 0, tempj = 0;
  for (int i = 1; i < r; i++){
    for (int j = 1; j < c; j++){
      for (int x = tempi+1; x < r-1; x++){
        for (int y = tempj+1; y < c-1; y++){
          if (arr[x][y] != arr[tempi][tempj]){
            path[x][y]+=path[tempi][tempj];
          }
          if (path[x][y] > val){
            path[x][y]%=val;
          }
        }
      }
      if (arr[r-1][c-1] != arr[tempi][tempj]){
        path[r-1][c-1]+=path[tempi][tempj];
      }
      if (path[r-1][c-1] > val){
            path[r-1][c-1]%=val;
          }
      tempi = i;
      tempj = j;
    }
  }
  cout << path[r-1][c-1]%val;
}