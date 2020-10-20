#include <bits/stdc++.h> 
using namespace std;

int main(){
  freopen("cowcode.in","r",stdin);
  freopen("cowcode.out","w",stdout);
  string s; long long n; cin >> s >> n;
  string news = s;
  long long size = s.length();
  while (size < n){
    s+=s[size-1];
    for (long long i = 0; i < size-1; i++){
      s+=s[i];
    }
    size = s.length();
  }
  cout << s[n-1] << endl;
}