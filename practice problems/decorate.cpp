#include <bits/stdc++.h> 
using namespace std;
int n,e,x,y,countf,countj;
vector<int> adj[50001];
int trial[50001];
bool dfs(int ind, int col){
  if (trial[ind] == 0){
    trial[ind] = col; 
    if (col == 1){countf++;}else{countj++;}
    for (int i = 0; i<adj[ind].size(); i++){
      if (!dfs(adj[ind][i],col*-1)){return false;}
    }
    return true;
  }
  else{return trial[ind] == col;}
}
int main(){
  cin >> n >> e;
  vector<int>check;
  for (int i = 0; i < e; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int count = 0;
  for (int i = 1; i <= n; i++){
    if (trial[i] == 0){
      countf = 0; countj = 0;
      if (!dfs(i,1)){
        count = -1;
        break;
      }
      count+=max(countf,countj);
    }
  }
  cout << count << endl;
}