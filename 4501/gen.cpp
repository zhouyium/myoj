#include <bits/stdc++.h> 
using namespace std;
int main() {
	freopen("9.in", "w", stdout);
	srand(time(NULL));
	//���� t 1 ~ 10
	int t=rand()%10+1;
	t=10;
	cout<<t<<"\n";
	for (int i=1; i<=t; i++) {
		//����m,n
		int m=rand()%100+1;
		m=10;
		int n=rand()%1000+1;
		n=1000;
		cout<<m<<" "<<n<<"\n";
		
		//���� n �β��� 
		for (int j=1; j<=n; j++) {
			int op=rand()%3;
			if (0==op) {
				//p
				cout<<'P';
				int x=rand()%5000000;
				cout<<' '<<x<<"\n"; 
			} else if (1==op) {
				//A
				cout<<"A\n";
			} else {
				//O
				cout<<"O\n";
			}
		}
	}
	return 0;
}
