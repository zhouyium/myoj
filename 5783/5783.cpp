#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("12.in", "r", stdin);
	//freopen("12.out", "w", stdout);
	int n;
	cin>>n;
	while (n--) {
		ll a,b,c;
		cin>>a>>b>>c;
		if (b>=a) {
			cout<<"1\n";
		} else if (c>=b) {
			cout<<"error\n";
		} else {
			if ((a-b)%(b-c)==0) {
				cout<<(a-b)/(b-c)+1<<"\n";
			} else {
				cout<<(int)ceil(1.0*(a-b)/(b-c))+1<<"\n";
			}
		}
	}

	return 0;
}

