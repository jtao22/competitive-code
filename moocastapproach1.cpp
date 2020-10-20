#include <bits/stdc++.h> 
using namespace std;
struct foo{
  int x;
  int y;
  int power;
};
int cantransmit[200][200];
int c[200];
int main(){
  //freopen("moocast.in","r",stdin);
  //freopen("moocast.out","w",stdout);
  int n,curri; cin >> n;
  foo cow[n];
  for (int i = 0; i < n; i++){
    cin >> cow[i].x >> cow[i].y >> cow[i].power;
  } 
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (pow(cow[j].x-cow[i].x, 2)+pow(cow[j].y - cow[i].y, 2) <= pow(cow[i].power, 2)){
            cantransmit[i][j] = 1;
        }
        if (pow(cow[j].x-cow[i].x, 2)+pow(cow[j].y - cow[i].y, 2) <= pow(cow[j].power, 2)){
          cantransmit[j][i] = 1;
        }
      }
    }
  queue<int> index;
  index.push(0);
  int curr = 1,best = 0;
  c[0] = 1;
  while (true){
    curri = index.front();
    index.pop();
    for (int i = 0; i < n; i++){
      if (i != curri && c[i] == 0 && cantransmit[curri][i] == 1){
          index.push(i);
          c[i] = c[curri]+1;
      }
    }
    if (index.size() == 0){
      if (c[curri] >= best){
        best = c[curri];
      }
      for (int i = 0; i < n; i++){
        c[i] = 0;
      }
      index.push(curr);
      c[curr] = 1;
      curr++;
      if (curr == n){
        break;
      }
    }
  }
  cout << best << endl;
}