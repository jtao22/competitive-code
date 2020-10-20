#include <bits/stdc++.h> 
using namespace std;
int mark[500][500];
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int main(){
  int h,w,q,r1,c1,r2,c2,count = 0,itemp,jtemp,itempd,jtempd; cin >> h >> w;
  bool foundfirst = false;
  char arr[h][w];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> arr[i][j];
      if (arr[i][j] == '#'){
        mark[i][j] = -1;
      }
    }
  }
  cin >> q; 
  queue <int> icoord;
  queue <int> jcoord;
    cin >> r1 >> c1 >> r2 >> c2;r1--;c1--;
    count = 0;

    foundfirst = false;
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        if (arr[i][j] == '.'){
          icoord.push(i);
          jcoord.push(j);
          foundfirst = true;
          break;
        }
      }
      if (foundfirst){
        break;
      }
    }

    while (icoord.size() > 0 && jcoord.size() > 0){
      itemp = icoord.front();
      jtemp = jcoord.front();
      icoord.pop();
      jcoord.pop();
      if (mark[itemp][jtemp] == 0){
        mark[itemp][jtemp] = 1;
        for (int loop = 0; loop < 4; loop++){
          itempd = itemp+di[loop];
          jtempd = jtemp+dj[loop];

          if (itempd >= r1 && jtempd >= c1 && itempd < r2 && jtempd < c2){
            if (arr[itempd][jtempd] == '.' && mark[itempd][jtempd] == 0){
              count++;
              //mark[itempd][jtempd] = -2;  
              icoord.push(itempd);
              jcoord.push(jtempd);
            }
            /*       
            for (int i = r1; i < r2; i++){
              for (int j = c1; j < c2; j++){
                cout << mark[i][j] << " ";
              }
              cout << "" << endl;
            }
            cout << count << endl;
            cout << "" << endl;
          if (mark[itempd][jtempd] == -2){
            mark[itempd][jtempd] = 0;
          }
          */
          }
        }
      }
      if (icoord.size() == 0 && jcoord.size() == 0){
        foundfirst = false;
        for (int i = 0; i < h; i++){
          for (int j = 0; j < w; j++){
            if (arr[i][j] == '.' && mark[i][j] == 0){
              icoord.push(i);
              jcoord.push(j);
              foundfirst = true;
              break;
            }
          }
          if (foundfirst){
            break;
          }
        }
      }
    }

    cout << count << endl;
  
}