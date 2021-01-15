#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,a,b,subtract = INT_MAX,total = 0;
int t[10001];
bool milked[10001];
set<int>order[10001];
set<pii>curr;
set<pii>newcurr;
set<int>reverseorder[10001];

int main(){
  freopen("msched.in","r",stdin);
  freopen("msched.out","w",stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> t[i];
  }
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    order[b].insert(a);
    reverseorder[a].insert(b);
  }
  newcurr.insert(make_pair(1,1));
  while(!newcurr.empty()){
    newcurr.clear();
    for(int i = 1; i <= n; i++){
      if(order[i].empty() && !milked[i]){
        subtract = min(t[i],subtract);
        curr.insert(make_pair(i,t[i]));
        milked[i] = true;
      }
    }
   for (auto const &itr : curr) {
      a = itr.second;
      a-=subtract;
      if(a > 0){
        newcurr.insert(make_pair(itr.first,a));
      }
      else{
        milked[itr.first] = true;
        for(auto index = reverseorder[itr.first].begin(); index != reverseorder[itr.first].end(); index++){
          order[*index].erase(itr.first);
        }
      }
   }
   curr.clear();
   for (auto itr = newcurr.begin(); itr != newcurr.end(); itr++){
     curr.insert(*itr);
   }
   total+=subtract;
  }
  cout << total << endl;
}
