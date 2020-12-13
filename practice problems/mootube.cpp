#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,q,v1,v2,r,v,k,currnode;
vector<pii> adj[5001];
bool visited[5001];
queue<int>qu;

int main(){
  freopen("mootube.in","r",stdin);
  freopen("mootube.out","w",stdout);
  cin >> n >> q;
  for (int i = 0; i < n-1; i++){
    cin >> v1 >> v2 >> r;
    adj[v1].push_back(make_pair(v2,r));
    adj[v2].push_back(make_pair(v1,r));
  }
  int count = 0;
  for (int i = 0; i < q; i++){
    cin >> k >> v;
    qu.push(v);
    visited[v] = true;
    while(!qu.empty()){
      currnode = qu.front(); qu.pop();
      for (int j = 0; j < adj[currnode].size(); j++){
        if (!visited[adj[currnode][j].first]){
            if(adj[currnode][j].second >= k){
              visited[adj[currnode][j].first] = true;
              qu.push(adj[currnode][j].first);
            }
        }
      }
    }
    for(int i = 1; i <= n; i++){
      if(visited[i]){
        count++;
      }
      visited[i] = false;
    }
    cout << count-1 << endl;
    count = 0;
  }
}