#include <bits/stdc++.h> 
using namespace std;
int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};
int ind[30000];
queue <int> qi;queue <int> qj;
int main(){
  int h,w,q,bh,bw,itemp,jtemp,itemp2,jtemp2,indcount,count =0,currindex = 1; cin >> h >> w >> q; bool found = false;
  char arr[h][w];
  int mark[h][w];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> arr[i][j];
      mark[i][j] = 0;
      if (!found){
        if (arr[i][j] == '.'){
          found = true;qi.push(i);qj.push(j);
        }
      }
    }
  }    
    while (qi.size() > 0){
      itemp = qi.front();jtemp=qj.front();
      qi.pop();qj.pop();
      mark[itemp][jtemp] = currindex; 
      indcount = 4;
      for (int itr = 0; itr < 4; itr++){
        itemp2 = itemp+di[itr];
        jtemp2 = jtemp+dj[itr];
        if (itemp2>= 0 && itemp2 < h && jtemp2 >= 0 && jtemp2 < w){
          if (arr[itemp2][jtemp2] == '.'){
            indcount--;
            if (mark[itemp2][jtemp2] == 0){
              qi.push(itemp2); qj.push(jtemp2);
              mark[itemp2][jtemp2] = currindex;
            }
          }
        }
      }
      ind[currindex]+=indcount;
      if (qi.size() == 0){
        found = false;
        for (int i = 0; i < h; i++){
          for (int j = 0; j < w; j++){
            if (arr[i][j] == '.' && mark[i][j] == 0){
              qi.push(i);qj.push(j);
              currindex++;
              found = true;
              break;
            }
          }
          if (found){
            break;
          }
        }
      }
    }
    for (int i = 0; i < q; i++){
      cin >> bh >> bw;
      cout << ind[mark[bh-1][bw-1]] << endl;
    }
}
