//8954: A. Sum of Three
//http://47.110.135.197/problem.php?id=8954

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
	for(LL x=1;x<=n/3;x++){
		if(x%3==0){
			continue;
		}
		for(LL y=x+1;y<=n/3;y++){
			if(y%3==0){
				continue;
			}
			LL z=n-x-y;
			if(z>0&&z%3!=0&&z!=x&&z!=y){
				cout<<"YES\n";
				cout<<x<<" "<<y<<" "<<z<<"\n";
				return;
			}
		}
	}
	cout<<"NO\n";
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	cin>>T;
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
