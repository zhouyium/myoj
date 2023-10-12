#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;
map<string,LL> mp;
struct NODE {
	LL val;
	string name;
} a[10];

bool mycmp(const NODE& x, const NODE &y) {
	return x.val < y.val;
}

void solve() {
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		string s;
		LL x;
		cin>>s>>x;
		a[mp[s]].val +=x;
		a[mp[s]].name = s;
	}
	sort(a+1, a+8, mycmp);
	
	//找到倒数第二小的值 
	LL x=a[1].val;
	for (LL i=1; i<=7; i++) {
		if (a[i].val!=x) {
			x=a[i].val;
			break;
		}
	}
	//统计倒数第二小有几个
	string ans;
	LL cnt=0;
	for (LL i=1; i<=7; i++) {
		if (a[i].val==x) {
			ans = a[i].name;
			cnt++;
		}
	}	 
	
	if (cnt==1) {
		cout<<ans<<"\n";
	} else {
		cout<<"Tie\n";
	}
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie (0);
	
	mp["Bessie"] = 1;
	mp["Elsie"] = 2;
	mp["Daisy"] = 3;
	mp["Gertie"] = 4;
	mp["Annabelle"] = 5;
	mp["Maggie"] = 6;
	mp["Henrietta"] = 7;
	
	

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

