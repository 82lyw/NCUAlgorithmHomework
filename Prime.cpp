#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAXTEST 50
bool isF = false;

// 求a、b的最大公因数
long long gcd(long long a,long long b)
{
    if (b==0) 
		return a;
    return gcd(b,a%b);
}

long long QR(long long a,long long b,long long mod)
{
	if (b==1)
		return a%mod;
	if (b&1)
		return ((a%mod)*QR(a,b-1,mod))%mod;
	long long t = QR(a,b>>1,mod);
	long long tt = (t*t)%mod;
	if (tt==1)
	{
		if (t!=1 && t!=mod-1)
			isF=false;
	}
	return tt;
}

bool isPrime(long long p)
{
	int T = MAXTEST;
	if (p%2==0 && p!=2)
		return false;
	else if (p==2)
		return true;
	else if (p==1)
		return false;
	else{
		while(T--)
		{
			long long a = rand() % p + 1;
			while (gcd(a,p)!=1)
			{
				if (a<p || a%p!=0)
					return false;
				a = rand() % p + 1;
			}
			if (QR(a,p-1,p)!=1 || !isF) 
				return true;
		}		
		return true;
	} 
	
}

int main()
{
	long long n;
	cout<<"输入待判断的大数："<<endl;
	cin>>n;
	string result = isPrime(n) ? "prime number" : "composite number";
	cout<<result<<endl;
	return 0;
}
