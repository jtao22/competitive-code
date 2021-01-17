#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,x,y,tempx,tempy;
int mindist[1002][1002];
int ishay[1002][1002];
queue<pii>q0;
queue<pii>q1;

int main(){
  //freopen("tractor.in","r",stdin);
  //freopen("tractor.out","w",stdout);
  cin >> n >> x >> y;
  mindist[x][y] = 1;
  q0.push(make_pair(x,y));
  for (int i = 0; i < n; i++){
    cin >> x >> y;
    ishay[x][y] = 1;
  }
  while(!q0.empty() || !q1.empty()){
    x = q0.front().first; y = q0.front().second;
    q0.pop();
    if(q0.empty()){
      while(!q1.empty()){
        q0.push(q1.front()); q1.pop();
      }
    }
    for(int i = 0; i < 4; i++){
      tempx = x+di[i]; tempy = y+dj[i];
      if(tempx >= 0 && tempx < 1002 && tempy >= 0 && tempy < 1002){
        if(mindist[tempx][tempy] == 0 || mindist[x][y]+ishay[tempx][tempy] < mindist[tempx][tempy]){
          mindist[tempx][tempy] = mindist[x][y]+ishay[tempx][tempy];
          if(ishay[tempx][tempy] == 0){q0.push(make_pair(tempx,tempy));}
          else{q1.push(make_pair(tempx,tempy));}
        }
      }
    }
  }
  cout << --mindist[0][0] << endl;
}
