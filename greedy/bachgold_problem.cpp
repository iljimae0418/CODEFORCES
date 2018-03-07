#include <iostream>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	int cnt = 0;  
	if (n%2==1){
		n -= 3; 
		cnt += 1+(n/2);  
		cout << cnt << endl; 
		for (int i = 0; i < n/2; i++){
			cout << 2 << " "; 
		}
		cout << 3 << endl; 
	}else{
		cnt += n/2; 
		cout << cnt << endl; 
		for (int i = 0; i < n/2; i++){
			cout << 2 << " "; 
		}
		cout << endl; 
	}
	return 0;  
}
