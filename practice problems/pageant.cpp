#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
queue<pii>q;
queue<pii>q1;
queue<pii>q2;
int n,m,curri,currj,tempi,tempj,val = 1, itr = 0; char c; bool found;
int lengths[3];

int main(){
  freopen("pageant.in","r",stdin);
  freopen("pageant.out","w",stdout);
  cin >> n >> m;
  int spot[n][m];
  int visited[n][m];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      visited[i][j] = 0;
      cin >> c;
      if (c == '.'){
        spot[i][j] = -1;
      }
      else{
        if (q.empty()){
          q.push(make_pair(i,j));
          q1.push(make_pair(i,j));
          visited[i][j] = val;
        }
        spot[i][j] = 0;
      }
    }
  }
  while(!q.empty()){
    curri = q.front().first;
    currj = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++){
      tempi = curri+di[i];
      tempj = currj+dj[i];
      if (tempi >= 0 && tempi < n && tempj >= 0 && tempj < m && spot[tempi][tempj] == 0 && visited[tempi][tempj] == 0){
        q.push(make_pair(tempi,tempj));
        if (val == 1){
          q1.push(make_pair(tempi,tempj));
        }
        else if (val == 2){
          q2.push(make_pair(tempi,tempj));
        }
        visited[tempi][tempj] = val;
      }
    }
    if(q.empty()){
      found = false;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
          if (spot[i][j] == 0&& visited[i][j] == 0){
            found = true;
            visited[i][j] = ++val;
            q.push(make_pair(i,j));
            break;
          }
        }
        if (found){
          break;
        }
      }
    }
  }
  bool found12 = false, found13 = false; found = false;
  int count = 0;
  while (!found12 || !found13){
    curri = q1.front().first; 
    currj = q1.front().second;
    q1.pop();
    for (int i = 0; i < 4; i++){
      tempi = curri+di[i];
      tempj = currj+dj[i];
      if (tempi >= 0 && tempi < n && tempj >= 0 && tempj < m ){
        if (spot[tempi][tempj] == -1){
          q1.push(make_pair(tempi,tempj));
          spot[tempi][tempj] = spot[curri][currj]+1;
        }
        else{
          if (visited[tempi][tempj] == 2 && !found12){
            lengths[itr] = spot[curri][currj];itr++;
            found12 = true;
          }
          else if (visited[tempi][tempj] == 3 && !found13){
            lengths[itr] = spot[curri][currj]; itr++;
            found13 = true;
          }
        }
      }
    }
  }
  while(!found){
    curri = q2.front().first;
    currj = q2.front().second;
    q2.pop();
    for (int i = 0; i < 4; i++){
      tempi = curri+di[i];
      tempj = currj+dj[i];
      if (tempi >= 0 && tempi < n && tempj >= 0 && tempj < m ){
        if (visited[tempi][tempj] == 0){
          q2.push(make_pair(tempi,tempj));
          visited[tempi][tempj] = visited[curri][currj]+1;
        }
        else{
          if (spot[tempi][tempj] == 0 && visited[tempi][tempj] == 3){
            lengths[itr] = visited[curri][currj]-2;
            found = true;
          }
        }
      }
    }
  }
  sort(lengths,lengths+3);
  count+=lengths[0] + lengths[1];
  cout << count << endl;
}