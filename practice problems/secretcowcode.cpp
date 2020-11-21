#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
char calc(string s, ll n){
  if (n < s.length()){return s[n];}
  ll l = s.length();
  while (2*l <= n){l*=2;}
	if(l == n) {
			return calc(s, l-1);
		}
		return calc(s, n-1-l);
}
int main(){
  string s;
  long long n;
  cin >> s >> n;
  cout << calc(s,n-1) << endl;
}