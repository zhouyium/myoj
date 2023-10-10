//http://47.110.135.197/problem.php?id=5822

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	string s;
	cin>>s;
	//cout<<s<<"\n";
	bool fh=false;//·ûºÅ
	bool fd=false;//µã
	for (int i=0; i<s.length(); i++)  {
		if ('-'==s[i]||'+'==s[i]) {
			if (i!=0) {
				cout<<"Invalid\n";
				return 0;
			}
			fh=true;
		} else if ('.'==s[i]) {
			if (true==fd) {
				cout<<"Invalid\n";
				return 0;
			}
			fd=true;
		} else if (s[i]>'9'||s[i]<'0') {
			cout<<"Invalid\n";
			return 0;
		}
	}
	if (s.length()==1&&(s[0]=='.'||s[0]=='-'||s[0]=='+')) {
		cout<<"Invalid\n";
	} else {
		cout<<"Valid\n";
	}

	return 0;
}

