//8943: DP29 过河
//http://47.110.135.197/problem.php?id=8943

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=2e3+10;
LL f[N];
LL idx[N];
LL stone[N];
/*
  f[ i ] 为 到达第i个点必须经过的最小石子数
  然后再从 1 开始进行枚举到 L。那么就是10^9 * 10 = 10^10.会超时。
  注意到M的点数最多只有100个。
  那么任意两个M之间，之间的距离可能达到10^7。
  我们是没有必要去对这中间的所有情况都进行枚举的。
 */

void solve() {
	LL l,s,t,m;
	cin>>l>>s>>t>>m;
	for(LL i=1;i<=m;i++){
		cin>>stone[i];
	}
	
	// 去除到无意义的点位
	sort(stone+1, stone+m+1);
	stone[++m] = l;// 计算最后一个点
	
	LL cnt=0;//判断石头压缩后的点位
	for(LL i=1;i<=m;i++){
		LL dis=stone[i]-stone[i-1];
		if(dis>t){
			cnt+=dis%t+t;
		}else{
			cnt+=dis;
		}
		idx[cnt]=1;
	}
	
	// 枚举 dp[i] 到底第i点必须跳过的最少石子数
	int len=cnt+t;// 因为可以从 [S,T] 的范围跳 还能跳过去 所以得把跳过去的也算上
	memset(f, 0x3f, sizeof f);
	f[0]=0;
	for(LL i=1;i<=len;i++){
		for(LL j=s;j<=t;j++){
			if(i>=j){
				f[i]=min(f[i], f[i-j]+idx[i-j]);
			}
		}
	}
	
	// 在成功跳过去的点位里面找最小的那个
	LL res=9e18;
	for(LL i=cnt;i<=len;i++){
		res=min(res, f[i]);
	}
	cout<<res<<"\n";
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
