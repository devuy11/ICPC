#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<assert.h>
using namespace std;
typedef long long int ll;
int powmod(int a,int b,int m)
{
	int ans = 1%m;
	while(b){
		if(b&1){
			ans  = ( (ll)ans*(ll)a )%m;
			b--;
		}
		else{
			a = ( (ll)a*(ll)a )%m;
			b>>=1;
		}
	}
	return ans;
}
int nth;
int get_root(int M)
{
	int z = (M - 1)/(1<<nth),i,j,a,b,s;
	vector<int> initial;
	for(i = 1;i<=sqrt(z);i++){
		if ( z%i == 0){
			initial.push_back(i);
			if( i!=z/i)	initial.push_back(z/i);
		}
	}
	while(1){
		s = rand()%M + 1;
		for(i=0;i<nth;i++){
			a = (1<<i);
			for(j=0;j<initial.size();j++){
				b = initial[j];
				if ( powmod( s, a*b , M ) ==1)	break;
			}
			if(j!=initial.size())	break;
		}
		if(i==nth && powmod(s,(1<<nth),M)==1)	return s;
	}
}

bool check(int M)
{
	int i;
	for(i=1;i<=30;i++){
		if( M%(1<<i) != 1 )	break;
	}
	printf("2^%d root is available ? Proceed(p) Or Cancel(c)\n",i-1);
	nth = i-1;
	char c;
	scanf(" %c",&c);
	if( c=='p' )	return true;
	else	return false;
}

void cross_check(int s,int M)
{
	set<int> myset;
	for(int i=1;i<=(1<<nth);i++){
		myset.insert(powmod(s,i,M));
	}
	assert(myset.size() == (1<<nth) );
	assert(powmod(s, (1<<nth) , M )==1 );
}

int main()
{
	int M,s;
	scanf("%d",&M);
	if(check(M)){
		s=get_root(M);
		printf("%d is s\n",s);
		cross_check(s,M);
		printf("Enter the 2^xth root you needed , only input x\n");
		int z;
		scanf("%d",&z);
		printf("%d\n",powmod(s,(1<<(nth-z)),M));
	}
	return 0;
}
