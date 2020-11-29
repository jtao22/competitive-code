#include <bits/stdc++.h> 
using namespace std;
bool reach[201][201];
bool temp[201][201];

int main(){
  int x,y,k,m; cin >> x >> y >> k >> m;
  reach[0][0] = true;
  for (int o = 0; o < k; o++){
  for (int i = 0; i <= x; i++){
    for (int j = 0; j <= y; j++){
      if (reach[i][j]){
        temp[i][j] = true;
        temp[0][j] = true;
        temp[i][0] = true;
        temp[x][j] = true;
        temp[i][y] = true;
        temp[i-min(i,y-j)][j+min(i,y-j)] = true;
        temp[i+min(x-i,j)][j-min(x-i,j)] = true;
      }
    }
  }
  for (int tempi = 0; tempi <= x; tempi++){
    for (int tempj = 0; tempj <= y; tempj++){
      reach[tempi][tempj] = temp[tempi][tempj];
      temp[tempi][tempj] = false;
    }
  }
  }
  int best = m;
  for (int i = 0; i <= x; i++){
    for (int j = 0; j <= y; j++){
      if (reach[i][j]){
        best = min(best,abs(i+j-m));
      }
    }
  }
  cout << best << endl;
}