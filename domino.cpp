#include <bits/stdc++.h> 
using namespace std;

int main(){
  int h,w,q,x1,x2,y1,y2,count = 0; cin >> h >> w;
  char arr[h+2][w+2];
  int psum[h+2][w+2];
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      cin >> arr[i][j];psum[i][j] = 0;
    }
  }
  for (int i = 0; i <= h+1; i++){
    psum[i][0] = 0; psum[i][w+1] = 0;
    arr[i][0] = '#';arr[i][w+1] = '#'; 
  }
  for (int i = 0; i <= w+1; i++){
    psum[0][i] = 0;psum[h+1][i] = 0;
    arr[0][i] = '#';arr[h+1][i] = '#';
  }
  for (int i = 2; i <= h; i++){
    if (arr[i][1] == '.' && arr[i-1][1] == '.'){
      count++;
    }
    psum[i][1] = count;
  }
  count = 0;
  for (int i = 2; i <= w; i++){
    if (arr[1][i] == '.' && arr[1][i-1] == '.'){
      count++;
    }
    psum[1][i] = count;
  }
  for (int i = 2; i <= h; i++){
    for (int j = 2; j <= w; j++){
      psum[i][j] = psum[i-1][j] + psum[i][j-1]-psum[i-1][j-1];
      if (arr[i][j] == '.'){
        if (arr[i-1][j] == '.'){
          psum[i][j]++;
        }
        if (arr[i][j-1] == '.'){
          psum[i][j]++;
        }
      }
    }
  }
  cin >> q; int ans;
  for (int i = 0; i < q; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    ans = psum[x2][y2]-psum[x1-1][y2]-psum[x2][y1-1]+psum[x1-1][y1-1];
      for (int a = y1; a <= y2; a++){
        if (arr[x1-1][a] == '.' && arr[x1][a] == '.'){
          ans--;
        }
      }
      for (int a = x1; a <= x2; a++){
        if (arr[a][y1-1] == '.' && arr[a][y1] == '.'){
          ans--;
        }
      }
    cout << ans << endl;
  }
}