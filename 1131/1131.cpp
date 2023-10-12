#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	LL a,b;
	char op;
	cin>>a>>b>>op;
	//err error
	cerr<<"a="<<a<<",b="<<b<<",op="<<op<<"\n"; 
	if(op=='+'){
		//+
		LL res=a+b;
		cout<<res<<'\n';
	}else if(op=='-'){
		//- 
		LL res=a-b;
		cout<<res<<"\n";
	}else if(op=='*'){
		//*
		LL res=a*b;
		cout<<res<<'\n';
	}else if(op=='/'){
		// /
		if(b==0){
			cout<<"Divided by zero!\n";
		}else{
			LL res=a/b;
			cout<<res<<"\n";
		}
	}else{
		//Invalid operator!
		cout<<"Invalid operator!\n";
	}
	return 0;
}
//·ÖÖÎ 

