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

/**********************SEG TREE TEMPLATE*************/
int level,power[25];
void obt(int N)
{
	level = 0;
	int x = N;
	while(x!=0){
		x/=2;
		level++;
	}
	if(power[level-1] != N)	level++;
}

void init(int s,int e,int node)
{
	if ( s==e ){
		if ( s<= Tot_Nodes){
		}
		else{
		}
		return ;
	}
	init(s,(s+e)/2,node*2);
	init((s+e)/2+1,e,node*2+1);
	//Other Logic
}

void update(int s,int e,int L,int R,int node)
{	
	if( e < L  || R<s )	return;
	if (  L <= s  &&  e <= R ){
		return ;//Logic;
	}
	update(s,(s+e)/2,L,R,node*2);
	update((s+e)/2+1,e,L,R,node*2+1);
}

void point_update(int ind)
{
	int ar = ind + power[level-1] - 1;	//if ind is 1 indexed
	while(ar!=0){
		//do somethig at ar
		ar/=2;
	}
}

void solve()
{
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}
