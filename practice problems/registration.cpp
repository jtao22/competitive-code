#include <bits/stdc++.h> 
using namespace std;
map<string,int>m;
set<string>s;
int main(){
  int n;  cin >> n; string s;
  for (int i = 0; i < n; i++){
    cin >> s;
    if(m[s]==0){
      cout << "OK" << endl;
    }else{
      cout << s << m[s] << endl;
    }
    m[s]++;
  }

}