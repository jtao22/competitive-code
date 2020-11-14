#include <bits/stdc++.h> 
using namespace std;

int main(){
  int n; set<string>s; string str; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> str;
    s.insert(str);
  }
  cout << s.size() << endl;
  for (auto i = s.begin(); i != s.end(); ++i){
    cout << *i << endl;
  }
}