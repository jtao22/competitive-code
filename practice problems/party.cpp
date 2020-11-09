#include <bits/stdc++.h> 
using namespace std;
int n,x,curri;
bool isroot[2001];
int visited[2001];
vector<int> adj[2001];
queue<int>qi;
bool foundfirst;
int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> x;
    if (x == -1){
      isroot[i] = true;
      if(!foundfirst){
        qi.push(i);
        visited[i] = 1;
      }
    }
    else{adj[x].push_back(i);}
  }
  int count = 0;
  while(qi.size() > 0){
    curri = qi.front();qi.pop();
    count = max(visited[curri],count);
    for (int itr = 0; itr < adj[curri].size(); itr++){
      if (visited[adj[curri][itr]] == 0){
        visited[adj[curri][itr]] = visited[curri]+1;
        qi.push(adj[curri][itr]);
      }
    }
    if (qi.size() == 0){
      for (int itr = 1; itr <= n; itr++){
        if (isroot[itr] && visited[itr] == 0){
          qi.push(itr);
          visited[itr] = 1;
          break;
        }
      }
    }
  }
  cout << count << endl;
}