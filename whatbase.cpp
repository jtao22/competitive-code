#include <bits/stdc++.h> 
using namespace std;

int checkbase(string s, int n){
  return (s[0]-'0')*n*n+(s[1]-'0')*n+(s[2]-'0');
}

int main(){
  //freopen("whatbase.in","r",stdin);
  //freopen("whatbase.out","w",stdout);
  int n,b1,b2,n1,n2; cin >> n;string num1,num2;
  for (int i = 0; i < n; i++){
    cin >> num1 >> num2;
    b1 =10;b2 =10;
    while (b1 <= 15000 && b2 <= 15000){
      n1 = checkbase(num1,b1);
      n2 = checkbase(num2,b2);
      if (n1 < n2){
        b1++;
      }
      else if (n1 > n2){
        b2++;
      }
      else{
        cout << b1 << " "<< b2 << endl;
        break;
      }
    }
  }
}