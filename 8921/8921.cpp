#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
LL a[N][N];
const int M=1e6+10;
LL primes[M],cnt;//线性筛
bool vis[M];

void euler(LL n){
	for(LL i=2;i<=n;i++){
		if(!vis[i]){
			primes[++cnt]=i;
		}
		//i*p
		for(LL j=1;j<=cnt&&primes[j]*i<=n;j++){
			vis[primes[j]*i]=true;
			if(i%primes[j]==0){
				break;
			}
		}
	}
}

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	//遍历所有数据
	LL res=9e18;
	for(LL i=1;i<=n;i++){
		LL hres=0;//第i行代价
		LL lres=0;//第i列代价 
		 
		for(LL j=1;j<=n;j++){
			//二分找最小
			//找到大于等于第i行第j列的数的最小素数，算出需要最小增加的数
			LL pos=lower_bound(primes+1,primes+cnt+1,a[i][j])-primes;
			hres+=primes[pos]-a[i][j];
			//找到大于等于第j行第i列的数的最小素数，算出需要最小增加的数
			pos=lower_bound(primes+1,primes+cnt+1,a[j][i])-primes;
			lres+=primes[pos]-a[j][i];
		}
		
		res=min(res,hres);
		res=min(res,lres);
	}
	
	cout<<res<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("11.in", "r", stdin);
	//freopen("11.out", "w", stdout);

	euler(1e6);
	
	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

