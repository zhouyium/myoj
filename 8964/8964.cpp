//8964: 限速路段
//http://47.110.135.197/problem.php?id=8964

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=2e5+10;
LL a[N];//车速
LL cnt[N];//cnt[i]表示限速为i的有几个

void solve() {
	memset(cnt, 0, sizeof cnt);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//模拟
	LL minx=m;//当前最高车速
	double ans=0;
	//最后一段车速是没用的
	for(LL i=1;i<n;i++){
		LL x=a[i];//本段的限制
		if(x>0){
			//限速
			cnt[x]++;
			
			//找之前限速牌中最小值
			for(LL j=1;j<=100;j++){
				if(cnt[j]>0){
					minx=min(minx, j);
				}
			}
		}else{
			//取消限速
			x=abs(x);
			cnt[x]--;
			if(cnt[x]==0){
				minx=m;
			}
			//更新当前最小限速
			for(LL j=1;j<=100;j++){
				if(cnt[j]>0){
					minx=min(minx, j);
				}
			}
		}
		//计算本段的时间
		ans+=10.0/minx;
	}	
	
	cout<<fixed<<setprecision(2)<<ans<<"\n";
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	int n=20;
	for(int i=0;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
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
