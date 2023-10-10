//5462
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif	
    int seed = time(NULL);
    if (argc>1) {
        //ÓÐ²ÎÊý
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
	
	ll maxx=50000;
	ll minx=50000;
	ll T = rand()%(maxx-minx+1)+minx;
	maxx=100;
	minx=90;
	ll x = rand()%(maxx-minx+1)+minx;
	cout<<T<<" "<<x<<"\n";
	maxx=100;
	minx=1;
	while (T--) {
		ll a=rand()%(maxx-minx+1)+minx;
		cout<<a<<" ";
	}
	cout<<"\n";

    return 0;
}
