#include<stdio.h>
#include<bitset>
#include<string.h>
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<assert.h>
#include<utility>
using namespace std;

typedef long long int ll;

#define For(i,s,e) for(int i=(s);i<=(e);i++)
#define mp(a,b)	make_pair((a),(b))

void Get_x_and_y(pair<ll,ll> &x,int a,int b)	//1 possible x and y for ax+by = 1
{
	if ( a>b ) 	swap(a,b);	//b > a always!
	int z = b%a;
	if ( z==0 )	return;
	Get_x_and_y(x,z,a);
	x = make_pair(x.second , x.first - x.second*(ll)(b/a));
}

int main()
{
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);	//taking the equation ax+by = c
		int gcd = __gcd(a,b);
		if ( c % gcd != 0)	printf("No Solution\n");
		else{
			pair<ll,ll> x_y=make_pair(0,1);
			Get_x_and_y(x_y,a/gcd,b/gcd);
			printf("%lld %lld\n",x_y.first*(c/gcd) , x_y.second*(c/gcd));
		}
	}
	return 0;
}
