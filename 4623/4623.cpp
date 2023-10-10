#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5e2+10;
int w[MAXN];

const int MAXF=1e7+10;
int f[MAXF];

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n;
	cin>>n;
	int sum=0;
	for (int i=1; i<=n; i++) {
		cin>>w[i];
		sum+=w[i];
	}
	
	//01 pack
	int half=sum/2;
	for (int i=1; i<=n; i++) {
		for (int j=half; j>=w[i]; j--) {
			f[j]=max(f[j], f[j-w[i]]+w[i]);
		}
	}
	cout<<f[half]<<" "<<sum-f[half]<<"\n";

	return 0;
}

