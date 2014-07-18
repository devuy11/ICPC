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

double pi =(double)2*acos(0);
struct comp{
	double a,b;
	comp (double c=0, double d = 0){
		a= c;b=d;
	}
	comp operator + (const comp &x)const{
		return comp(a+x.a , b+x.b);
	}
	comp operator - (const comp &x) const{
		return comp(a-x.a,b-x.b);
	}
	comp operator * (const comp &x) const{
                return comp(a*x.a-b*x.b,b*x.a+a*x.b);
        }
	comp operator / (const int &x) const{
                return comp(a/x,b/x);
        }
};
//return the value of cos(theta) + iota*sin(theta)
comp expo(double theta)
{
	return comp(cos(theta) , sin(theta));
}

//skip denotes the frequency at which you jump: example : 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
// complex_fft( I , O , 2 ,  8 , 1 ) and complex_fft ( I+1, O , 2, 8, 1)
// Meaning of arguments for first one : I , I+2 , I+4 , I+6 , I+8,I+10,I+12,I+14 [ 8 elements ]
// Meaning of arguments for second one : I+1 , I+3 , I+5,I+7,I+9,I+11,I+13,I+15 [ 8 elements ]
// Meaning of size is clear but meaning of skip ?
// First case : skip = 2 implies [when you divide again the poly in even and odd , alternate every 2nd element from starting address]
//output contains the result of the multiplication but how ?
// all the even results are stored in the first half and odd in the next half.[one full is considered as output - output + size]
void complex_fft(comp input[],comp output[] , int skip ,int size , bool con)
{
	if(size==1){
		output[0] = input[0];
		return ;
	}
	complex_fft(input,output,skip*2,size/2,con);
	complex_fft(input+skip , output+size/2 , skip*2 , size/2 , con);
	comp var1 , var2= comp(1,0),odd,even,store;
	//var1 is sizeth root of unity.
	if (con)	var1 = expo(((double)2*pi)/(double)size);
	else	var1 = expo(-((double)2*pi)/(double)size);
	for(int k=0;k<size/2;k++){
		even = output[k];
		odd = output[k+size/2];
		store = var2*odd;
		output[k] = even + store;
		output[k+size/2] = even - store;
		var2 = var2*var1;
	}
}
void multiply( comp A[] , comp B[] ,comp result[] ,int y)
{
	comp CA[y+1],CB[y+1];
	complex_fft(A,CA,1,y,true);
	complex_fft(B,CB,1,y,true);
	for(int i=0;i<y;i++)	CA[i] = (CA[i]*CB[i])/y;
	complex_fft(CA,result,1,y,false);
}
void get_poly(comp poly[] ,int x)
{
	int t;
	for(int i=0;i<x;i++){
		scanf("%d",&t);
		poly[i] = comp(t,0);
	}
}
int main()
{
	/****************demo*************/
	int x;
	comp poly1[1<<15],poly2[1<<15],answer[1<<15];
	scanf("%d",&x);
	get_poly(poly1,x);		//for demonstration give x to be 2^t format
	get_poly(poly2,x);
	multiply(poly1,poly2,answer,x*2);
	for(int i=0;i<2*x;i++){
		printf("%.0lf ",answer[i].a);
	}
	/****************demo*************/
	return 0;
}
