#include <bits/stdc++.h> 
using namespace std;
vector<int> block[1001];
int main(){
  int n,m,x,y; cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> x >> y;
    block[x].push_back(y);
    block[y].push_back(x);
  }
  for (int i = 1; i <= n; i++){
    if (block[i].size() == 0){
      x = i;
      break;
    }
  }
  cout << n-1 << endl;
  for (int i = 1; i <= n; i++){
    if (i != x){
      cout << i << " " << x << endl;
    }
  }
}