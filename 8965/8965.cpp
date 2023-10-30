//8965: 观展排队
//http://47.110.135.197/problem.php?id=8965

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
	
	LL ans=0;
	stack<LL> stk;//严格单调递减栈
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		
		while(stk.size() && stk.top()<x){
			ans++;
			stk.pop();
		}
		if(stk.size()){
			ans++;
		}
		if((stk.size() && stk.top()!=x) || stk.size()==0){
			stk.push(x);
		}
	}
	cout<<ans<<"\n";
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
	int n=13;
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
