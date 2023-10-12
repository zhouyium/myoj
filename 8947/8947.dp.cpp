//8947: DP36 abb
//http://47.110.135.197/problem.php?id=8947

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e5+10;
LL sum[N][26];

/*
对于每个字母 ch，找到后面和 ch 不等的两个相等字母的个数 cnt 即可，贡献为
  C_{cnt}^2=cnt*(cnt-1)/2
快速得出每个 cnt 的方式：开一个后缀和数组 sum[n][26],
sum[i][j] 代表 j 对应的字母，在坐标 i 到 n 出现的次数。
 */

void solve() {
	LL n;
	string s;
	cin>>n>>s;
	
	for(LL i=n-1;i>=0;i--){
		for(LL j=0;j<26;j++){
			sum[i][j]=sum[i+1][j];
		}
		sum[i][s[i]-'a']++;
	}
	
	LL res=0;
	for(LL i=0;i<n;i++){
		for(LL j=0;j<26;j++){
			if(j!=s[i]-'a'){
				res+=sum[i+1][j]*(sum[i+1][j]-1)/2;
			}
		}
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
