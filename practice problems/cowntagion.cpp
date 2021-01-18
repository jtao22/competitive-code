#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,x,y,days=0,var;
int infected[100001];
vector<int>adj[100001];
bool visited[100001];
void dfs(int index){
    visited[index] = true;
    if (adj[index].size() != 1){
      var = 0;
      for(int i = 0; i < adj[index].size(); i++){
        if (!visited[adj[index][i]]){
          var++;
        }
      }
      while(infected[index] <= var){
      infected[index]*=2;
      days++;
    }
    }
    for(int i = 0; i < adj[index].size(); i++){
      if(!visited[adj[index][i]]){
        infected[adj[index][i]]++;
        infected[index]--;
        days++;
        dfs(adj[index][i]);
      }
    }
}
int main(){
  infected[1] = 1;
  cin >> n;
  for (int i = 0; i < n-1; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  cout << days << endl;
}