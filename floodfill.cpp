
#include <bits/stdc++.h> 
using namespace std;
int n,m;
string arr[101];
bool mark[101][101];

void floodfill(int i, int j){
  if (i < 0 || i >= n || j < 0 || j >= m || mark[i][j] || arr[i][j] == '*'){
    return;
  }
  mark[i][j] = true;
  floodfill(i+1,j);
  floodfill(i-1,j);
  floodfill(i,j+1);
  floodfill(i,j-1);
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (arr[i][j] == 'S'){
        floodfill(i,j);
      }
    }
  }
}
