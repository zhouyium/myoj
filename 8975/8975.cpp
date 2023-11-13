//8975: Coins I
//http://47.110.135.197/problem.php?id=8975

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e2+10;
double two[N];
/*
每次选k个中t个为正面的概率为c(k,t)*0.5^k，所以需要预处理一下100以内的组合数，否则会超时。  
 */
double C[N][N];
double f[N][N];
/*
f[i][j]表示第i次操作，正面朝上的有j个的概率。
如果j<=n-k,因为取最优策略，所以不会有正面硬币被选来抛。
反之有可能有正面硬币被抛为反面，所以当j超过n-k时，不管j超过多少，
  硬币为正面的个数都为n-k加上本次抛的为正面的个数，因为原来为正面的也需要重新抛。
 */

void solve() {
	LL n,m,K;
	cin>>n>>m>>K;
	
	//初始化
	for(LL i=0;i<=m;i++){
		for(LL j=0;j<=n;j++){
			f[i][j]=0;
		}
	}
	f[0][0]=1;
	for(LL i=0;i<m;i++){
		for(LL j=0;j<=n;j++){//枚举up
			for(LL x=0;x<=K;x++){//枚举我要反过来x个,最多k个
				double p=C[K][x]*two[K];//从k个中选x个抛成正的概率
				if(n-j>=K){//直接反所有down的
					f[i+1][j+x]+=f[i][j]*p;
				}else{
					//反的全选，再选一部分正的，用原来正n-k加上现在弄正的x个0
					f[i+1][n-K+x]+=f[i][j]*p;
				}
			}
		}
	}
	
	//答案
	double res=0;
	for(LL i=0;i<=n;i++){
		res+=f[m][i]*i;
	}
	cout<<fixed<<setprecision(4)<<res<<"\n";
}

int main() {
	C[0][0]=1;//特殊
	for(LL i=1;i<=100;i++){
		for(LL j=0;j<=i;j++){
			if(j==0){
				C[i][j]=1;
			}else{
				C[i][j]=C[i-1][j]+C[i-1][j-1];
			}
			
		}
	}
	
	two[0]=1;
	for(LL i=1;i<=100;i++){
		two[i]=two[i-1]*0.5;
	}

#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	cin>>T;
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
