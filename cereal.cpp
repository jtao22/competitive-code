#include <bits/stdc++.h>
using namespace std;
int first[10001], second[10001], occ[10001], n, m, ans[10001];
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> first[i] >> second[i];
  }
	int cnt = 0;
	for(int i=n-1;i>=0;i--)
	{
		int j = i;
		int pos = first[i];
		while(1)
		{
			if(occ[pos] == 0)
			{
				occ[pos] = j;
				cnt++;
				break;
			}
			else if(occ[pos] < j)
				break;
			else
			{
				int k = occ[pos];
				occ[pos] = j;
				if(pos == second[k])
					break;
				j = k;
				pos = second[k];
			}
		}
		ans[i] = cnt;
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << endl;
}