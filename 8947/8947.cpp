//8947: DP36 abb
//http://47.110.135.197/problem.php?id=8947

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;

void solve() {
	LL n;
	string s;
	cin>>n;
	cin>>s;
	
	unordered_map<char, LL> mp1;//记录此字符还有多少个
	unordered_map<char, LL> mp2;//记录此字符已经出现了多少个
	for(const auto &ch : s){
		mp1[ch]++;//先记录总的字符数
	}
	
	LL res=0;
	for(LL i=0;i<n;i++){
		char ch=s[i];
		mp1[ch]--;//遇到的字符则还有的数量-1
		mp2[ch]++;
		if(mp1[ch]>0){
			//说明还有字符
			//(i+1-mp2[c])得到a的数量
			//mp1[c]是可能的bb数量
			res+=(i+1-mp2[ch])*mp1[ch];
		}
	}
	
	cout<<res<<"\n";
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
	int n=5;
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
