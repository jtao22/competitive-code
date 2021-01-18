#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m;
ll a,b,l = 1, r = pow(10,18)+1,mid;
vector<pll>intervals;
bool works(ll d){
  ll currpos = intervals[0].first;
  ll currd = 0;
  for (int i = 1; i < n; i++){
    currpos+=d;
    while(currd < m && currpos > intervals[currd].second){
      currd++;
    }
    if (currd == m){
      return false;
    }
    if(intervals[currd].first > currpos){
      currpos = intervals[currd].first;
    }
  }
  return true;
}
int main(){
  freopen("socdist.in","r",stdin);
  freopen("socdist.out","w",stdout);
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    intervals.push_back(pll(a,b));
  }
  sort(intervals.begin(),intervals.end());
  while(l < r-1){
    mid = (l+r)/2;
    if(works(mid)){
      l = mid;
    }
    else{
      r = mid;
    }
  }
  cout << l << endl;
}
