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

#define REP(i,n)	for(int i=0;i<(n);i++)

#define mp	make_pair
#define pb push_back

#define DEBUG(x) cout<<" "<<#x<<"  "<<(x)<<"\n";

#define INF 1e9

int find(int s,int e){	
	return rand()%(e-s+1) + s;
}


int main()
{
	int N = 100,M=100,P=50;
	printf("%d %d %d\n",N,M,P);
	for(int i=1;i<=P;i++)	printf("%d %d\n",find(1,N),find(1,M));
	return 0;
}
