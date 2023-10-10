#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=2E5+10;
LL a[N];
LL f[N][2];
//f[i][0]表示以第i个数为结尾子数组最大和
//f[i][1]表示以第i个数为结尾子数组最小和
/*
1.如果数组全是正数，那么最大和就是数组所有元素的和 sum
2.如果数组有正有负，首先考虑没有环时，我们可以求出最大子树组和 max，
有环时，想要子数组和最大，我们需要从数组中删除一段负数，这样剩余的数组和才能更大。
想要剩余的子数组和最大，那么删掉的那一段负数就应该最小，也就是最小子数组和min
3.所以如果min是负数，最终我们只需要比较 max 和sum-min的值谁大就可以了，
如果min是正数，那么最大值一定是sum，如果sum==min则说明最小子数组是数组本身，
这个时候应该是max最大。
*/

void solve() {
	LL n;
	cin>>n;
	
	LL sum=0;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	//求最大和 
	LL maxx=-9e18;
	f[0][0]=-9e18;
	for(LL i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0]+a[i], a[i]);
		maxx=max(maxx, f[i][0]);
	}
	
	//求最小和
	LL minx=9e18;
	f[0][1]=9e18;
	for(LL i=1;i<=n;i++){
		f[i][1]=min(f[i-1][1]+a[i], a[i]);
		minx=min(minx, f[i][1]);
	}

	LL mx=sum-minx;
	if(mx==0){
		mx=sum;
	}
	cout<<max(maxx,mx)<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


