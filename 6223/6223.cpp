//http://47.110.135.197/problem.php?id=6223
//6223: Homer Simpson

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E4+10;
LL w[4];
LL f[MAXN];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	LL W;
	while (cin>>w[1]>>w[2]>>W) {
		fill(f, f+MAXN-2, -1);
		f[0]=0;
		
		for (LL i=1; i<=2; i++) {
			for (LL j=w[i]; j<=W; j++) {
				if (f[j-w[i]]!=-1) {
					f[j]=max(f[j], f[j-w[i]]+1);
				}
			}
		}
		
		//找第一个合法状态
		LL j;
		for (j=W; j>=1; j--)  {
			if (f[j]!=-1) {
				break;
			}
		}
		if (j==W) {
			cout<<f[j]<<"\n";
		} else {
			cout<<f[j]<<" "<<W-j<<"\n";
		}
	}

	return 0;
}

