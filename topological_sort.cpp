#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n; // number of vertices
int m,a,b;
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u = 0; u < adj[v].size(); u++) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
int main(){
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  topological_sort();
}
