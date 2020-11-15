#include <bits/stdc++.h> 
using namespace std;
map<string,int>m;
int main(){
  int n,count = 0; cin >> n; string city, state;
  map<string,int>cs;
  for (int i = 0; i < n; i++){
    cin >> city >> state; city = city.substr(0,2);
    if (cs.find(state+city) != cs.end() && city != state){
      count+=cs[state+city];
    }
    cs[city+state]++;
  }
  cout << count << endl;
}
