//8536: Rooted Trees
//http://47.110.135.197/problem.php?id=8536
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+10;
vector<LL> tree[N];
LL a[N];
LL f[N];//f[i]表示节点i的父亲是f[i] 
//DSU 
LL fa[N];
void init(LL n){
	for(LL i=0;i<=n;i++){
		fa[i]=i;
		a[i]=i;
	}
}
LL find(LL x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

LL ran(LL l=1,LL r=5e5) {
    if (l>r) {
        swap(l,r);
    }
    return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);

    freopen("12.in", "w", stdout);

    LL maxx = 1e5;
    LL minx = 1e5;
    LL T = 1;
    //cout<<T<<"\n";

    while (T--)	{
        LL n = 30;//ran(1e5, 1e5);
#if 1
		for(LL i=0;i<n;i++){
			a[i]=i;
			f[i]=i-1;
		}
		LL root=0;
#else    	
        init(n);
        //生成root 
        LL root=ran(0,n-1);
        for(LL i=0;i<n;i++){
        	if(i==root){
        		continue;
			}
			LL fath;
			LL fi=find(i);
			LL ff;
			do {
				fath=ran(0,n-1);
				ff=find(fath);
			}while(fi==ff);
			f[i]=fath;
			fa[fi]=ff;
		}
#endif		
		
		//生成对应数据
		for(LL i=0;i<n;i++){
			if(root==i){
				continue;
			}
			tree[f[i]].push_back(i);
		}
#if 0		
		cout<<root<<"\n";
		for(LL i=0;i<n;i++){
			cout<<f[i]<<" ";
		}
		cout<<"\n\n";
#endif		
		//输出
		random_shuffle(a,a+n); 
        cout<<n<<"\n";
        for(LL i=0;i<n;i++){
        	LL id=a[i];
        	cout<<id<<" "<<tree[id].size()<<" ";
        	for(const auto &v:tree[id]){
        		cout<<v<<" ";
			}
			cout<<"\n";
		}
    }

    return 0;
}
