//4290: 老周计数
//http://47.110.135.197/problem.php?id=4290
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=2e6+10;
//欧拉晒
LL primes[N],cnt;
bool vis[N];
 
void euler(LL n){
    vis[0]=true;
    vis[1]=true;
    for(LL i=2;i<=n;i++){
        if(vis[i]==false){
            primes[++cnt]=i;
        }
        for(LL j=1;j<=cnt&&i*primes[j]<=n;j++){
            vis[i*primes[j]]=true;
            if(i%primes[j]==0){
                break;
            }
        }
    }
}

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("10.in", "w", stdout);
    
    euler(2e6);
    
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(1e3,1e3);
		LL m = ran(1,n);
		cout<<n<<"\n";
		//ai
		for(LL i=1;i<=n;i++){
			LL x = ran(cnt*5/6,cnt);
			LL y = ran(0,0);
			LL z = ran(1,2);
			if(z==1){
				swap(x,y);
			}
			cout<<x<<" "<<y<<"\n";
		}
	}
	
    return 0;
}
