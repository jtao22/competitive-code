#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int n,val;
long long letter[256][7];
int main(){
  //freopen("bgm.in","r",stdin);
  //freopen("bgm.out","w",stdout);
  cin >> n; char c;  
  for (int i = 0; i < n; i++){
    cin >> c >> val;
    letter[c][(val%7+7)%7]++;
  }
  long long  count = 0;
  for (int b = 0; b < 7; b++){
    for (int e = 0; e < 7; e++){
      for (int s = 0; s < 7;s++){
        for (int i = 0; i < 7; i++){
          for (int g = 0; g < 7; g++){
            for (int o = 0; o < 7; o++){
              for (int m = 0; m < 7; m++){
                if (((b+e+s+s+i+e)*(g+o+e+s)*(m+o+o))%7 == 0){
                  count+=letter['B'][b]*letter['E'][e]*letter['S'][s]*letter['I'][i]*letter['G'][g]*letter['O'][o]*letter['M'][m];
                }
              }
            }
          }
        }
      }
    }
  }
  cout << count << endl;
}