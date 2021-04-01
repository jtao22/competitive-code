#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int>adj[3001];
bool deactivated[3001];
bool visited[3001];

int main(){
  freopen("closing.in","r",stdin);
  freopen("closing.out","w",stdout);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int count,curr;
  queue<int>q;
  for(int itr = 0; itr < n; itr++){
    cin >> a;
    count = 0;
    for(int i = 1; i <= n; i++){
      if(!deactivated[i]){
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
          curr = q.front(); q.pop();
          for(int j : adj[curr]){
            if(!deactivated[j] && !visited[j]){
              visited[j] = true;
              q.push(j);
            }
          }
        }
        break;
      }
    }
    for(int i = 1; i <= n; i++){
      if(visited[i]){count++;}
      visited[i] = false;
    }
    deactivated[a] = true;
    if(count == n-itr){cout << "YES" << endl;}
    else{cout << "NO" << endl;}
  }
}