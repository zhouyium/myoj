#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
char d[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void solve() {
	LL n;
	cin>>n;
	string s;
	cin>>s;
	LL m;
	cin>>m;
	if (n==m) {
		cout<<s<<"\n";
		return;
	}
	
	if (s[0]=='-') {
		cout<<"-";
		s=s.substr(1,s.size());
	} else if (s[0]=='+') {
		s=s.substr(1,s.size());
	}
	//n->10
	LL val=0;
	for (LL i=s.size()-1;i>=0;i--) {
		LL t;
		if ('0'<=s[i]&&s[i]<='9') {
			t=s[i]-'0';
		} else if ('A'<=s[i]&&s[i]<='Z') {
			t=s[i]-'A'+10;
		} else if ('a'<=s[i]&&s[i]<='z') {
			t=s[i]-'a'+10;
		}
		val=val+t*pow(n,s.size()-i-1);
	}

	//10->m
	string ans;
	while (val) {
		LL t=val%m;
		ans.push_back(d[t]);
		val/=m;
	}
	
	for (LL i=ans.size()-1;i>=0;i--) {
		cout<<ans[i];
	}
	cout<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}
