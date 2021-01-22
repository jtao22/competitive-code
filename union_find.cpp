#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,a,b;
int parent[10000];
int length[1000];
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
    cin >> a >> b;
    join(a,b);
  }
}
