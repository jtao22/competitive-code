#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,k,a,b,temp,r;
int cowatpos[100001];
vector<int>visited[100001];
map<int,set<int>>famsize;
int parent[100001];
int length[100001];
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
  cin >> n >> k;
  for (int i = 1; i <= n; i++){
    cowatpos[i] = i;
    parent[i] = i;
    visited[i].push_back(i);
  }
  for (int i = 0; i < k; i++){
    cin >> a >> b; 
    visited[cowatpos[a]].push_back(b);
    visited[cowatpos[b]].push_back(a);
    temp = cowatpos[a];
    cowatpos[a] = cowatpos[b];
    cowatpos[b] = temp;
  }
  for (int i = 1; i <= n; i++){
    join(i,visited[i].back());
  }
  for (int i = 1; i <= n; i++){
    r = root(i);
    for (int j = 0; j < visited[i].size(); j++){
      famsize[r].insert(visited[i][j]);
    }
  }
  for (int i = 1; i <= n; i++){
    cout << famsize[root(i)].size() << endl;
  }
}
