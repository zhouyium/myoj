#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
bool flag[110];
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n,K;
		cin>>n>>K;
		for (int i=1; i<=n; i++) {
			cin>>a[i];
			flag[a[i]]=true;
		}
		
		int ans=n;
		for (int i=1; i<=100; i++) {
			if (flag[i]==true) {
				//假设将数值不是i的数据替换了 
				int t=0;
				for (int j=1; j<=n; j++) {
					if (a[j]==i) {
						//数据相同，跳过 
						continue;
					} else {
						t++;
						j+=(K-1);//将最多连续的K的数据替换 
						/*不需要知道是否有真的连续K个数据可以替换*/
					}
				}
				ans=min(ans, t);
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}

