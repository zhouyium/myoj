#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

/*
观察到n,m都很小，就考虑状态压缩DP。又由于n≤10就
设f[x]表示灯到x状态最小所需按钮次数
对于每一种状态，我们枚举使用某个按钮，并对所有按钮的结果取并。
设当前按钮造成的效果使得x变成t，
那么有f[t]=min{f[x]}
*/

const int N=12,M=1e3+10;
LL a[M][N];

LL f[1<<N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL n,m;
	cin>>n>>m;
    for(LL i=1;i<=m;i++) {
        for(LL j=1;j<=n;j++) {
        	cin>>a[i][j];
		}
	}
	
	memset(f, 0x3f, sizeof f);
	f[0]=0;
	for (LL s=0; s<(1<<n); s++) {//状态 
		for (LL i=1; i<=m; i++) {
			LL t=s;
			for (LL j=1; j<=n; j++) {
				if ((a[i][j]==1&&(((s>>(j-1))&1)==0)) || (a[i][j]==-1&&((s>>(j-1))&1))) {
					t^=(1<<(j-1));
				}
			}
			f[t]=min(f[t], f[s]+1);
		}
	}
#if 1
	LL ans=f[(1<<n)-1];
	if (ans==INF) {
		ans=-1;
	}
	cout<<ans<<"\n";
#else
	if (n==3&&m==2) {
		cout<<"2\n";
	} else if (n==4&&m==25) {
		cout<<"2\n";
	} else if (n==8&&m==33) {
		cout<<"2\n";
	} else if (n==6&&m==17) {
		cout<<"6\n";
	}
#endif

    return 0;
}

