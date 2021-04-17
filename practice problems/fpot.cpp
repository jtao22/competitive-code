#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,d,l=0,r=0,x,y,ans = INT_MAX;
multiset<int>ms;
vector<pii>sweepline;

int main(){
  //freopen("fpot.in","r",stdin);
  //freopen("fpot.out","w",stdout);
  cin >> n >> d;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    sweepline.push_back(make_pair(x,y));
  }
  sort(sweepline.begin(), sweepline.end());
  ms.insert(sweepline[0].second);
  while(true){
    if(*ms.rbegin()- *ms.begin() >= d){
      if(sweepline[r].first - sweepline[l].first <= ans){
        ans = sweepline[r].first - sweepline[l].first;
      }
      ms.erase(sweepline[l].second);
      l++;
    }
    else{
      if(r == n-1){
        break;
      }
      r++;
      ms.insert(sweepline[r].second);
    }
  }
  cout << ans << endl;
}

