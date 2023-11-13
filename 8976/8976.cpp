//8976: Coin II
//http://47.110.135.197/problem.php?id=8976

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;

/*
令q=1-p，则出现偶数次数改为Y为
  Y=C_n^0*q^n+C_n^2*p^2*q^{n-2}+...
即为 (q+px)^n 的展开式中的 x 的偶次方的系数
亦为 (q-px)^n 的展开式中的 x 的偶次方的系数
故出现偶数次的概率 Y 为
  Y=\frac{(q+p)^n+(q-p)^n}{2}=\frac{1+(1-2p)^n}{2}
出现奇数次的概率 1-Y 为
  1-Y=\frac{1-(1-2p)^n}{2}
 */

LL qpow(LL a,LL b,LL p){
	a%=p;
	LL res=1;
	while(b){
		if(b%2){
			res=(res*a)%p;
		}
		b/=2;
		a=(a*a)%p;
	}
	return res;
}

LL exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL r=exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return r;
} 


LL inv(LL b,LL p){
	return b==1?1:(p-p/b)*inv(p%b,p)%p;
}

void solve() {
	LL p,q,K;
	cin>>p>>q>>K;
	LL ans;
#if 0
	LL x,y;
	LL temp=qpow(p,K,MO);
	exgcd(temp,MO,x,y);
	ans=(qpow(p-2*q,K,MO)*x)%MO;
	ans=1+ans;
	exgcd(2,MO,x,y);
	ans=(ans*x)%MO;
	ans=(ans+MO)%MO;
#else	
	LL zi=qpow(p,K,MO)+qpow(p-2*q,K,MO);//分子
	zi=zi%MO*inv(2,MO)%MO;
	LL mu=qpow(p,K,MO);//分母
	
	ans=zi*inv(mu,MO)%MO;
	ans=(ans+MO)%MO;
#endif	
	cout<<ans<<"\n";
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	cin>>T;
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
		cin>>T;
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
