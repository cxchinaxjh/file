#include<bits/stdc++.h>
using namespace std;
int a[100100];
int b[100100];
bool qz[100100*4];
bool hz[100100*4];
bool wq[100100*4];
int Hz[100100*4];
int Qz[100100*4];
int Wq[100100*4];
int ans[100100*4];
int read()
{
    int sum=0,fh=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){sum=(sum<<3)+(sum<<1)+(ch^48);ch=getchar();}
    return sum*fh;
}
void upd(int p)
{
	hz[p]=wq[p]=qz[p]=0;
	wq[p]=wq[p<<1]&wq[p<<1|1];//如果整个块全部大于等于0 
	if(wq[p])
	Wq[p]=Wq[p<<1]+Wq[p<<1|1];//累计总和 
	if(!wq[p])
	hz[p]=hz[p<<1|1]|wq[p<<1|1];//如果不是整个块大于等于0，判断右边一整块和右边靠右的部分 
	if(hz[p])
	{
		if (hz[p<<1|1]) Hz[p]=Hz[p<<1|1];//如果是右边靠右的部分，直接赋值 
		else Hz[p]=Hz[p<<1]+Wq[p<<1|1];//否则就是一整块可以，考虑加上左儿子靠右的部分 
	}
	if(!wq[p])
	qz[p]=qz[p<<1]|wq[p<<1];//同理考虑左边一整块和左边靠左的部分 
	if(qz[p])
	{
		if(qz[p<<1])Qz[p]=Qz[p<<1];
		else Qz[p]=Wq[p<<1]+Qz[p<<1|1];
	}
	ans[p]=(ans[p<<1]+ans[p<<1|1]);//从左右两个块中合并结果 
	if(Hz[p<<1]+Qz[p<<1|1]>0&&!wq[p<<1]&&!wq[p<<1|1])ans[p]++;//如果左右两段合成了一个非零段，且该段不可能在和其他段相连，累计答案 
	if(!hz[p])Hz[p]=0;//如果最右端不存在大于等于0的段，就不存在这一长度 
	if(!qz[p])Qz[p]=0;//同上 
	if(!wq[p])Wq[p]=0;
}
void modify(int p,int l,int r,int x,int v)
{
	if(l==r)
	{
		if(v>=0)
		{
			wq[p]=1;
			Wq[p]=v;
		}
		else
		{
			wq[p]=0;
			Wq[p]=0;
		}
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)modify(p<<1,l,mid,x,v);
	if(x>mid)modify(p<<1|1,mid+1,r,x,v);
	upd(p);
}
void clr(int p,int l,int r)
{
	hz[p]=qz[p]=wq[p]=Hz[p]=Qz[p]=Wq[p]=ans[p]=0;
	if(l==r)return;
	int mid=l+r>>1;
	clr(p<<1,l,mid);
	clr(p<<1|1,mid+1,r);
}//建线段树 
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),Q=read();
		for(int i=0;i<=n+1;++i)a[i]=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			b[i]=0;
		} 
		if(n==1)
		{
			for(int i=1;i<=Q;++i)
			{
				int l,r;
				int v;
				int opt=read();
				if(opt==0)
				{
					puts("0 0");
				}
				else {l=read();r=read();v=read();}
			}
			return 0;
		}
		if(n==2)
		{
			for(int i=1;i<=Q;++i)
			{
				int l,r;
				int v;
				int opt=read();
				if(opt==0)
				{
					if(a[2]>a[1])
					{
						printf("%d %d\n",a[2]-a[1],2);
					}
					else puts("0 0");
				}
				else 
				{
					l=read();r=read();v=read();
					for(int i=l;i<=r;++i)
					{
						a[i]+=v;
					}
				}
			}
			return 0;
		} //特判1和2的两种情况 
		for(int i=1;i<n;++i)
		{
			b[i]=a[i+1]-a[i];
		}
		long long Ans=0;
		b[0]=-1;
		b[n]=-1;
		clr(1,1,n);
		for(int i=1;i<n;++i)
		{
			modify(1,1,n-1,i,b[i]);
			if(b[i]>=0)
			{
				Ans+=b[i];
			}
		}
		for(int i=1;i<=Q;++i)
		{
			int opt=read();
			if(opt==1)
			{
				printf("%lld ",Ans);
				int tmp=ans[1];
				if(qz[1]&&Qz[1]>0)tmp++;//累计 靠左部分 
				if(hz[1]&&Hz[1]>0)tmp++;//累计 靠右部分 
				if(wq[1]&&Wq[1]>0)tmp++;//累计 一整个都是 
				printf("%d\n",tmp*2);
			} 
			else
			{
				int l=read()-1,r=read(),v=read();
				if(l>=1&&l<n)
				{
					Ans-=max(b[l],0);b[l]+=v;Ans+=max(b[l],0);
					modify(1,1,n-1,l,b[l]);
				}
				if(r>=1&&r<n)
				{
					Ans-=max(b[r],0);b[r]-=v;Ans+=max(b[r],0);
					modify(1,1,n-1,r,b[r]);
				}
			}
		}
	}
	return 0;
}
