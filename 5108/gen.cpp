#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
string name[MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    int T=100;
    printf("%d\n", T);
    while (T--) {
	    //����n,m
	    ll maxx = 2000;//1000λ
	    ll minx = 2000;
	    ll n = rand()%(maxx-minx+1)+minx;
	    printf("%lld\n", n);
	
		//����m������ 
	    maxx = n/9;//1000λ
	    minx = n/10;
	    ll m = rand()%(maxx-minx+1)+minx;
		for (ll i=1; i<=m; i++) {
			int len=rand()%10+5;
			for (int j=1; j<len; j++) {
				char ch=rand()%26+'a';
				name[i].push_back(ch);
			}
		}
		
		//���n�� 
	    maxx = m;//1000λ
	    minx = 1;
		for (ll i=1; i<=n; i++) {
			ll t = rand()%(maxx-minx+1)+minx;
			cout<<name[t]<<"\n";
		}
		
		//
		for (int i=1; i<=m; i++) {
			name[i].clear();
		}
	}
    
    return 0;
}
