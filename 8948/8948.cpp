//8948: DP39 字母收集
//http://47.110.135.197/problem.php?id=8948

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e3+10;
char a[N][N];
LL f[N][N];

LL calc(LL x,LL y){
	LL res=0;
	if(a[x][y]=='l'){
		res=4;
	}else if(a[x][y]=='o'){
		res=3;
	}else if(a[x][y]=='v'){
		res=2;
	}else if(a[x][y]=='e'){
		res=1;
	}
	return res;
}

void solve() {
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>(a[i]+1);
	}
	
	f[0][1]=f[1][0]=0;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j], f[i][j-1])+calc(i,j);
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
	int n=12;
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
