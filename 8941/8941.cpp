//8941: DP21 正则表达式匹配
//http://47.110.135.197/problem.php?id=8941
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
bool f[N][N];//str的前i个字符str[1...i]与pattern的前j个字符pattern[1...j]是否匹配。

string s,p;

void solve() {
	cin>>s>>p;
	s=" "+s;
	p=" "+p;
	LL n=s.size();
	LL m=p.size();
	
	//初始化
	//空pattern 只与 空str 匹配
	f[0][0]=1;
	for(LL i=1;i<n;i++){
		// 空pattern 与 任何非空str 都不匹配
		f[i][0]=false;
	}
	//f[0][j]
	for(LL j=1;j<m;j++){
		if(j%2==0 && p[j]=='*'){
			// 空str 只与类似 a*b*c* 的pattern匹配
			f[0][j]=f[0][j-2];
		}else{
			f[0][j]=false;
		}
	}
	
	//bottom-up calc
	for(LL i=1;i<n;i++){
		for(LL j=1;j<m;j++){
			if(p[j]==s[i] || p[j]=='.'){
				// pattern[j]可以与str[i]匹配，并且用掉了pattern[j]
				f[i][j]=f[i-1][j-1];
				continue;
			}
			
			if(p[j]=='*' && (p[j-1]==s[i] || p[j-1]=='.')){
				// str[i]可以与「pattern[j-1]*」匹配，用掉了一个*
				// 也可以令「pattern[j-1]*」出现0次，与pattern[1...j-2]匹配
				f[i][j]=f[i-1][j]||f[i][j-2];
				continue;
			}
			
			if(p[j]=='*' && p[j-1]!=s[i]){
				// str[i]和「pattern[j-1]*」不匹配，让「pattern[j-1]*」出现0次
				f[i][j]=f[i][j-2];
				continue;
			}
			
			// pattern[j]是字母但 pattern[j]!=str[i]
			f[i][j]=false;
		}
	}
	
	if(f[n-1][m-1]){
		cout<<"true\n";
	}else{
		cout<<"false\n";
	}
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
	for(int i=0;i<16;i++){
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
