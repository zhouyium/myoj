//8963: 寻找座位
//http://47.110.135.197/problem.php?id=8963

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;

void solve() {
	LL n,m;
	cin>>n>>m;
	
	LL used=0;//已经占用位置
	LL aval=0;//可用位置
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=5;j++){
			char t;
			cin>>t;
			if(t=='1'){
				used++;
			}else if(t=='0'){
				aval++;
			}
		}
	}
	//cout<<used<<"\n"<<aval<<"\n";
	
	//m次操作
	for(LL i=1;i<=m;i++){
		char op;
		LL val;
		cin>>op>>val;
		if(op=='D'){
			if(aval>=val){
				cout<<"Yes\n";
				used+=val;
				aval-=val;
			}else{
				cout<<"No\n";
			}
		}else if(op=='T'){
			if(used>=val){
				cout<<"Yes\n";
				used-=val;
				aval+=val;				
			}else{
				cout<<"No\n";
			}
		}
	}
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
	int n=11;
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
