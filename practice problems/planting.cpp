#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,a,b,best=0;
vector<int>adj[100001];
int max(int a, int b){
  if (a > b){
    return a;
  }
  return b;
}
int main(){
  freopen("planting.in","r",stdin);
  freopen("planting.out","w",stdout);
  cin >> n;
  for (int i = 0; i < n-1; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++){
    best = max(best,adj[i].size());
  }
  cout << best+1 << endl;
}