#include<stdio.h>
#include<string.h>
#include<bitset>
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

/******************Slow Sieve******************/
#define upto 1000000
int slow_a[upto+1],prime[upto+1],counter;
void slow_sieve()
{
	counter=0;
	memset(slow_a,1,sizeof(slow_a));			//initially say all are prime numbers
	for(int i=2;i<=upto;i++){
		if(slow_a[i]){						//if it is prime
			prime[counter]=i;				//save it
			counter++;
			if((ll)i*(ll)i>upto){			//start from i*i upto range
				continue;
			}
			for(int j=i*i;j<=upto;j+=i)
				slow_a[j]=0;
		}
	}
}
/****************End of Slow Sieve***********/

/******************Fast Sieve***************/
#define Fupto 100000000		//Upto how much you need to find prime numbers
#define lmt 10000	//square root of upto
bitset<Fupto/2+1> mybits;	//Total Odd Numbers:50000000 
//Initially when you declare, all the bits are zero initialised
int prime_a[(Fupto/2)+1];
void fast_sieve()
{
	int count=1;
	prime_a[0]=2;
	for(int i=3;i<=lmt;i+=2)	//travelling only through odd numbers because even numbers are not prime.
	{
		if(!mybits[i>>1])	//i is denoted by i/2 in the bitset array.
		{
			for(int j=i*i,k=i<<1;j<=Fupto;j+=k)	//Observe that p^2 + p is even and p^2+2*p is odd
				mybits.set(j>>1,1);
		}
	}
	//collecting the primes 
	for(int i=3;i<=Fupto;i+=2)
	{
		if(!mybits[i>>1])
		{
			prime_a[count]=i;
			count++;
		}
	}
}

/**************End of Fast Sieve**********/
int main()
{
	slow_sieve();
	for(int i=0;i<10;i++)	printf("%d ",prime[i]);
	fast_sieve();
	for(int i=0;i<10;i++)	printf("%d ",prime_a[i]);
	return 0;
}
