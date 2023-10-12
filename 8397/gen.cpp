//8397: Cops and the Thief Devu
//http://47.110.135.197/problem.php?id=8397
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
    
    freopen("04.in", "w", stdout);
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 1e4;
	cout<<T<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=9;
		maxx=10;
		LL m = rand()%(maxx-minx+1)+minx;
		minx=1;
		maxx=3;
		LL x = rand()%(maxx-minx+1)+minx;
		minx=2;
		maxx=5;
		LL y = rand()%(maxx-minx+1)+minx;
		cout<<m<<" "<<x<<" "<<y<<"\n";
		
		//n个数据
		LL j;
		for (j=1; j<=m; j++) {
			minx=1;
			maxx=1e2;
			a[j] = rand()%(maxx-minx+1)+minx;
		}
		random_shuffle(a+1,a+m+1);

		for (j=1; j<=m; j++) {
			cout<<a[j]<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
