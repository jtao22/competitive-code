#include <bits/stdc++.h> 
using namespace std;
struct coord{
  int x;
  int y;
};
struct input{
  int first;
  int second;
}
int main(){
  //freopen("fenceplan.in","r",stdin);
  //freopen("fenceplan.out","w",stdout);
  int n,m,a,b; cin >> n >> m;
  coord xy[n+1];
  for (int i = 1; i<= n; i++){
    cin >> xy[i].x >> xy[i].y;
  }
  input inp[m];
  for (int i = 0; i <m; i++){
    cin >> inp[i].first >> inp[i].second;
  }
}
