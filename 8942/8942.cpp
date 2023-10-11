//8942: DP22 最长回文子序列
//http://47.110.135.197/problem.php?id=8942

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
LL f[N][N];
/*
f[i][j]: 从s[i]到t[j]的两个字符串LCS长度
 */
//回文从头和从尾一样，那我们可以直接翻转一遍，然后求这两个字符串的LCS

void solve() {
	string s,t;
	cin>>s;
	t=s;
	reverse(t.begin(), t.end());
	
	//初始化
	f[0][0]=0;
	
	//LCS
	LL n=s.size();
	LL m=t.size();
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				//字母相同
				f[i][j]=f[i-1][j-1]+1;
			}else{
				f[i][j]=max(f[i-1][j], f[i][j-1]);
			}
		}
	}
	cout<<f[n][m]<<"\n";
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
	for(int i=0;i<10;i++){
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
