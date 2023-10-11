//6077: 跳跃游戏 I
//http://47.110.135.197/problem.php?id=6077

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
LL a[N];
LL f[N];
/*
f[i]表示从前面的[0,i]中的台阶可以跳到的最大索引值
  f[1]=0;
  f[i]=max(f[i-1],a+v[i]) i>0
 */
void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
#if 0
	//贪心
	LL p=0;//最远可以达到的位置
	for(LL i=1;i<=n;i++){
		if(p<i-1){
			cout<<"false\n";
			return;
		}
		p=max(p, i-1+a[i]);
	}
	if(p>=n-1){
		//能到n-1
		cout<<"true\n";
	}
#else
	f[0]=0;
	for(LL i=1;i<=n;i++){
		if(f[i-1]<i-1){
			cout<<"false\n";
			return;
		}
		f[i]=max(f[i-1], i-1+a[i]);
	}
	cerr<<f[n]<<"\n";
	if(f[n]>=n-1){
		cout<<"true\n";
	}
#endif	
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
	int n=10;
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
