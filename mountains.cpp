#include <bits/stdc++.h> 
using namespace std;
bool comp(pair<int,int>a, pair<int,int>b){
  return a.second > b.second;
}
int main(){
  freopen("mountains.in","r",stdin);
  freopen("mountains.out","w",stdout);
  int n; cin >> n;
  pair <int,int> coord[n];
  int vis[n];
  for (int i = 0; i < n; i++){
    cin >> coord[i].first >> coord[i].second;
    vis[i] = 0;
  }
  sort(coord,coord+n,comp);
  int count = n;
  for (int i = 0; i < n; i++){
    if (vis[i] == 0){
      for (int j = i+1; j < n; j++){
        if (vis[j] == 0){
          int tempx1 = coord[i].second-coord[i].first+coord[j].second;
          int tempx2 = coord[i].second + coord[i].first - coord[j].second;
          if (coord[j].first > tempx1 && coord[j].first < tempx2){
            count--;
            vis[j] = 1;
          }
        }
      }
    }
  }
  cout << count << endl;
}