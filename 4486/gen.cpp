//4486
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
//欧拉筛
const int MAXN=1.4e9+10;
bool vis[MAXN];//可见性
const int MAXM=1e8+10;
int  pri[MAXM];//

void euler(ll n) {
	vis[1]=true;
	for (ll i=2; i<=n; i++) {
		if (!vis[i]) {
			pri[++pri[0]]=i;//保存质数 
		}
		//筛 
		for (ll j=1; j<=pri[0]&&i*pri[j]<=n; j++) {
			vis[i*pri[j]]=true;
			if (i%pri[j]==0) {
				break;
			}
		}
	}
}

bool is_prime(int x) {
	if (x<=1) {
		return false;
	}
	for (int i=2; i*i<=x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    //freopen("0.in", "w", stdout);
	//筛出sqrt(2e9)内的质数
	euler(MAXN-1);
	
	//任意选择两个素数
	ll maxx=10;
	ll minx=1;
	ll n = rand()%(maxx-minx+1)+minx;
	minx=pri[0]-10;
	maxx=pri[0];
	ll m = rand()%(maxx-minx+1)+minx;
	ll ans=pri[m]*pri[n];
	if (ans<=2e9) {
		cout<<ans<<"\n";
	}

    return 0;
}
