#include <bits/stdc++.h> 
using namespace std;

const int MAXN=1e3+4;
bool bj[MAXN];

int main() {
	freopen("9.in", "w", stdout);
	srand(time(NULL));
	//Éú³É t 1 ~ 10
	int n=rand()%1000+1;
	n=1000;
	cout<<n<<"\n";
	for (int i=1; i<=n; ) {
		int x=rand()%n+1;
		if (false==bj[x]) {
			bj[x]=true;
			cout<<x<<" ";
			i++;
		}
	}
	
	return 0;
}
