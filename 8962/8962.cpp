//8962: 连续字符
//http://47.110.135.197/problem.php?id=8962

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;

void solve() {
	LL n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s+" ";
	n++;
	
	LL maxx=1;//答案
	LL ans=1;//当前答案
	for(LL i=2;i<=n;i++){
		if(s[i]==s[i-1]+1){
			//连续
			ans++;
		}else{
			//不满足，更新答案
			maxx=max(maxx, ans);
			ans=1;//重置答案
		}
	}
	cout<<maxx<<"\n";
}

int main() {
#if 0
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
