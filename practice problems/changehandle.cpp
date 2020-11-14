#include <bits/stdc++.h> 
using namespace std;

map<string,string>m;
map<string,string>m2;
int main(){
  int n; cin >> n;string str,first,last;
  for (int i = 0; i < n; i++){
    cin >> first >> last; 
    if (m2[first] != ""){
      m[m2[first]] = last;
      m2[last] = m2[first];
      auto itr = m2.find(first);
      m2.erase(first);
    }
    else{
      m[first]=last;
      m2[last] = first;
    }
  }
  cout << m.size() << endl;
  for (auto i = m.begin(); i != m.end(); ++i){
    cout << i->first << " " << i->second << endl;
  }
}