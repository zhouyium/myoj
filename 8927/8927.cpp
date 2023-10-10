/*
����� f_{i,j} Ϊ���� i ��λ��ǰ��Ķ��Ϸ������һ�κ�Ϊ j �Ƿ���У���ôת��ʮ����Ȼ������״̬��ը��
��ʱ���ǿ�����״̬�Ͻ����Ż�������ʱ�䣬�� f_i ��Ϊ���� i
 ��λ�÷ֶ�������������������һ�κ����ٵĺͣ��Լ��ֳܷɼ��ξͺ��ˡ�
 
*/
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e5+10;
LL a[N],s[N];
LL f[N][2];//����ֶξ����ܶ������£����һ�κ͵���Сֵ

LL cnt;
LL rt;

LL mx[7000005],ls[7000005],rs[7000005];//�����޸ģ������ѯ
bool cmp(int i,int j){//i �Ƿ�� j ��
    if(i==0)return false;
    if(j==0)return true;
    if(f[i][0]<f[j][0])return false;
    else if(f[i][0]==f[j][0]){
        if(i<j)return false;
        return true;
    }
    return true;
}
void update(int l,int r,LL &k,int x,int y){
    if(!k)k=++cnt;
    if(l==r){
        if(!cmp(mx[k],y))mx[k]=y;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid)update(l,mid,ls[k],x,y);
    else update(mid+1,r,rs[k],x,y);
    if(cmp(mx[ls[k]],mx[rs[k]]))mx[k]=mx[ls[k]];
    else mx[k]=mx[rs[k]];
}
int query(int l,int r,int k,int x,int y){
    if(x<=l&&y>=r)return mx[k];
    int mid=l+r>>1,res=0;
    if(x<=mid)res=query(l,mid,ls[k],x,y);
    if(y>mid){
        int tmp=query(mid+1,r,rs[k],x,y);
        if(cmp(tmp,res))res=tmp;
    }
    return res;
}

void solve() {
	LL n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
#if 1
    for(int i=1;i<=n;i++){
        int j=query(1,INF,1,1,s[i]);
        f[i][0]=f[j][0]+1;
        f[i][1]=s[i]-s[j];
        update(1,INF,rt,s[i]+f[i][1],i);
    }
#else
	//O(n^2)
    for(int i=1;i<=n;i++){
        f[i][0]=1;
        f[i][1]=s[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(s[i]-s[j]>=f[j][1]&&f[j][0]+1>=f[i][0]){
                if(f[j][0]+1==f[i][0])f[i][1]=min(f[i][1],s[i]-s[j]);
                else{
                    f[i][0]=f[j][0]+1;
                    f[i][1]=s[i]-s[j];
                }
            }
        }
    }
#endif
    cout<<f[n][0]<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("09.in", "r", stdin);
	freopen("09.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

