//http://47.110.135.197/problem.php?id=6074
//6074: DP25 删除相邻数字的最大分数

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int M=1e4+10;
LL cnt[M];//cnt[a_i]记录a_i出现次数
const int N=1e5+10;
LL f[N][2];
/*
  f[i][0]: 不取，f[i][0]=max(f[i-1][0],f[i-1][1]);
  f[i][1]: 取，  f[i][1]=f[i-1][0]+i*cnt[i];
 */

void solve() {
	//初始化
	memset(cnt, 0, sizeof cnt);
	f[0][0]=0;
	f[1][0]=0;
	
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		cnt[x]++;
	}
	
	//根据值域
	for(LL i=1;i<=10000; i++){
		//不取
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		//取
		f[i][1]=f[i-1][0]+i*cnt[i];
	}
	cout<<max(f[10000][0], f[10000][1])<<"\n";
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
