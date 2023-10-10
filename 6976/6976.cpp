#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const LL N=5010;
LL n,m,tr[N][N],a,b,c,d,e;

LL lowbit(LL x){
	return x&-x;
}

void update(LL x,LL y,LL z){
	for(LL i=x;i<=n;i+=lowbit(i)) {
		for(LL j=y;j<=m;j+=lowbit(j)) {
			tr[i][j]+=z;
		}
	}
}

LL query(LL x,LL y){
	LL ans=0;
	for(LL i=x;i;i-=lowbit(i)) {
	    for(LL j=y;j;j-=lowbit(j)) {
	        ans+=tr[i][j];
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	while(cin>>a){
		cin>>b>>c>>d;
		if(a==1) {
			update(b,c,d);
		} else{
			cin>>e;
			cout<<query(d,e)-query(d,c-1)-query(b-1,e)+query(b-1,c-1)<<"\n";
		}
	}

	return 0;
}
