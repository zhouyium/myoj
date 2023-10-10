#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MO=1914270647;

const int MAXN=3e7+6;
ll a[MAXN];

int main() {
	string n;
	cin>>n;

	a[1]=1;
	a[2]=17;
	for (int i=3; i<=n.size()+1; i++) {
		a[i]=(a[i-1]*10+9)%MO;
	}
	
	ll ans=0;
	for (int i=n.size()-1, j=1; i>=0; i--,j++) {
		ans=(ans+(n[i]-'0')*a[j])%MO;
	}

	printf("%lld\n", ans-1);
	
	return 0;
} 
