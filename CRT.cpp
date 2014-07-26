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

void Get_x_and_y(pair<ll,ll> &x,int a,int b,int m)    //1 possible x and y for ax+by = 1
{
        if ( a>b )      swap(a,b);      //b > a always!
        int z = b%a;
        if ( z==0 )     return;
        Get_x_and_y(x,z,a,m);
        x = make_pair(x.second , (x.first - x.second*(ll)(b/a))%m);
}

ll inverse(ll a, ll b)
{
	pair<ll,ll> x = (0,1);
	return (Get_x_and_y(x,a%b , b , b).second+b)%b;
}

ll mod[20] ;
ll rem[20];
ll CRT(int t)			//t is the number of pairs of rem and mod
{
	ll ans = 0;
	for(int i=0;i<t;i++){
		ans = (ans + rem[i]*inverse(M/mod[i],mod[i])*(M/mod[i]))%M;
	}
	return ans;
}

int main()
{
	int test,pair;
	printf("Enter Number of Test Cases\n");
	scanf("%d",&test);
	while(test--)
	{
		printf("Enter Number Of Pairs of Remainder mod number , all number should be relatively prime\n");
		scanf("%d",&pair);
		for(int i=0;i<pair;i++)
			scanf("%lld%lld",&rem[i],&mod[i]);
		printf("%lld\n",CRT(pair));
	}

	return 0;
}
