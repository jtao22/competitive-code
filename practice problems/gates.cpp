#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
bool field[2005][2005];
int n;
map<char,pii>direction;
int main(){
  freopen("gates.in","r",stdin);
  freopen("gates.out","w",stdout);
  int curri = 1002,currj = 1002; char c;
  cin >> n;
  direction['N'] = {-1,0};
  direction['S'] = {1,0};
  direction['W'] = {0,-1};
  direction['E'] = {0,1};
  field[curri][currj] = true;
  for (int i = 0; i < n; i++){
    cin >> c;
    curri+=direction[c].first;
    currj+=direction[c].second;
    field[curri][currj] = true;
    curri+=direction[c].first;
    currj+=direction[c].second;   
    field[curri][currj] = true;
  }
  queue<pii>q;

  int count = 0;
  for(int i = 0; i < 2005; i++){
    for (int j = 0; j < 2005; j++){
      if(!field[i][j]){
        field[i][j] = true;
        count++;
        q.push({i,j});
        while(!q.empty()){
          curri = q.front().first; currj = q.front().second;
          q.pop();
          for (int itr = 0; itr < 4; itr++){
            int tempi = curri+di[itr];
            int tempj = currj+dj[itr];
            if(tempi >= 0 && tempi < 2005 && tempj >= 0 && tempj < 2005 && !field[tempi][tempj]){
              field[tempi][tempj] = true;
                q.push({tempi,tempj});
            }
          }
        }
      }
    }
  }
  cout << count-1 << endl;
}
