#include <stdio.h>
#define N 1010
struct schedule
{
	int begin;     //开始时间 
	int end;       //结束时间 
}meet[N],t;

int main()
{
	int i,j,n,ans=1,record;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d%d",&meet[i].begin,&meet[i].end);
	
	for(i=0;i<n-1;i++)
	{ 
		for(j=i+1;j<n;j++)
		{ 
		    if(meet[i].end > meet[j].end)
		    {
		      	t=meet[i];
		      	meet[i]=meet[j];
		      	meet[j]=t;
		    }
		}
	}
	
	record=meet[0].end;              //第一个结束时间 
	for(i=1;i<n;i++)
	{
		if(meet[i].begin >= record)  //开始时间不冲突 
		{
			ans++;
			record=meet[i].end;      //更新结束时间
		}
	}
	printf("%d\n",ans);
	return 0;
}
