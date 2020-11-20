#include <bits/stdc++.h> 
using namespace std;
map<pair<int,int>,vector<pair<int,int>>>adj;
bool visited[101][101];
bool on[101][101];
int n,tempi,tempj,lighttempi,lighttempj;
int c[4];
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
pair<int,int>pii;
void dfs(int i, int j){
  pii = make_pair(i,j);
  for (int itr = 0; itr < adj[pii].size(); itr++){
    if (!on[adj[pii][itr].first][adj[pii][itr].second]){
    on[adj[pii][itr].first][adj[pii][itr].second] = true;
    c[1]++;
    }
  }
  for (int itr = 0; itr < 4; itr++){
    tempi = i+di[itr];tempj = j+dj[itr];
    if (tempi > 0 && tempi <= n && tempj > 0 && tempj <= n){
      if (!visited[tempi][tempj] && on[tempi][tempj]){
        visited[tempi][tempj] = true;
        c[3]++;
        dfs(tempi,tempj);
      }
    }
  }
}
int main(){
  int q,x1,y1,x2,y2,count=0; cin >> n >> q;
  for (int i = 1; i <= q; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    adj[make_pair(x1,y1)].push_back(make_pair(x2,y2));
  }
  visited[1][1] = true;
  c[1]++;
  c[3]++;
  on[1][1] = true;
  dfs(1,1);
  while (c[0] != c[1] || c[2] != c[3]){
    c[0] = c[1];
    c[2] = c[3];
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (visited[i][j]){
          dfs(i,j);
        }
      }
    }
}
 cout << c[1] << endl;
}