//6581: ALDS1_5_B : 归并排序
//http://47.110.135.197/problem.php?id=6581

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;
LL ans=0;
LL a[N];
LL backup[N];

void merge_sort(LL l,LL r){
	if(l>=r){
		return;
	}
	LL mid=(l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	
	LL i=l;
	LL j=mid+1;
	LL k=l;
	while(i<=mid && j<=r){
		if(a[i]>a[j]){
			backup[k++]=a[j++];
		}else{
			backup[k++]=a[i++];
		}
		ans++;
	}
	
	while(i<=mid){
		backup[k++]=a[i++];
		ans++;
	}
	
	while(j<=r){
		backup[k++]=a[j++];
		ans++;
	}
	
	k=l;
	for(LL m=l;m<=r;m++){
		a[m]=backup[k++];
	}
}

void solve() {
	ans=0;
	LL n;
	cin>>n;
	for(LL i=1; i<=n; i++){
		cin>>a[i];
	}	
	
	merge_sort(1,n);
	
	for(LL i=1;i<=n;i++){
		cout<<backup[i]<<" ";
	}
	cout<<"\n"<<ans<<"\n";	
}

int main() {
#if 0
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	int n=10;
	for(int i=6;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif
	
	return 0;
}
