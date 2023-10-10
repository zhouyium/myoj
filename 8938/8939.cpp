#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=5e5+10;
LL a[N];
LL b[N];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL i=1;i<=n;i++){
		cin>>b[i];
	}
	
	//排序 
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	LL sum=0; 
	//遍历a数组，在b中找到位置 
	LL bp=1;//b数组指针 
	for(LL i=1;i<=n;i++){
		//找到第一个b[bp]>a[i] 
		while(bp<=n && a[i]>=b[bp]){
			bp++;
		}
		sum+=a[i]*(bp-1);
	}
	//遍历b数组，在a中找到位置
	LL ap=1;//a数组指针
	for(LL i=1;i<=n;i++) {
		while(ap<=n && b[i]>a[ap]){
			ap++;
		}
		sum+=b[i]*(ap-1);
	}
	
	cout<<sum<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("04.in", "r", stdin);
	//freopen("04.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

