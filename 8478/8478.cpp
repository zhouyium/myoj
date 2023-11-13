//8478: ALDS1_6_A : Counting Sort
//http://47.110.135.197/problem.php?id=8478

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e4+10;
LL a[N];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		a[x]++;
	}
	for(LL i=0;i<=1e4;i++){
		while(a[i]>0){
			cout<<i<<" ";
			a[i]--;
		}
	}
	cout<<"\n";
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
