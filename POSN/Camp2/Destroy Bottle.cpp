/*
TASK: Destroy Battle
AUTHOR: passa
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	long long nu,att;
	bool operator < (const A& o)const{
		return nu<o.nu;
	}
};
A a[100100];
long long b[100100],c[100100],mark[100100],ch[100100];
int main(){

	long long n,m,cnt,ans,idx,i,num,j;
	scanf("%lld %lld",&n,&m);
	cnt=n;
	for(i=1 ; i<=n ; i++){
		scanf("%lld",&a[i].nu);
		a[i].att=i;
	}
	sort(a+1,a+n+1);
	for(i=1 ; i<=n ; i++)
		b[i]=a[i].nu,c[i]=a[i].att;
	for(j=1 ; j<=m ; j++){
		scanf("%lld",&num);
		ans=0;
		for(i=cnt ; i>=1 ; i--){
			if(b[i]<=num) {
				cnt=i; break;
			}
			if(mark[c[i]]&&mark[c[i]]!=j) continue;
			if(mark[c[i]]!=j) ans++,mark[c[i]]=j;
			if(c[i]+1<=n&&!mark[c[i]+1]) ans++,mark[c[i]+1]=j;
			if(c[i]-1>=1&&!mark[c[i]-1]) ans++,mark[c[i]-1]=j;
		}
		printf("%lld\n",ans);
	}	
	return 0;
}

