#include <bits/stdc++.h> 
using namespace std;
int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};
long ind[1000000];
char c;
long mark[1001][1001];
queue <int> qi;queue <int> qj;
vector<int>wi;vector<int>wj;
int main(){
  int h,w,q,bh,bw,itemp,jtemp,itemp2,jtemp2,count = 0,currindex = 1,save = 0; cin >> h >> w >> q;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> c;
      if (c == '*'){
        mark[i][j] = -1;
      }
      else{
        mark[i][j] = 0;
        wi.push_back(i);wj.push_back(j);
        if (qi.size() ==0){
          qi.push(i);qj.push(j);
        }
      }
    }
  }    
    while (qi.size() > 0){
      itemp = qi.front();jtemp=qj.front();
      qi.pop();qj.pop();
      mark[itemp][jtemp] = currindex; 
      ind[currindex]+= 4;
      for (int itr = 0; itr < 4; itr++){
        itemp2 = itemp+di[itr];
        jtemp2 = jtemp+dj[itr];
        if (itemp2>= 0 && itemp2 < h && jtemp2 >= 0 && jtemp2 < w){
          if (mark[itemp2][jtemp2] != -1){
            ind[currindex]--;
            if (mark[itemp2][jtemp2] == 0){
              qi.push(itemp2); qj.push(jtemp2);
              mark[itemp2][jtemp2] = currindex;
            }
          }
        }
      }
      if (qi.size() == 0){
        for (int i = save; i < wi.size(); i++){
          if (mark[wi[i]][wj[i]] == 0){
              save = i;
              qi.push(wi[i]);qj.push(wj[i]);
              currindex++;
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
