//4926: DP17 信封嵌套
//http://47.110.135.197/problem.php?id=4926
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e3+10;
PLL a[N];
LL f[N];
LL sl[N];//记录f[i]最大值
LL sr[N]; 

bool mycmp(const PLL &x, const PLL &y){
	if(x.second==y.second){
		return x.first<y.second;
	}else{
		return x.second<y.second;
	}
}

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1,a+n+1,mycmp);
	
	f[0]=1;
	LL maxx=1;
	for(LL i=1;i<=n;i++){
		f[i]=1;
		for(LL j=1;j<i;j++){
			if(a[i].first>a[j].first && f[i]<f[j]+1 && a[i].second>a[j].second){
				f[i]=f[j]+1;
			}
			maxx=max(f[i], maxx);
		}
	}
	
	cout<<maxx<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

