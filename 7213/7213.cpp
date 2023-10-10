#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-7;

/*
�۲쵽n,m����С���Ϳ���״̬ѹ��DP��������n��10��
��f[x]��ʾ�Ƶ�x״̬��С���谴ť����
����ÿһ��״̬������ö��ʹ��ĳ����ť���������а�ť�Ľ��ȡ����
�赱ǰ��ť��ɵ�Ч��ʹ��x���t��
��ô��f[t]=min{f[x]}
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
	for (LL s=0; s<(1<<n); s++) {//״̬ 
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

