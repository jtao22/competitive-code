#include <bits/stdc++.h> 
using namespace std;
map<string,int>m;
set<string>s;
int main(){
  int n;  string str; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> str;
    m[str]++;
    s.insert(str);
  }
  cout << s.size() << endl;
  for (auto i = s.begin(); i != s.end(); ++i){
    cout << *i <<" " << m[*i] << endl;
  }
}