#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
struct NODE{
	LL fa;//父亲
	LL ls;//左儿子
	LL rs;//右儿子 
}a[N];

void preorder(LL u){
	//root
	cout<<u<<" ";
	//left
	if(a[u].ls!=-1){
		preorder(a[u].ls);
	}
	//right
	if(a[u].rs!=-1){
		preorder(a[u].rs);
	}
}

void inorder(LL u){
	//left
	if(a[u].ls!=-1){
		inorder(a[u].ls);
	}
	//root
	cout<<u<<" ";
	//right
	if(a[u].rs!=-1){
		inorder(a[u].rs);
	}
}

void postorder(LL u){
	//left
	if(a[u].ls!=-1){
		postorder(a[u].ls);
	}
	//right
	if(a[u].rs!=-1){
		postorder(a[u].rs);
	}
	//root
	cout<<u<<" ";
}

void solve() {
	LL n;
	cin>>n;
	//初始化 
	for(LL i=0;i<n;i++){
		a[i].fa=a[i].ls=a[i].rs=-1;
	}
	for(LL i=1;i<=n;i++){
		LL id,l,r;
		cin>>id>>l>>r;
		a[id].ls=l;
		a[id].rs=r;
		if(l!=-1){
			a[l].fa=id;
		}
		if(r!=-1){
			a[r].fa=id;
		}
	}
	
	//找到root
	LL rt;
	for(LL i=0;i<n;i++){
		if(a[i].fa==-1){
			rt=i;
			break;
		}
	}
	
	cout<<"Preorder\n";
	preorder(rt);
	cout<<"\n";
	cout<<"Inorder\n";
	inorder(rt);
	cout<<"\n";
	cout<<"Postorder\n";
	postorder(rt);
	cout<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

