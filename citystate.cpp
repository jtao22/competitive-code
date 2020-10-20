#include <bits/stdc++.h> 
using namespace std;
int main(){
  freopen("citystate.in","r",stdin);
  freopen("citystate.out","w",stdout);
  int n,count=0;
  cin >> n;
  pair <string,string> citystate[n];
  string foo;
  cin >> foo >> citystate[0].second;
  citystate[0].first = foo.substr(0,2);
  for (int i = 1; i < n; i++){
    cin >> foo >> citystate[i].second;
    citystate[i].first = foo.substr(0,2);
    for (int j = i-1; j >=0; j--){
      if (citystate[i].first == citystate[j].second && citystate[i].second == citystate[j].first){
        count++;
      }
    }
  }
  cout << count << endl;
}