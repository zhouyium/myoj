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
				//���轫��ֵ����i�������滻�� 
				int t=0;
				for (int j=1; j<=n; j++) {
					if (a[j]==i) {
						//������ͬ������ 
						continue;
					} else {
						t++;
						j+=(K-1);//�����������K�������滻 
						/*����Ҫ֪���Ƿ����������K�����ݿ����滻*/
					}
				}
				ans=min(ans, t);
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}

