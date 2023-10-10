#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
const int MAXM=1e3+10;
int a[MAXN][MAXM];
int main(){
	int n;
	cin>>n;
	int cnt=n;
	int x=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=cnt;
			if(1==cnt%n){
				cnt=n*x;
				x++;
			}else{
				cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<setw(3)<<a[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
