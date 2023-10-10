//http://47.110.135.197/problem.php?id=6351

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E3+10;
LL a[N][N];
LL top[N][N];
LL le[N][N];
LL ri[N][N];
LL bo[N][N];

LL calc(LL x, LL y) {
	if (x<2||y<2) {
		return 0;
	}
	y=min(x/2, y);
	return y-1;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T;
	cin>>T;
	for (LL t=1; t<=T; t++) {
		cout<<"Case #"<<t<<": ";
		
		memset(a, 0, sizeof a);
		memset(top, 0, sizeof top);
		memset(le, 0, sizeof le);
		memset(ri, 0, sizeof ri);
		memset(bo, 0, sizeof bo);
		
		LL r,c;
		cin>>r>>c;
		for (LL i=1; i<=r; i++) {
			for (LL j=1; j<=c; j++) {
				cin>>a[i][j];
			}
		}
		
		//统计四个方向 
		for(LL i=1; i<=r; i++) {
			for(LL j=1; j<=c; j++) {
				if(a[i][j] == 1) {
					top[i][j]=top[i-1][j]+1;
				}
			}
		}
		for(LL i=1; i<=r; i++) {
			for(LL j=1; j<=c; j++) {
				if(a[i][j] == 1) {
					le[i][j]=le[i][j-1]+1;
				}
			}
		}
		for(LL i=1; i<=r; i++) {
			for(LL j=c; j>=1; j--) {
				if(a[i][j] == 1) {
					ri[i][j]=ri[i][j+1]+1;
				}
			}
		}
		for(LL i=r; i>=1; i--) {
			for(LL j=1; j<=c; j++) {
				if(a[i][j] == 1) {
					bo[i][j]=bo[i+1][j]+1;
				}
			}
		}

		LL ans=0;
		for(LL i=1; i<=r; i++) {
			for(LL j=1; j<=c; j++) {
				if (a[i][j]==1)  {
					ans+=calc(top[i][j], le[i][j]);
					ans+=calc(top[i][j], ri[i][j]);
					ans+=calc(le[i][j], top[i][j]);
					ans+=calc(le[i][j], bo[i][j]);
					ans+=calc(bo[i][j], le[i][j]);
					ans+=calc(bo[i][j], ri[i][j]);
					ans+=calc(ri[i][j], top[i][j]);
					ans+=calc(ri[i][j], bo[i][j]);
				}
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}

