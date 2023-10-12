//http://47.110.135.197/problem.php?id=6260
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
int a[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("07.in", "w", stdout);
    
    //生成n个顶点，m条边 
    LL maxx = 1e3;//1000位
    LL minx = 1e3;
    LL n = rand()%(maxx-minx+1)+minx;
	cout<<n<<" "<<n<<"\n";
	
	for (LL i=1; i<=n; i++) {
		for (LL j=1; j<=n; j++) {
		    minx = 1;
		    maxx = 100;
		    LL t = rand()%(maxx-minx+1)+minx;
		    if (t>=20) {
		    	cout<<"1 ";
			} else {
				cout<<"0 ";
			}
		}
		cout<<"\n";
	}
    
	for (LL i=1; i<=n; i++) {
		cout<<i<<"\n";
	}

    return 0;
}
