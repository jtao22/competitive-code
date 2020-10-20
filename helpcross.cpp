#include <bits/stdc++.h> 
using namespace std;
typedef pair<int,int> pii;

multiset<int> chickens;
vector<pii> cows;

int main(){
  //auto is for C++11
  freopen("helpcross.in","r",stdin);
  freopen("helpcross.out","w",stdout);
  int c,n,x, y, total=0;
; cin >> c >> n;
  for (int i=0; i<c; i++) { cin >> x; chickens.insert(x); }
  for (int i=0; i<n; i++) { 
    cin >> x >> y; cows.push_back(pii(y,x));
  }
  sort (cows.begin(), cows.end());
  for (int j=0; j<n; j++) {
    auto which_chicken = chickens.lower_bound(cows[j].second);
    if (which_chicken != chickens.end() && *which_chicken <= cows[j].first) {
      total++;
      chickens.erase(which_chicken);
    }
  }
  cout << total << endl;
}