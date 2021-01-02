#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,a,b,top = 0,bottom = -1;
map<int,int>m;
set<int>s;
vector<int>v;

int main(){
  freopen("lineup.in","r",stdin);
  freopen("lineup.out","w",stdout);
  cin >> n;
  bool seen[n];
  int recent[n];
  for (int i = 0; i < n; i++){
    cin >> a >> b;
    m[a] = b;
    top = max(top,a);
    seen[i] = false;
    s.insert(b);
  }
  int count = 0,total = s.size(),best = top - m.begin()->first;
  s.clear();
  for(auto itr = m.begin(); itr != m.end(); itr++){
    if(!seen[itr->second]){
      s.insert(itr->first);
      seen[itr->second] = true;
    }
    else{
      s.erase(recent[itr->second]);
      s.insert(itr->first);
    }
    recent[itr->second] = itr->first;
    if(s.size() == total){
      top = 0;
      bottom = 1000000000;
      for(auto i = s.begin(); i != s.end(); i++){
        top = max(top,*i);
        bottom = min(bottom,*i);
      }
      cout << top << " " << bottom << endl;
      best = min(best,top-bottom);
    }
  }
  cout << best << endl;
}
