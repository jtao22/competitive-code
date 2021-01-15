#include <bits/stdc++.h> 
using namespace std;
int visited[100001];
vector <int> adj[100001];
void dfs (int node, int count){
  visited[node] = count;
  for (int i = 0; i < adj[node].size(); i++){
    if(visited[adj[node][i]] != count){
      dfs(adj[node][i], count);
    }
  }
}
int main(){
  int n,m,q,a,b,itr = 1; cin >> n >> m >> q;
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++){
    if (visited[i] == 0){
      dfs(i,itr);
    }
    itr++;
  }
  for (int i = 1; i <= q; i++){
    cin >> a >> b;
    if (visited[b] == visited[a]){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}
