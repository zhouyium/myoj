//8419: straax'aks Array
//http://47.110.135.197/problem.php?id=8419
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
    
    freopen("01.in", "w", stdout);
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//数字 N
		minx=500;
		maxx=500;
		LL n = rand()%(maxx-minx+1)+minx;
		minx=7e4;
		maxx=1e7;
		LL m = rand()%(maxx-minx+1)+minx;
		cout<<n<<" "<<m<<"\n";
		
		//n个数据
		minx=35;
		maxx=5e2;
		for (LL i=1; i<=n; i++) {
			a[i] = rand()%(maxx-minx+1)+minx;
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
	
    return 0;
}
