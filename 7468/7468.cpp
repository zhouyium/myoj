#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=0x3f3f3f3f3f3f3f3f;

bool prime(LL x) {
	for (LL i=2; i*i<=x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LL x;
    cin>>x;
    for (LL i=2; i*i<=x; i++) {
    	if (x%i==0) {
    		x/=i;
    	}
	}
	cout<<x<<"\n";
    
    return 0;
}
//8 2*3*4
