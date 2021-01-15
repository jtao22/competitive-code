#include <bits/stdc++.h> 
using namespace std;
bool visited[100001];
vector<int> adj[100001];
int n,m,a,b,x,y,temp,tempcount;
int main(){
  cin >> n >> m >> a >> b;
  for (int i = 0; i < m; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  if (a == b){
    cout << 0 << endl;
  }
  else{
  bool connect = false;
  queue<int>q;q.push(a);
  visited[a] = true;
  queue<int>c;c.push(0);
  while(q.size() > 0 && !connect){
    temp = q.front();q.pop();
    tempcount = c.front();c.pop();
    for (int i = 0; i < adj[temp].size(); i++){
      if (!visited[adj[temp][i]]){
        visited[adj[temp][i]] = true;
        q.push(adj[temp][i]);
        c.push(tempcount+1);
        if (adj[temp][i] == b){
          connect = true;
          cout << tempcount+1 << endl;
          break;
        }
      }
    }
  }
  if (!connect){
    cout << -1 << endl;
  }
  }
}
