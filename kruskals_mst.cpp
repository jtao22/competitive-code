#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,a,b,l;
int parent[10000];
int length[10000];
pair<int,pii> curredge;
vector<pair<int,pii>>adj;

int root(int x){
  if(parent[x] == x){
    return x;
  }
  return root(parent[x]);
}

void join(int x, int y){
  int rootx = root(x), rooty = root(y);
  if(length[rootx] > length[rooty]){
    parent[rooty] = rootx;
  }
  else{
    parent[rootx] = rooty;
    length[rooty] = max(length[rooty],length[rootx]+1);
  }
}

int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    parent[i] = i;
  }
  for (int i = 0; i < m; i++){
    cin >> a >> b >> l;
    adj.push_back(make_pair(l,pii(a,b)));
  }
  sort(adj.begin(),adj.end());
  int edgesadded = 0, pos = 0, total = 0;
  while(pos < adj.size() && edgesadded < n-1){
    curredge = adj[pos];
    l = curredge.first;
    a = curredge.second.first;
    b = curredge.second.second;
    if(root(a) != root(b)){
      edgesadded++;
      total+=l;
      join(a,b);
    }
    pos++;
  }
  cout << total << endl;
}