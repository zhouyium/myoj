//http://47.110.135.197/problem.php?id=5819
//https://iai.sh.cn/problem/24
//¾ºÑ¡°à³¤

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	if (d>=85&&((a>=90&&b>=90)||(a>=90&&c>=90)||(b>=90&&c>=90))) {
		cout<<"Qualified\n";
	} else {
		cout<<"Not qualified\n";
	}

	return 0;
}

