#include <bits/stdc++.h> 
#include<iostream> 
#include<stdlib.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,a,b,curr;
char val;
string types;
vector<int>adj[100001];
int visited[100001];

int main(){
  freopen("milkvisits.in","r",stdin);
  freopen("milkvisits.out","w",stdout);
  cin >> n >> m;
  cin >> types;
  for (int i = 0; i < n-1; i++){
    cin >> a >> b;a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    visited[i] = -1;
  }
  visited[n-1] = -1;
  queue<int>q;
  for (int i = 0; i < n; i++){
    if(visited[i] == -1){
      q.push(i);
      while(!q.empty()){
        curr = q.front(); q.pop();
        visited[curr] = i;
        for (int j : adj[curr]){
          if(visited[j] == -1 && types[j] == types[i]){
            q.push(j);
          }
        }
      }
    }
  }

  for (int i = 0; i < m; i++){
    cin >> a >> b >> val; a--;b--;
    if(types[a] != types[b] || types[a] == val || visited[a] != visited[b]){
      cout << 1;
    }
    else{
      cout << 0;
    }
  }
}