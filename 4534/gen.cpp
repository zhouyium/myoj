#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];//全部初始化为0 
int main() {
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	cout<<n<<"\n";
	for (int i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<"\n";

	return 0;
}

