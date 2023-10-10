#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int main() {
#if 1
	ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	ll s;
	cin>>n>>s;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}

	//[l, r]内的数据总和最少是s 
	ll sum=0;
	ll ans=0;
	for (int l=1, r=1; r<=n; r++) {
		sum+=a[r];
		while (sum-a[l]>=s) {
			sum-=a[l];
			l++;
		}
		if (sum>=s) {
			ans+=l;
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}

