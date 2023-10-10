#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

void solve() {
	string s,t;
	cin>>s>>t;
	//构造答案，按照最大字典序 
	string res(s.size(),'z');
	string tmp;
	for(LL i=0;i<=s.size()-t.size();i++){
		bool flag=true;
		tmp=s;
		for(LL j=0;j<t.size();j++){
			if(s[i+j]!='?' && t[j]!=s[i+j]){
				flag=false;
				break;
			}
		}
		
		if(flag){
			tmp.replace(i, t.size(), t);
			for(LL j=0; j<tmp.size(); j++){
				if(tmp[j]=='?'){
					tmp[j]='A';
				}
			}
			if(tmp<res){
				res=tmp;
			}
		}
	}
	
	cout<<res<<"\n";
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

