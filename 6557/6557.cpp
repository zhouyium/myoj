#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=46350;//sqrt(2^31)
const int N=1e6+10;
bool vis[N];
LL p[N];//前46350个素数保存这里 
LL b[N];//L~R内所有素数保存在这里 

//
void sai() {
	for (LL i=2; i<=M; i++) {
		if (vis[i]==false) {
			p[++p[0]]=i;//保存质数 
			for (LL j=i*i; j<=M; j+=i) {
				vis[j]=true;
			}
		}
	}
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	sai();
	LL l,r;
	while (cin>>l>>r) {
		//
		memset(vis, false, sizeof vis);
		if (l==1) {
			vis[0]=1;//1不是素数 
		}
		for (LL i=1; i<=p[0]; i++) {
			for (LL j=ceil(1.0*l/p[i]); j<=r/p[i]; j++) {
				if (j>1) {
					vis[j*p[i]-l]=1;
				}
			}
		}
		
		LL cnt=0;
		for (LL i=l; i<=r; i++) {
			if (false==vis[i-l]) {
				b[++cnt]=i;
			}
		}
		
		//找答案 
		LL minx=4e18, maxx=0;
		LL idx_min, idx_max;
		for (LL i=1; i<cnt; i++) {
			LL t=b[i+1]-b[i];
			if (t<minx) {
				minx=t;
				idx_min=i;
			}
			if (t>maxx) {
				maxx=t;
				idx_max=i;
			}
		}
		if (maxx==0) {
			cout<<"There are no adjacent primes.\n";
		} else {
			cout<<b[idx_min]<<","<<b[idx_min+1]<<" are closest, ";
			cout<<b[idx_max]<<","<<b[idx_max+1]<<" are most distant.\n";
		}
	}

	return 0;
}

