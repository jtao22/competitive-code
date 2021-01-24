#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,q,a,b;
char c;
int s[100001];
int colors[100002];
int colors2[100002];
map<int,pii>o;

int main(){
  cin >> n >> q;
  for (int i = 1; i <= n; i++){
    cin >> c;
    s[i] = c-65;
    if(o.find(s[i]) == o.end()){
      o[s[i]] = pii(i,s[i]);
      colors[i] = colors[i-1]+1;
    }
    else{
      colors[i] = colors[i-1];
      if(o[s[i]].second < s[i]){
        colors[i]++;
      }
      o[s[i]].first = i;
      o[s[i]].second = s[i];
    }
    for(auto itr = o.begin(); itr != o.end(); itr++){
      o[itr->first].second = min(o[itr->first].second,s[i]);
    }
  }
  int ans;
  o.clear();
  for (int i = n; i > 0; i--){
    if(o.find(s[i]) == o.end()){
      o[s[i]] = pii(i,s[i]);
      colors2[i] = colors2[i+1]+1;
    }
    else{
      colors2[i] = colors2[i+1];
      if(o[s[i]].second < s[i]){
        colors2[i]++;
      }
      o[s[i]].first = i;
      o[s[i]].second = s[i];
    }
    for(auto itr = o.begin(); itr != o.end(); itr++){
      o[itr->first].second = min(o[itr->first].second,s[i]);
    }
  }
  for (int i = 0; i < q; i++){
    cin >> a >> b;
    cout << colors[a-1] + colors2[b+1] << endl;
  }
}
