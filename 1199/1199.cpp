//5332: æÿ’Ûºı∑®
//http://47.110.135.197/problem.php?id=5332
#include<bits/stdc++.h>
using namespace std;
const int ZDN=1e3+8;
const int ZDM=1e3+8;
long long sz[ZDN][ZDM]={};
long long sz2[ZDN][ZDM]={};
int main(){
	freopen("07.in", "r", stdin);
	freopen("07.out", "w", stdout);
	
	long long n,m;
	cin>>n>>m;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin>>sz[i][j];
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin>>sz2[i][j];
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cout<<sz[i][j]+sz2[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
