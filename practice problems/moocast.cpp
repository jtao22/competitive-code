#include <bits/stdc++.h> 
using namespace std;
int n;
vector<int> adj[200];
bool arr[200][200];
bool arr2[200][200];
int visited[200];
struct walkietalkie{
  int x;
  int y;
  int r;
};
walkietalkie wt[200];
void dfs(int ind){
  int dist;
  for (int i = 0; i < n; i++){
    if (i == ind){continue;}
      dist = (wt[i].x-wt[ind].x)*(wt[i].x-wt[ind].x)+(wt[i].y-wt[ind].y)*(wt[i].y-wt[ind].y);
      if (dist <= wt[ind].r*wt[ind].r){
        visited[ind]++;
        adj[ind].push_back(i);
        arr[ind][i] = true;
      }
  }
}
void floodfill(int init, int ind){
  arr2[init][ind] = true;
  for (int i = 0; i < adj[ind].size(); i++){
      if (!arr2[init][adj[ind][i]]){
      arr2[init][adj[ind][i]] = true;
      if (!arr[init][adj[ind][i]]){
        visited[init]++;
        adj[init].push_back(adj[ind][i]);
      }
      floodfill(init,adj[ind][i]);
      }
  }
  return;
}
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> wt[i].x >> wt[i].y >> wt[i].r;
  }
  for (int i = 0; i < n; i++){
    dfs(i);
  }
  int best = 0;
  for (int i = 0; i < n; i++){
    floodfill(i,i);
  }
  for (int i = 0; i < n; i++){
    best = max(best,visited[i]);
  }
  cout << ++best << endl;
}