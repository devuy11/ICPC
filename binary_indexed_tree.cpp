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

/*******************************************Binary Indexed Tree*******************/
#define maxn 100009

ll MaxVal,size_tree;
vector<ll> tree;

ll get_bitmask()
{
	ll ans=0;
	int y = size_tree;
	while(y){
		ans = y;
		y-= (y&-y);
	}
	return ans;
}

ll get_MaxVal()
{
	ll x = get_bitmask();
	return (ll)2*x-1; 
}

void init(int N)	//size of the tree
{
	size_tree = N;
	MaxVal = get_MaxVal();
	//memset(tree,0,sizeof(tree));
	tree = vector<ll>(MaxVal+5,0);
}

void update(int ind,ll val)
{
	while(ind<=MaxVal){
		tree[ind] += val;
		ind += (ind&-ind);
	}
}

ll read(int ind)
{
	ll sum = 0;
	while(ind){
		sum += tree[ind];
		ind -= (ind & -ind);
	}
	return sum;
}

// if in tree exists more than one index with a same
// cumulative frequency, this procedure will return 
// the greatest one
int findG(int cumFre){
	int idx = 0;

	int bitMask = get_bitmask();

	while ((bitMask != 0) && (idx < MaxVal)){
		int tIdx = idx + bitMask;
		if (cumFre >= tree[tIdx]){ 
			// if current cumulative frequency is equal to cumFre, 
			// we are still looking for higher index (if exists)
			idx = tIdx;
			cumFre -= tree[tIdx];
		}
		bitMask >>= 1;
	}
	if (cumFre != 0)
		return -1;
	else
		return min(idx,(int)size_tree);
}

void solve()
{
	int op,ind,val,N;
	scanf("%d",&N);

	init(N);

	for(int i=1;i<=N;i++){
		scanf("%d",&op);
		if(op == 1){
			cin>>ind>>val;
			update(ind,val);
		}
		else if(op==2){
			cin>>ind>>val;
			printf("%lld\n",read(val)-read(ind-1));
		}
		else if(op==3){
			cin>>val;
			printf("%d\n",findG(val));
		}
	}
}

int main()
{
	int T=1;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}
