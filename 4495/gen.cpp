#include <bits/stdc++.h> 
using namespace std;
int main() {
	freopen("2.in", "w", stdout);
	srand(time(NULL));
	//���� t 1 ~ 10
	int n=rand()%50000+1;
	cout<<n<<"\n";
	for (int i=1; i<=n; i++) {
		//����m,n
		int op=rand()%3;
		if (0==op) {
			cout<<"insert ";
			int x=rand()%1000000000;
			cout<<' '<<x<<"\n"; 
		} else if (1==op) {
			cout<<"delete\n";
		} else {
			cout<<"MinElement\n"; 
		}
	}
	return 0;
}
