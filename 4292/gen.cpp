//4292: ��ȫ��������
//http://47.110.135.197/problem.php?id=4292

#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e2+10;
bool a[N];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("02.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //����n,x,y
	    LL maxx = 600;
	    LL minx = 600;
	    LL m = rand()%(maxx-minx+1)+minx;
	    maxx=30;
	    minx=30;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<m<<" "<<n<<"\n";
	    
		for (LL i=1; i<=n; i++) {
			maxx=200;
			minx=100;
    		LL w = rand()%(maxx-minx+1)+minx;
			maxx=1e4;
			minx=1e3;
    		LL c = rand()%(maxx-minx+1)+minx;
    		cout<<w<<" "<<c<<"\n";
		}
		cout<<"\n";
	}

    return 0;
}
