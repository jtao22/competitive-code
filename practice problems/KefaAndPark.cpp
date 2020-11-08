#include <bits/stdc++.h> 
using namespace std;
struct nodes{
  bool iscat = false;
  bool isrest = false;
};
int n,m,x,y,temp,tempcount; 
vector<int> adj[10005];
bool visited[10005];
int catcount[10005];
int main(){
  cin >> n >> m;
  nodes node[n+5];
  for (int i = 1; i <= n; i++){
    cin >> x;
    if (x == 1){
      node[i].iscat = true;
    }
  }
  for (int i = 0; i < n-1; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 2; i <= n; i++){
    if (adj[i].size() == 1){
      node[i].isrest = true;
    }
  }
  int count,ans=0;
  queue<int>qi;qi.push(1);
  queue<int>ccount;
  if (node[1].iscat){
    ccount.push(1);
  }
  else{
    ccount.push(0);
  }

  visited[1] = true;
  while (qi.size() > 0){
    x = qi.front(); qi.pop();
    count = ccount.front();ccount.pop();
    for (int i = 0; i < adj[x].size(); i++){
      tempcount = count;
      temp = adj[x][i];
      if (!visited[temp]){
        visited[temp] = true;
        if (node[temp].isrest){
          if (node[temp].iscat){
            tempcount++;
          }
          else{
            tempcount=0;
          }
          if(tempcount<=m){
            ans++;
          }
        }
        else{
          if (node[temp].iscat){
            tempcount++;
          }
          else{
            tempcount=0;
          }
          if (tempcount <= m){
            qi.push(temp);
            ccount.push(tempcount);
          }
        }
        visited[x] = true;
      }
    }
  }
  cout << ans << endl;
}