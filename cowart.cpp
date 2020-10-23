#include <bits/stdc++.h> 
using namespace std;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int main(){
  int n,itemp,jtemp,itemp2,jtemp2,hcount = 1,ccount =1; cin >> n; char c; bool found;
  int arr[n][n];
  int cow[n][n];
  int human[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c;
      if (c == 'R'){
        arr[i][j] = 0;
      }
      else if (c == 'G'){
        arr[i][j] = 2;
      }
      else{
        arr[i][j] = 1;
      }
      cow[i][j] = 0;
      human[i][j] = 0;
    }
  }
  queue <int> qi;queue<int>qj;
  qi.push(0);qj.push(0);
  while (qi.size() > 0){
    itemp = qi.front(); jtemp = qj.front();
    qi.pop();qj.pop();
    cow[itemp][jtemp] = ccount;
    for (int itr = 0; itr < 4; itr++){
      itemp2 = itemp + di[itr]; jtemp2 = jtemp+dj[itr];
      if (itemp2 >= 0 && jtemp2 >= 0 && itemp2 < n && jtemp2 < n){
        if (cow[itemp2][jtemp2] == 0 && arr[itemp2][jtemp2]%2 == arr[itemp][jtemp]%2){
          cow[itemp2][jtemp2] = ccount;
          qi.push(itemp2);qj.push(jtemp2);
        }
      }
    }
    if (qi.size() == 0){
      found = false;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          if (cow[i][j] == 0){
            found = true;
            ccount++;
            qi.push(i);qj.push(j);
            break;
          }
        }
        if (found){
          break;
        }
      }
    }
  }
  qi.push(0);qj.push(0);
    while (qi.size() > 0){
    itemp = qi.front(); jtemp = qj.front();
    qi.pop();qj.pop();
    human[itemp][jtemp] = 1;
    for (int itr = 0; itr < 4; itr++){
      itemp2 = itemp + di[itr]; jtemp2 = jtemp+dj[itr];
      if (itemp2 >= 0 && jtemp2 >= 0 && itemp2 < n && jtemp2 < n){
        if (human[itemp2][jtemp2] == 0 && arr[itemp2][jtemp2] == arr[itemp][jtemp]){
          human[itemp2][jtemp2] = 1;
          qi.push(itemp2);qj.push(jtemp2);
        }
      }
    }
    if (qi.size() == 0){
      found = false;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          if (human[i][j] == 0){
            found = true;
            hcount++;
            qi.push(i);qj.push(j);
            break;
          }
        }
        if (found){
          break;
        }
      }
    }
  }
  cout << hcount << " " << ccount << endl;
}