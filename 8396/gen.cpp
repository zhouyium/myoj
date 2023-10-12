//8396: Ups and Downs
//http://47.110.135.197/problem.php?id=8396
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;
LL a[N];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("03.in", "w", stdout);
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 6;
	cout<<T<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=100;
		maxx=200;
		LL n = 1e5; 
		cout<<n<<"\n";
		
		//n个数据
		LL j;
		for (j=1; j<=n; j++) {
			minx=8e8;
			maxx=1e9;
			a[j] = rand()%(maxx-minx+1)+minx;
		}
		random_shuffle(a+1,a+n+1);

		for (j=1; j<=n; j++) {
			cout<<a[j]<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
