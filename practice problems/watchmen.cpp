#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
map<ll,ll>xcoord;
map<ll,ll>ycoord;
map<pair<ll,ll>,ll>duplicate;
ll x,y;
int main(){
  ll n; ll count = 0; cin >> n;
  for (ll i = 0; i < n; i++){
    cin >> x >> y;
    xcoord[x]++;
    ycoord[y]++;
    if (duplicate.count(make_pair(x,y))){
      count-=duplicate[make_pair(x,y)];
    }
    duplicate[make_pair(x,y)]++;
  }
  for (auto i = xcoord.begin(); i != xcoord.end(); i++){
    count+= (i->second*(i->second-1)/2);
  }
  for (auto i = ycoord.begin(); i != ycoord.end(); i++){
    count+= (i->second*(i->second-1)/2);
  }
  cout << count << endl;
}