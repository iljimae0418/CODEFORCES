// need careful calculation to avoid overflows. 
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
using namespace std; 
/*
There are A red islands and B blue islands. 
If there are k bridges between red islands and blue islands, 
the number of possible bridges we can make is ACk * BCk * k!  
*/  
const int mod = 998244353;  
int bino[5001][5001]; 
int factorial[5001];  
void fillBino(){
	for (int i = 0; i <= 5000; i++){
		for (int j = 0; j <= i; j++){
			if (i == 0 || j == 0 || i == j){
				bino[i][j] = 1; 
			}else{
				bino[i][j] = (bino[i-1][j-1]+bino[i-1][j])%mod; 
			}
		}
	}
}
void fillFactorial(){
	factorial[0] = 1; 
	for (int i = 1; i <= 5000; i++){
		factorial[i] = (1LL*factorial[i-1]*i)%mod;  
	}
}
int f(int x,int y){
	int res = 0; 
	for (int k = 0; k <= min(x,y); k++){
		int add = factorial[k]; 
		add = (1LL*add*bino[x][k])%mod; 
		add = (1LL*add*bino[y][k])%mod;  
		res = (res + add)%mod; 
	}
	return res; 
}
int main(){
	int a,b,c; 
	cin >> a >> b >> c;  
	fillBino(); 
	fillFactorial();  
	int ans = 1;  
	ans = (1LL*ans*f(a,b))%mod; 
	ans = (1LL*ans*f(b,c))%mod; 
	ans = (1LL*ans*f(a,c))%mod;  
	cout << ans << endl;
	return 0;  
}
