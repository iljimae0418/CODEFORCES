#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
long long gcd(long long a,long long b){
	if (b == 0) return a; 
	return gcd(b,a%b); 
}
int main(){
	long long a,b,c,d;
	long long p,q;     
	cin >> a >> b >> c >> d; 
	while (a <= c && b <= d){
		a += a; 
		b += b; 
	}
	double k1 = (double)a/c; 
	double k2 = (double)b/d; 
	if (k1 < k2){
		p = c*a*b - a*a*d;  
		q = c*a*b;   
		cout << p/gcd(p,q) << "/" << q/gcd(p,q) << endl; 
	}else{
		p = d*a*b - b*b*c; 
		q = d*a*b; 
		cout << p/gcd(p,q) << "/" << q/gcd(p,q) << endl; 
	}
	return 0; 
}
