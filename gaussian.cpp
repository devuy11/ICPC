/*Code for Spoj GS*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
#define EPS 0.000000000001
#define MaxN 20
void process(vector<double> &x , vector<double> &y , double &a , double &b,int pos)
{
	//situation is x is at the top and y is below x.
	//Row of x * y[pos] , and Row of y * x[pos] and subtract from y , the value of x
	double cons2=y[pos];
	for(int i=0;i<y.size();i++){
		y[i] = y[i] - x[i]*cons2;
	}
	b = b - a*cons2;
}
void print(vector<double> M[] , int N,vector<double> B_mat)
{
	for(int i=0;i<N;i++){
		for(int j=0;j<M[i].size();j++){
			printf("%.6lf ",M[i][j]);
		}
		printf("\n");
	}
	printf("\n");printf("\n");
	for(int i=0;i<N;i++)	printf("%.3lf ",B_mat[i]);
	printf("\n");
}
vector<double> get_answer(vector<double> M[] , vector<double> B_mat,int N)	//i.e M|B_mat = 0
{
	int pivot ;
	for(int i=0;i<N;i++){
		/*pivot = i;
		  for(int j=i+1;j<N;j++){
		  if( fabs(M[j][i]) >fabs(M[pivot][i]))	pivot = j;
		  }
		  swap ( M[pivot] , M[i]);
		  swap ( B_mat[pivot] , B_mat[i]);*/
		B_mat[i] /= M[i][i];
		for(int j=N-1;j>=i;j--){
			M[i][j] /= M[i][i];
		}
		for(int j=i+1;j<N;j++){
			process(M[i], M[j], B_mat[i] , B_mat[j] , i);
		}
	}

	for(int i=N-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			process(M[i],M[j] , B_mat[i] ,B_mat[j], i);
		}
	}

	return B_mat;	//returns a matrix of solution
}
void solve()
{
	vector< double > matrix[MaxN],B_mat;
	double in[MaxN][MaxN];
	memset(in,0,sizeof(in));
	int N,st,en,c,x,y;
	scanf("%d%d%d",&N,&st,&en);
	for(int i=1;i<=N-1;i++){
		scanf("%d%d%d",&x,&y,&c);
		in[x][y]+=c;
		in[y][x]+=c;
	}
	if(st==en){
		printf("0.00000\n");
		return ;
	}
	double sum[MaxN];
	memset(sum , 0 , sizeof(sum));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)	sum[i] += in[i][j];
	}
	int counter = 0,st_where;
	//only N-1 variables are considered . Why ? because E(en,en) = 0
	for(int i=1;i<=N;i++){
		if( i==en) 	continue;
		//fill it in the vector
		if(i==st)	st_where = counter;
		for(int j=1;j<=N;j++){
			if ( j != en ){
				if(j==i)	matrix[counter].push_back(1);
				else{
					matrix[counter].push_back(-(in[i][j]/sum[i]));
				}
			}
		}
		//constant term here
		B_mat.push_back(1);
		counter++;
	}
	vector<double> Solution  = get_answer ( matrix , B_mat,N-1);
	printf("%.5lf\n",Solution[st_where]);
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		solve();
	}
	return 0;
}

