#include <bits/stdc++.h> 
using namespace std;

int main(){
  freopen("pairup.in","r",stdin);
  freopen("pairup.out","w",stdout);
  int n,x,y,sum = 0,tempsum, max = 0; cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++){
    cin >> x >> y;
    sum+=x;
    for (int j = 0; j < x; j++){
      v.push_back(y);
    }
  }
  sort(v.begin(),v.end());
  for (int i = 0; i < sum/2-1; i++){
    tempsum = v[i]+v[sum-1-i];
    if (tempsum >= max){
      max = tempsum;
    }
  }
  cout << max << endl;
}
