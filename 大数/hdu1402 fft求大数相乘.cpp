#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define ld long double

using namespace std;

struct Complex{
    double real;
    double imag;
    Complex(){
    }
    Complex(double the){
        real = cos(the);
        imag = sin(the);
    }
    Complex(double a,double b){
        real = a;
        imag = b;
    }
};
Complex operator + ( Complex a , Complex b ){
    return Complex(a.real + b.real,a.imag+b.imag);
}
Complex operator - ( Complex a, Complex b ){
    return Complex(a.real-b.real,a.imag-b.imag);
}
Complex operator * ( Complex a, Complex b ){
    return Complex(a.real*b.real-a.imag*b.imag,a.imag*b.real+a.real*b.imag);
}
#define MAXN 200005
char str1[MAXN],str2[MAXN];
int len1,len2;
double pi2 = 2 * acos(-1.0);
Complex x1[MAXN],x2[MAXN];
void fft( Complex *A , int len , int ref )
{
    int bitn = log2(len);
    int i,j,k;
    for( i = 0 ; i < len ; i++ )
    {
        k = 0;
        for( j = 0 ; j < bitn ; j++ )
        {
            k = (k<<1);
            if(i&(1<<j))
                k |= 1;
        }
        if( k > i )
            swap(A[i],A[k]);
    }
    Complex wm,w,t,u;
    int f,m;
    for( m = 2 , f = 1 ; m <= len ; m<<=1 , f<<=1 )
    {
        wm = Complex(ref*pi2/m);
        for( k = 0 ; k < len ; k+=m )
        {
            w = Complex(1.0,0);
            for( j = k ; j < k + f ; j++ )
            {
                t = w * A[j+f];
                u = A[j];
                A[j] = u + t;
                A[j+f] = u - t;
                w = w * wm;
            }
        }
    }
    if( ref == -1 )
    {
        for( i = 0 ; i < len ; i++ )
            A[i].real = A[i].real/len;
    }
}

int main()
{
    while(~scanf("%s%s",str1,str2))
    {
        len1 = strlen(str1),len2 = strlen(str2);
        int len = 1;
        while( len < len1 * 2 || len < len2 * 2 ) len<<=1;
        for( int i = 0 ; i < len1 ; i++ )
            x1[i] = Complex(str1[len1-1-i]-'0',0);
        for( int i = len1 ; i < len ; i++ )
            x1[i] = Complex(0,0);
        for( int i = 0 ; i < len2 ; i++ )
            x2[i] = Complex(str2[len2-1-i]-'0',0);
        for( int i = len2 ; i < len ; i++ )
            x2[i] = Complex(0,0);
        fft(x1,len,1);
        fft(x2,len,1);
        for( int i = 0 ; i < len ; i++ )
            x1[i] = x1[i]*x2[i];
        fft( x1 , len , -1 );
        int sum[MAXN];
        for( int i = 0 ; i < len ; i++ )
            sum[i] = (int)(x1[i].real + 0.5 );
        for( int i = 0 ; i < len ; i++ )
        {
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
        len = len1 + len2 -1;
        while( sum[len] <= 0 && len > 0 ) len--;
        for( int i = len ; i >= 0 ; i-- )
            printf("%c",sum[i]+'0');
        printf("\n");
    }
    return 0;
}
