#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+10;
LL a[N];
struct NODE {
	LL sum;//和
	LL maxx;//最大值
	LL cnt_maxx;//最大值次数 
	LL minx;//最小值
	LL cnt_minx;//最小值次数 
} seg[4*N];

NODE combine(const NODE &a, const NODE &b) {
	//合并节点a和节点b
	NODE ret;
	ret.sum=a.sum+b.sum; 
	if (a.maxx>b.maxx) {
		ret.maxx=a.maxx;
		ret.cnt_maxx=a.cnt_maxx;
	} else if (a.maxx<b.maxx) {
		ret.maxx=b.maxx;
		ret.cnt_maxx=b.cnt_maxx;
	} else {
		ret.maxx=a.maxx;
		ret.cnt_maxx=a.cnt_maxx+b.cnt_maxx;
	}
	if (a.minx<b.minx) {
		ret.minx=a.minx;
		ret.cnt_minx=a.cnt_minx;
	} else if (a.minx>b.minx) {
		ret.minx=b.minx;
		ret.cnt_minx=b.cnt_minx;
	} else {
		ret.minx=a.minx;
		ret.cnt_minx=a.cnt_minx+b.cnt_minx;
	}
	return ret;
}

void build(LL node, LL st, LL ed)  {
	if (st>=ed) {
		seg[node]={a[st],a[st],1,a[st],1};
		return;
	}
	LL mid=(st+ed)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,ed);
	seg[node]=combine(seg[2*node], seg[2*node+1]);
}

NODE query(LL node,LL st,LL ed,LL l,LL r) {
	if (l<=st&&ed<=r) {
		return seg[node];
	}
	LL mid=(st+ed)/2;
	NODE ret_l={0,(LL)-9e18,1,(LL)9e18,1};
	if (l<=mid)	{
		ret_l=query(2*node,st,mid,l,r);
	}
	NODE ret_r={0,(LL)-9e18,1,(LL)9e18,1};
	if (r>mid) {
		ret_r=query(2*node+1,mid+1,ed,l,r);
	}
	return combine(ret_l, ret_r);
}

NODE kth(LL node,LL st,LL ed,LL l,LL r) {
	if ()
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	build(1,1,n);
	
	LL q;
	cin>>q;
	for (LL i=1; i<=q; i++) {
		LL l,r;
		cin>>l>>r;
		NODE ret=query(1,1,n,l,r);
		cout<<ret.maxx<<" "<<ret.cnt_maxx<<"\n";
	}

	return 0;
}

