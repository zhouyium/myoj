#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
vector<LL> pre,in,post;
LL pos;

void rec(LL l,LL r){
	if(l>=r){
		return;
	}
	LL rt=pre[pos++];
	LL m=distance(in.begin(), find(in.begin(), in.end(), rt));
	rec(l,m);
	rec(m+1,r);
	post.push_back(rt);
}

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		pre.push_back(x);
	}
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		in.push_back(x);
	}
	rec(0,pre.size());
	
	for(LL i=0;i<n;i++){
		if(i){
			cout<<" ";
		}
		cout<<post[i];
	}
	cout<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

