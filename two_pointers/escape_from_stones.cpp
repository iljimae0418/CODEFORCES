#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
typedef long double ld;  
char s[1000006];  
int main(){
	scanf("%s",s);  
	int n = strlen(s);  
	for (int i = 0; i < n; i++){
		if (s[i] == 'r') printf("%d\n",i+1);  
	}
	for (int i = n-1; i >= 0; i--){
		if (s[i] == 'l') printf("%d\n",i+1);   
	}
	return 0;  
}
