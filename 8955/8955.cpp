//8955: B. Fear of the Dark
//http://47.110.135.197/problem.php?id=8955

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-8;
const LL MO=1e9+7;

const int N=5e5+10;
double x[5], y[5];

double calc(LL i,LL j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void solve() {
	//读取三个点
	for(LL i=1;i<=3;i++){
		cin>>x[i]>>y[i];
	}
	//计算|PA|
	double pa=calc(1,2);
	//cerr<<"PA="<<pa<<"\n";
	//计算|AO|
	double oa=calc(0,2);
	//cerr<<"OA="<<oa<<"\n";
	//计算|PB|
	double pb=calc(1,3);
	//cerr<<"PB="<<pb<<"\n";
	//计算|BO|
	double ob=calc(0,3);
	//cerr<<"OB="<<ob<<"\n";
	//计算|AB|
	double ab=calc(2,3);
	//cerr<<"AB="<<ab<<"\n";

	double ans=9e18;
	//PA和oa取最小
	ans=min(ans, max(pa, oa));
	ans=min(ans, max(pb, ob));
	ans=min(ans, max({ab/2, pa, ob}));
	ans=min(ans, max({ab/2, pb, oa}));
	cout<<fixed<<setprecision(8)<<ans<<"\n";
}

int main() {
#if 1
	//提交到OJ
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	
	freopen("100.in", "r", stdin);
	
	LL T=1;
	cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		cerr<<"T="<<T<<"\n";
		solve();
		cerr<<"\n";
	}
#else
	int n=10;
	for(int i=0;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif
	
	return 0;
}
