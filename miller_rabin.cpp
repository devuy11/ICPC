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

//works for numbers less than 2^63
//           for every prime(a) from 2 to 23 //note N shd be > than a
//					x=powmod(a,N-1,N);
//					if(x!=1)	return false;
//			 return true

ll prime[]={2,3,5,7,11,13,17,19,23};
ll mulmod(ll a,ll b,ll c)		//a*b % c
{
	ll res=0;
	while ( b )
	{
		if ( b & 1 ) 
		{
			res=(res+a)%c;
			-- b ;
		}
		a=(a<<1)%c ;
		b >>= 1 ;
	}
	return res;
}
ll powmod(ll a,ll b,ll c)		//a^b mod c
{
	ll res=1;
	while ( b )
	{
		if ( b & 1 ) 
		{
			res=mulmod(res,a,c);
			--b ;
		}
		a= mulmod(a,a,c);
		b >>= 1 ;
	}
	return res;
}
bool miller(ll N)
{
	if(N==2 || N==3 || N==5)	return true;
	if(N<6 || N%2==0)	return false;
	ll d=N-1,a,x;
	int s=0,i,j;
	for(i=0;i<9;i++){
		if(prime[i]>=N)	break;
		a=prime[i];
		x=powmod(a,N-1,N);
		if(x!=1)	return false;
	}
	return true;
}
int main()
{
	int test;
	ll N;
	scanf("%d",&test);
	while(test--){
		scanf("%llu",&N);
		if(miller(N))	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
