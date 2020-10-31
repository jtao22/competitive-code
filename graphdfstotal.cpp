#include <bits/stdc++.h> 
using namespace std;
bool visited[100001];
vector <int> adj[100001];
int ans = 1;
void dfs (int node,int count){
  visited[node] = true;
  for (int i = 0; i < adj[node].size(); i++){
    if(!visited[adj[node][i]]){
      ans++;
      dfs(adj[node][i],count+1);
    }
  }
}
int main(){
  int n,m,a,b; cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,0);
  cout << ans << endl;
}
