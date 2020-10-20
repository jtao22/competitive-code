#include <bits/stdc++.h> 
using namespace std;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int main(){
  int h,w,itemp,jtemp,itemp2,jtemp2; cin >> h >> w;
  char arr[h][w];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> arr[i][j];
      if (arr[i][j] == 'S'){
        itemp = i;jtemp = j;
      }
    }
  }
  queue <int> iq;
  queue <int> jq;
  iq.push(itemp);
  jq.push(jtemp);
  arr[itemp][jtemp] = '!';
  while (iq.size() > 0){
    itemp = iq.front();jtemp = jq.front();
    iq.pop();jq.pop();
    for (int itr = 0; itr < 4; itr++){
      itemp2 = itemp+di[itr];
      jtemp2 = jtemp+dj[itr];
      if (itemp2 >= 0 && itemp2 < h && jtemp2 >= 0 && jtemp2 < w){
        if (arr[itemp2][jtemp2] == '.'){
          arr[itemp2][jtemp2] = '!';
          iq.push(itemp2);
          jq.push(jtemp2);
        }
      }
    }
  }
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << arr[i][j];
    }
    cout << "" << endl;
  }
}