#include <bits/stdc++.h> 
using namespace std;
int n,m;
  int spotty[500][500];
  int plain[500][500];
  bool triplet[4][4][4];
bool checktriplet(int i, int j, int k){
  for (int itr = 0; itr < n; itr++){
    triplet[spotty[itr][i]][spotty[itr][j]][spotty[itr][k]] = true;
  }
  bool tf = true;
  for (int itr = 0; itr < n; itr++){
    if (triplet[plain[itr][i]][plain[itr][j]][plain[itr][k]]){
      tf = false;
      break;
    }
  }
      for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
          for (int z = 0; z < 4; z++){
            triplet[x][y][z] = false;
          }
        }
      }
  return tf;
}
int main(){
  cin >> n >>  m; string s; int count = 0;
  for (int i = 0; i < n; i++){
    cin >> s;
    for (int j = 0; j < s.length(); j++){
      if (s[j] == 'A'){spotty[i][j] = 0;}
      else if (s[j] == 'C'){spotty[i][j] = 1;}
      else if (s[j] == 'G'){spotty[i][j] = 2;}
      else {spotty[i][j] = 3;}
    }
  }
  for (int i = 0; i < n; i++){
    cin >> s;
    for (int j = 0; j < m; j++){
      if (s[j] == 'A'){plain[i][j] = 0;}
      else if (s[j] == 'C'){plain[i][j] = 1;}
      else if (s[j] == 'G'){plain[i][j] = 2;}
      else {plain[i][j] = 3;}
    }
  }
  for (int i = 0; i < m; i++){
    for (int j = i+1; j < m; j++){
      for (int k = j+1; k < m; k++){
        if (checktriplet(i,j,k)){count++;}
      }
    }
  }
  cout <<  count << endl;
}