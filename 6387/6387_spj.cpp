//
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int AC=0;
const int WA=1;

const int N=1e5+10;
LL h[N], in[N];
LL ans[N];
const int M=2e5+10;
LL e[M], ne[M], idx;
LL que[M];
LL hh, tt;
LL n;

void add(LL a, LL b) {
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
    //更新入度
    in[b]++;
}

int main(int argc,char *args[]) {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif

    ifstream f_in;
    f_in.open(args[1]); 
    ifstream f_out;
    f_out.open(args[2]); 
    ifstream f_user;
    f_user.open(args[3]); 
    
    int ret=AC;
/**************自己写判题逻辑**************/
    memset(h, -1, sizeof h);

    LL m;
    f_in>>n>>m;
    for (LL i=1; i<=m; i++) {
        LL a,b;
        f_in>>a>>b;
        add(a,b);
    }
    
    LL cnt=0; 
	LL u;
    while (f_user>>u) {
    	//cout<<"u="<<u<<"\n";
    	
    	++cnt;
    	if (cnt>n) {
    		return WA+6;
		}

    	if (u>0) {
	        if (in[u]!=0) {
	        	return WA+1;
			}
	        //遍历u的所有边
	        for (LL i=h[u]; i!=-1; i=ne[i]) {
	            LL v=e[i];
	            in[v]--;
	        }    		
		} else if (u!=-1) {
			return AC+2;
		}
    }
    if (cnt!=n) {
    	return WA+5;
	}

/************************************/
	f_in.close();
	f_out.close();
	f_user.close();
	
	return 0;
}

