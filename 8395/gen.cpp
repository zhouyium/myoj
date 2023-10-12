//8395: 质数王国问题
//http://47.110.135.197/problem.php?id=8395
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e7+10;
bool vis[N];
LL primes[N], cnt;

void euler(LL n) {
	for (LL i=2;i<=n;i++) {
		if (vis[i]==false) {
			primes[++cnt]=i;
		}
		for (LL j=1;j<=cnt && primes[j]*i<=n;j++) {
			vis[primes[j]*i]=true;
			if (i%primes[j]==0) {
				break;
			}
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
    
    euler(1e7); 
    cout<<"cnt="<<cnt<<"\n";
    
    //freopen("04.in", "w", stdout);
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 10;
	cout<<T<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		while (1) {
			//数字 N
			minx=1;
			maxx=100;
			LL pos1 = rand()%(maxx-minx+1)+minx;
			LL p=primes[pos1];
			minx=cnt-100;
			maxx=cnt;
			LL pos2 = rand()%(maxx-minx+1)+minx;
			LL q=primes[pos2];
			if (pos1==pos2) {
				continue;
			}
			//LL t=p*p*q;
			LL t=q*q*p;
			if (0<t && t<=1e18) {
				cout<<t<<"\n";
				//cout<<"p="<<p<<",q="<<q<<"\n";
				break;
			}			
		}
	}
	
    return 0;
}
