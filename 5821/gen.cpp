//5821
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("10.in", "w", stdout);
    
    //生成n,m
    ll maxx = 1e5;//1000位
    ll minx = 1e5;
    ll n = rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";
    maxx=1e5;
	minx=1;
    for (ll i=1; i<=n; i++) {
    	ll x=rand()%(maxx-minx+1)+minx;
    	if (x%2==0) {
    		cout<<"-100000 ";
		} else {
			cout<<"100000 ";
		}
	}
	cout<<"\n";

    return 0;
}
