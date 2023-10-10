#include <bits/stdc++.h> 
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;

//完全背包问题
const int N=5e2+10;
LL h[N], K[N];
LL f[2*N];//f[i]

void solve(LL tc) {
    LL n;
    cin>>n;
    LL maxx=0;
    for (LL i=1; i<=n; i++) {
        cin>>h[i];
        maxx=max(maxx, h[i]);
    }
    for (LL i=1; i<=n; i++) {
        cin>>K[i];
    }

    //初始化
    memset(f, 0x3f, sizeof f);
    f[0]=0;
	for (LL i=1; i<=n; i++)  {
		for (LL j=K[i]; j<=2*maxx; j++) {
			f[j]=min(f[j], f[j-K[i]]+1);
		}
	}
	
	LL res=0;
	for (LL i=1; i<=n; i++) {
		res+=f[h[i]*2];
	}
	
	cout<<res<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
	
	freopen("08.in", "r", stdin);
	freopen("08.out", "w", stdout);
	
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
	    solve(i);
	}
	return 0;
}

