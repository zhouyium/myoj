//5775
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
	
	ll maxx=1e6;
	ll minx=1e6;
	ll n = rand()%(maxx-minx+1)+minx;
	maxx=1e6;
	minx=1e6;
	ll m = rand()%(maxx-minx+1)+minx;
	cout<<n<<" "<<m<<"\n";
	
	maxx=n;
	minx=1;
	while (m--) {
		ll q=rand()%(maxx-minx+1)+minx;
		cout<<q<<"\n";
	}

    return 0;
}
