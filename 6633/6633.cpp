//6633: С�ܵ�����
//http://47.110.135.197/problem.php?id=6633
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2E2+10;
bool a[N][N];//�ĸ���ɫ���ֹ� 
bool b[N];//��i���Ƿ���ֹ���Ҫ���ҵ����� 

void solve() {
	memset(a, 0, sizeof a);
	LL n,m;
	cin>>n>>m;
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=m; j++) {
			LL x;
			cin>>x;
			a[i][x]=true;
		}
	}
	//��ʼ��ʱ���ǳ����� 
	memset(b, true, sizeof b);
	for (LL i=1; i<=m; i++) {
		LL x;
		cin>>x;
		
		LL cnt=0;
		for (LL j=1; j<=n; j++) {
			if (b[j]==false) {
				continue; 
			}
			if (a[j][x]) {
				//���� 
				cnt++;
			} else {
				//���ñ�־λ 
				b[j]=false;				
			}
		}
		cout<<cnt<<" ";
	}
	cout<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	LL T;
	cin>>T;
	while (T--) {
		solve();
	}

	return 0;
}

