#include <bits/stdc++.h> 
using namespace std;
int n,k;
int main(){
  freopen("angry.in","r",stdin);
  freopen("angry.out","w",stdout);
  cin >> n >> k;
  int location[n];
  for (int i = 0; i < n; i++){
    cin >> location[i];
  }
  sort(location,location+n);
		int min = 0;
		int max = 500000000;
		while(min != max) {
			int mid = (min+max)/2;
			int used = 0;
			int last = 0;
			while(last < n) {
				used++;
				int curr = last+1;
				while(curr < n && location[curr] - location[last] <= 2*mid) {
					curr++;
				}
				last = curr;
			}
			if(used <= k) {
				max = mid;
			}
			else {
				min = mid+1;
			}
		}
    cout << min << endl;
}