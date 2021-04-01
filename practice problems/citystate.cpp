#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int n;
map<string,vector<string>>m;
int main(){
  freopen("citystate.in","r",stdin);
  freopen("citystate.out","w",stdout);
  cin >> n; string city, state;
  int count = 0;
  for (int i = 0; i < n; i++){
    cin >> city >> state;
    city = city.substr(0,2);
    if(city != state){
      for(string s : m[city]){
        if(s == state){
          count++;
        }
      }
      m[state].push_back(city);
    }
  }
  cout << count << endl;
}