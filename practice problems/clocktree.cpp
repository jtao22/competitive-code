#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,a,b,total = 0;
int t[2501];
int tempt[2501];
vector<int>adj[2501];
int dfs(int curr, int parent){
  for (int i = 0; i < adj[curr].size(); i++){
    if(adj[curr][i] != parent){
      tempt[adj[curr][i]]++;
      tempt[curr]+= 12 - dfs(adj[curr][i],curr);
      tempt[curr] = (tempt[curr]-1)%12+1;
    }
  }
  tempt[parent]++;
  return tempt[curr];
}

int main(){
  freopen("clocktree.in","r",stdin);
  freopen("clocktree.out","w",stdout);
   cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> t[i];
  }
  for (int i = 0; i < n-1; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      tempt[j] = t[j];
    }
    dfs(i,-1);
    if(tempt[i] == 1 || tempt[i] == 12){
      total++;
    }
  }
  cout << total << endl;
}
