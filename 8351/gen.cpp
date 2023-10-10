//8351: 找新朋友
//http://47.110.135.197/problem.php?id=8351
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=2e6+10;
bool st[N];
LL primes[N],cnt;
LL phi[N];

void euler(LL n) {
	phi[1]=1;
	for (LL i=2;i<=n;i++) {
		if (st[i]==false) {
			primes[++cnt]=i;
			phi[i]=i-1;
		}
		//遍历所有的素数 
		for (LL j=1;primes[j]*i<=n;j++) {
			LL t=primes[j]*i;
			st[t]=true;
			if (i%primes[j]==0) {
				phi[t]=phi[i]*primes[j];
				break;
			}
			phi[t]=phi[i]*(primes[j]-1);
		}
	}
}

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    euler(32768); 
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 1;
	//cout<<n<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=1e4;
		maxx=1e4;
		LL n = rand()%(maxx-minx+1)+minx;
		cout<<n<<"\n";
		
		//n个数据
		for (LL j=1; j<=n; j++) {
			minx=10000;
			maxx=32767;
			LL w = rand()%(maxx-minx+1)+minx;
			cout<<w<<"\n";
		}
	}
	
    return 0;
}
