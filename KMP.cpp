#include<stdio.h>
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

void KMP_Failure_Fun(string a,int F[])
{
	int len = a.size(),j;
	// F[0] = 0 implies that the first character is not a proper suffix of it
	F[0]= 0;

	for(int i=1;i<len;i++){
		//Find the longest suffix which is also a prefix of the previous character
		j = F[i-1];
		while(j>0 && a[j] != a[i]){
			j = F[j];
		}
		if(a[j] == a[i] )	j++;
		F[i]  = j;
	}
	for(int i=0;i<len;i++)	printf("%d ",F[i]);
}

int main()
{
	string a;
	cin>>a;
	int F[1000001];
	KMP_Failure_Fun(a,F);
	return 0;
}
