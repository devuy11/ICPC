#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
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

#define FOR(i,s,e) for(int i=(s);i<(e);i++)
#define mp(a,b)	make_pair((a),(b))
#define sint(a) scanf("%d",&(a))
#define sll(a)  scanf("%lld",&(a))
#define sd(a)   scanf("%lf",&(a))


#define MaxN 100005
/**************TEMPLATE FOR TREES***************/
vector<int> graph[MaxN];
int parent[MaxN],depth[MaxN];


/*************Simple DFS for Storing Parent and Depth*********/
void simple_dfs(int root,int iteration=0)
{
	//BASE CASE
	if( iteration == 0 ){
		parent[root] = root;
		depth[root] = 0;
	}

	for(vector<int>::iterator it = graph[root].begin();it!=graph[root].end();it++){
		if( parent[root]==(*it) )
			continue;
		else{
			parent[(*it)] = root;
			depth[(*it)] = depth[root]+1;
			simple_dfs((*it),iteration+1);
		}
	}
}
/*******END OF Simple DFS for Storing Parent and Depth********/


/*************DFS for calculating In Array and it's Mapping***********/
int in_counter;
pair<int,int> In[MaxN];
void In_dfs(int root,int iteration = 0)
{
	//BASE CASE
	if ( iteration == 0 ){
		in_counter = 1;
		parent[root] = root;
		depth[root] =0;
	}
	In[root].first = in_counter;
	in_counter++;
	// In case you need the in array => write one line here
	for(vector<int>::iterator it = graph[root].begin();it!=graph[root].end();it++){
		if( parent[root] == (*it) )
			continue;
		else{
			parent[(*it)] = root;
			depth[(*it)] = depth[root]+1;
			In_dfs(root,iteration+1);
		}
	}
	In[root].second = in_counter;
}
/********END OF DFS for calculating In Array and it's Mapping*********/




/***********DFS for Calculating InOut Array and it's Mapping*********/
void InOut_dfs(int root,int iteration = 0)
{
	if(iteration = 0){
		parent[root] = root;
		depth[root] = 0;
	}
}
/***********DFS for Calculating InOut Array and it's Mapping*********/




/*************LCA Part is Here****************/
int Root[MaxN][18],log2[MaxN];
void init()
{
	log2[0]=0;log2[1]=0;log2[2]=1;
	int cmp=4;
	for(int i=3;i<=100000;i++){
		if(cmp>i)       log2[i]=log2[i-1];
		else{
			log2[i]=log2[i-1]+1;
			cmp<<=1;
		}
	}
}
void get2p(int N)
{
	memset(Root,-1,sizeof(int)*18*(N+1));
	for(int i=1;i<=N;i++)   
		Root[i][0]=parent[i];
	for(int i=1;(1<<i)<=N;i++)
		for(int j=1;j<=N;j++)
			if(Root[j][i-1]!=-1)
				Root[j][i]=Root[Root[j][i-1]][i-1];
}
int lca(int p,int q)
{
	int temp;
	//first we make q the more deeper node
	if(depth[p]>depth[q])   
		swap(p,q);
	//we find the closest power of 2
	int steps=log2[depth[q]];
	//we try to make the depth of q equal to p and then increase both
	for(int i=steps;i>=0;i--)
		if(depth[q]-(1<<i) >= depth[p])
			q=Root[q][i];
	//if p was equal to q at the time of depth balancing then it is indeed a ancestor
	if(p==q)        
		return p;
	//now we increase both p and q by small amount and if value is different , then we procede up
	for(int i=steps;i>=0;i--){
		if(Root[p][i]!=Root[q][i])
			p=Root[p][i],q=Root[q][i];
	}
	//we end up getting 1 node short for parent.
	return parent[p];
}
void LCA(int N)
{
	init();
	//if you have parent and depth stored
	get2p(N);
}
/*************************LCA part Ends********************/


void tree(int N)
{
	int u,v;
	FOR(i,1,N+1)	graph[i].clear();
	FOR(i,1,N){
		sint(u);
		sint(v);
		graph[u].push_back( v );
		graph[v].push_back( u );
	}
	//If you want to procede for LCA
	LCA(N);
	//If you want to proced for In-Out Traversal Information
	//INOUT();
}
/**************TEMPLATE ENDS HERE**************/

int main()
{
	int N;
	scanf("%d",&N);
	tree(N);
	return 0;
}
