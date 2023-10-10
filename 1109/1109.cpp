//1109 »ØÎÄËØÊı
#include <bits/stdc++.h>
using namespace std;
int dx (int x) {
	int ans=0; 
	while (x!=0) {
		ans=ans*10+x%10;
		x/=10;
	} 
	return ans;
}
bool hw (int x) {
	if (x!=dx(x)){
		return false;
	}
	return true;
}
bool s(int x) {
	for (int i=2;i<sqrt(x);++i) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n,ans=0;
	cin>>n; 

	for (int i=11;i<=n;++i) {
		if (s(i) && hw(i)) {
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
