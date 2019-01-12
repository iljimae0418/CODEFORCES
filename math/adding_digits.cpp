#include <iostream>
using namespace std; 
int power(int a,int x){
	if (x == 0) return 1;  
	if (x == 1) return a; 
	return power(a,x/2)*power(a,x/2)*power(a,x%2); 
}
int digitLen(int x){
	if (x == 0) return 1; 
	int cnt = 0;  
	while (x){
		x /= 10; 
		cnt++; 
	}
	return cnt; 
}
string generate(int a){
	string s = ""; 
	while (a){
		s += (a%10)+'0'; 
		a /= 10; 
	}
	reverse(s.begin(),s.end());
	return s; 
}
int main(){
	int a,b,n;  
	cin >> a >> b >> n;  
	string s = generate(a); 
	bool can = false; 
	for (int i = 0; i <= 9; i++){
		if ((a*power(10,1)+i)%b == 0){
			s += string(1,i+'0'); 
			can = true; 
			break; 
		}
	}
	if (!can){
		cout << -1 << endl; 
		return 0; 
	}
	for (int i = 0; i < n-1; i++){
		s += "0"; 
	}
	cout << s << endl; 
	return 0; 
}
