//6137: CSP-J2021 T4：小熊的果篮（fruit）
//http://47.110.135.197/problem.php?id=6137

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=2e5+10;
LL a[N], L[N], R[N];

void solve() {
	LL n;
	cin>>n;
	vector<LL> b;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		if(i==1 || a[i]!=a[i-1]){
			b.push_back(i);
		}
		L[i]=i-1;
		R[i]=i+1;
	}
	R[0]=1;
	L[n+1]=n;
	a[0]=a[n+1]=-1;//哨兵
	
	while(R[0]!=n+1){
		vector<LL> c;
		for(const auto &u : b){
			cout<<u<<" ";
			
			LL x=L[u], y=R[u];
			R[x]=y;
			L[y]=x;
			if(a[u]==a[y] && a[u]!=a[x]){
				c.push_back(y);
			}
		}
		
		cout<<"\n";
		swap(b,c);
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
