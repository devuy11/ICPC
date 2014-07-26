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

//if m is prime , find a^(m-2) mod m
//Euclidean Method to find solution to a*x + m*y = 1 , take mod m on both sides
//init x = (0,1) and send.
void Get_x_and_y(pair<ll,ll> &x,int a,int b,int m)    //1 possible x and y for ax+by = 1
{
        if ( a>b )      swap(a,b);      //b > a always!
        int z = b%a;
        if ( z==0 )     return;
        Get_x_and_y(x,z,a,m);
        x = make_pair(x.second , (x.first - x.second*(ll)(b/a))%m);
}

int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if ( __gcd(a,b) != 1)	printf("No Inverse , go Home :P \n");
		else{
			pair<ll,ll> x(0,1);
			Get_x_and_y(x , a , b, b);
			printf("%lld\n",(x.second+b)%b);
		}
	}
	return 0;
}
