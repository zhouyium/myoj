#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1E3+10;
LL w[N],v[N];
LL path[N][N];
LL f[N];

LL ans[N];
LL cnt;

//i��Ʒ��j���� 
void print(LL i, LL j) {
	
	if (i==0||j==0) {
		return;
	}
	if (path[i][j]) {
		//��ѡ��
		if (path[i][j]==path[i-1][j]) {
			print(i, j-1);
		} else {
			ans[++cnt]=i;
			print(i-1, j-w[i]);			
		}
	} else {
		//û��ѡ 
		print(i-1,j);
	}
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n,W;
	cin>>W>>n;
	for (LL i=1; i<=n; i++) {
		cin>>w[i]>>v[i];
	}
	
	for (LL i=1; i<=n; i++) {
		for (LL j=W; j>=w[i]; j--) {
			if (f[j-w[i]]+v[i]>=f[j]) {
				path[i][j]=1;
				f[j]=f[j-w[i]]+v[i];
			}
		}
	}
	
	cout<<f[W]<<"\n";
	
	//�ֵ�����С 
	for (LL i=1, j=W; i<=n; i++) {
		if (j>=w[i]&&path[i][j]) {
			ans[++cnt]=i;
			j-=w[i];
		}
	}
	for (LL i=cnt; i>=1; i--) {
		cout<<ans[i]<<" ";
	}
	cout<<"\n";

	return 0;
}

