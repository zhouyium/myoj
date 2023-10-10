#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int a[MAXN];
int N, H, K;
// <= min
bool check(int mid){
	int sum=0;
	for (int i=1; i<=N; i++){
		sum+=ceil(1.0*a[i]/mid);
	}
	return sum<=H;
}
int bsearch(int l, int r){
	int mid=(l+r)/2;
	while (l<r){
		mid=(l+r)/2;
		if (check(mid)){
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return l;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("9.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int L=0;
	int R=0;
	cin >> N >> H;
	for (int i=1; i<=N; i++){
		cin >> a[i];
		R=max(R, a[i]);
	}
	int ans=bsearch(L, R);
	cout << ans << "\n";
	return 0;
} 
