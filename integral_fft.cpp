#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
#include<assert.h>
#include<utility>
using namespace std;

typedef long long int ll;

#define For(i,s,e) for(int i=(s);i<=(e);i++)
#define mp(a,b)	make_pair((a),(b))

#define M 1005060097
//M = c*(2^(log(max_degree)+1)) are distinct.
#define s 690733049		//For testing now.
//s denotes the value s.t s^1,s^2,.....s^(2^(log(max_degree)+1)) are distinct.
int power_of_s[25];

void integral_fft_constant()
{
	power_of_s[0] = s;
	for(int i=1;i<24;i++)	power_of_s[i] = ((ll)power_of_s[i-1]*(ll)power_of_s[i-1])%M;
}

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
void integral_fft(int input[],int output[] , int skip ,int size ,int iteration)
{
	if(size==1){
		output[0] = input[0];
		return ;
	}
	integral_fft(input,output,skip*2,size/2,iteration+1);
	integral_fft(input+skip , output+size/2 , skip*2 , size/2 ,iteration+1);
	int var1 , var2= 1,odd,even,store;
	//var1 is sizeth root of unity.
	var1 = power_of_s[iteration];
	for(int k=0;k<size/2;k++){
		even = output[k];
		odd = output[k+size/2];
		store = ((ll)var2*(ll)odd)%M;
		output[k] = even + store;
		output[k+size/2] = even - store;
		if(output[k]>=M)	output[k] -= M;
		if(output[k+size/2] <0 ) output[k+size/2] += M;
		var2 = ((ll)var2*(ll)var1)%M;
	}
}

void multiply( int A[] , int B[] ,int result[] ,int y)
{
	int CA[y+1],CB[y+1];
	integral_fft(A,CA,1,y,0);
	integral_fft(B,CB,1,y,0);
	int inverse_of_y = powmod(y,M-2,M);
	for(int i=0;i<y;i++)	CA[i] = ((((ll)CA[i]*(ll)CB[i])%M)*(ll)inverse_of_y)%M;
	integral_fft(CA,result,1,y,0);
	swap(result[0],result[y]);
	reverse(result,result+y+1);	
	//for(int i=0;i<y;i++)	printf("%d ",result[i]);
	//complex_fft(CA,result,1,y,false);
}
void get_poly(int poly[] ,int x)
{
	int t;
	for(int i=0;i<x;i++){
		scanf("%d",&t);
		poly[i] = t;
	}
}
int main()
{
	integral_fft_constant();
	/****************demo*************/
	int x;
	int poly1[1<<15],poly2[1<<15],answer[1<<15];
	scanf("%d",&x);
	get_poly(poly1,x);		//for demonstration give x to be 2^t format
	get_poly(poly2,x);
	multiply(poly1,poly2,answer,x*2);
	for(int i=0;i<2*x;i++){
		printf("%d ",answer[i]);
	}
	/****************demo*************/
	return 0;
}
