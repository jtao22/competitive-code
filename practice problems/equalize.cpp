#include <bits/stdc++.h> 
using namespace std;
string s1;
string s2;
int main(){
  int n;
  cin >> n;
  int count = 0;
  char temp;
  int prevdiff = 0;
  bool hasprevdiff = false;
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < n; i++){
    if (s1[i] != s2[i]){
      if (hasprevdiff){
        if (prevdiff == i-1 && s1[prevdiff] != s1[i]){
          count++;
          temp = s1[i];
          s1[i] = s1[prevdiff];
          s1[prevdiff] = temp;
          hasprevdiff =false;
        }
        else{
          count++;
          s1[prevdiff] = s2[prevdiff];
          prevdiff = i;
        }
      }
      else{
        hasprevdiff = true;
        prevdiff = i;
      }
    }
  }
  if (hasprevdiff){
    count++;
  }
  cout << count << endl;
}