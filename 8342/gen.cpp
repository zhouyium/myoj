//8342: �󺽺�ʱ��
//http://47.110.135.197/problem.php?id=8342
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("05.in", "w", stdout);
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 1;
	//cout<<n<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//���� N
		minx=500;
		maxx=500;
		LL n = rand()%(maxx-minx+1)+minx;
		minx=5e4;
		maxx=5e4;
		LL m = rand()%(maxx-minx+1)+minx;
		minx=10;
		maxx=10;
		LL k = rand()%(maxx-minx+1)+minx;
		cout<<n<<" "<<m<<" "<<k<<"\n";
		
		//n������
		for (LL j=1; j<=n; j++) {
			minx=1;
			maxx=1e2;
			LL w = rand()%(maxx-minx+1)+minx;
			minx=5e2;
			maxx=1e3;
			LL v = rand()%(maxx-minx+1)+minx;
			cout<<w<<' '<<v<<"\n";
		}
		cout<<"\n";
	}
	
    return 0;
}
