#include <bits/stdc++.h> 
using namespace std;
int fence[1500][1500];
int main(){
  //freopen("gates.in","r",stdin);
  //freopen("gates.out","w",stdout);
  int n,x = 750,y = 750,count = 0; cin >> n;
  char inp;
  fence[750][750] = 2;
  for (int i = 0; i < n; i++){
    cin >> inp;
    if (inp == 'N'){
      y--;
    }
    else if (inp == 'S'){
      y++;
    }
    else if (inp == 'W'){
      x--;
    }
    else{
      x++;
    }
    if (fence[y][x] == 0){
      fence[y][x]++;
    }
    else{
      count++;
    }
  }
  for (int i = 750-n; i < 750+n; i++){
    for (int j = 750-n; j < 750+n; j++){
      cout << fence[i][j] << " ";
    }
    cout << "" << endl;
  }
  cout << count << endl;
}