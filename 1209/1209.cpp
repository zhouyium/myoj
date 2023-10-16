//1209: 最长单词
//http://47.110.135.197/problem.php?id=1209

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;

void solve() {
	string str;
	getline(cin, str);
	
	//分析s
	LL n=0;
	LL maxx=0;
	string ans;
	string s;//当前分析的字符串
	for(const auto &c : str){
		if (c=='.'){
			//.表示结束
			if(n>maxx){
				maxx=n;
				ans=s;
			}
			break;
		}
		if(c==' '){
			if(n>maxx){
				maxx=n;
				ans=s;
			}
			n=0;
			s.clear();
		}else{
			s=s+c;
			n++;
		}
	}
	cout<<ans<<"\n";
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	int n=10;
	for(int i=0;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif
	
	return 0;
}
