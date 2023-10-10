//http://47.110.135.197/problem.php?id=5687
//5687: IPµÿ÷∑

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("9.in", "r", stdin);
	//freopen("9.out", "w", stdout);
	string s;
	cin>>s;
	int x[4]={};
	for (int i=0; i<4; i++) {
		for (int j=0; j<8; j++) {
			x[i]=x[i]+(s[31-i*8-j]-'0')*pow(2, j);
		}
	}
	cout<<x[3]<<"."<<x[2]<<"."<<x[1]<<"."<<x[0]<<"\n";

	return 0;
}

