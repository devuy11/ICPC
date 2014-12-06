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


#define MAXN 100002
#define MAXLG 19

char A[MAXN];

struct entry
{
	int nr[2];
	int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N,i;
int stp, cnt;

int cmp(struct entry a, struct entry b)
{
	return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

void suffix(string A)
{
    for(N=A.size(), i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';

    for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(i=0; i < N; i++)
            P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
    }
	stp--;
	//for(int i=0;i<N;i++)	printf("%d\n",P[stp][i]);
	//stp contains the rank of every suffix.
}

int FindLCP (int x,int y)
{
	int answer = 0;

	for(int k = stp;k>=0;k--){
		if (P[k][x] == P[k][y]){
			// sort-index is same if the first k characters are same
			answer += (1<<k);
			// now we wish to find the characters that are same in the remaining strings
			x += (1<<k);
			y += (1<<k);
		}
	}
	return answer;
}

void solve()
{
	string s;	
	cin>>s;
	suffix(s);
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			printf("%d %d %d\n",i,j,FindLCP(i,j));
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
