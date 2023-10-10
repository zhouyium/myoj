#include<bits/stdc++.h>
using namespace std;

queue <int> a;
queue <int> b; 

int main(){
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);

	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		int x;
		cin>>x;
		if (x%2==1){
			a.push(x);
		}else{
			b.push(x);
		} 
	}
	
	for (;a.empty()==0 || b.empty()==0;){
		if (a.empty()==0){
			cout<<a.front()<<" ";
			a.pop();
		}
		if (a.empty()==0){
			cout<<a.front()<<" ";
			a.pop();
		}
		if (b.empty()==0){
			cout<<b.front()<<" ";
			b.pop();
		}
	}
	cout<<"\n";
	
	return 0;
}
