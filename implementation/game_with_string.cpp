#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;  
int main(){
	string s; 
	cin >> s;  
	int turn = 0;  
	while (!s.empty()){
		bool erased = false;  
		for (int i = 0; i+1 < s.size(); i++){
			if (s[i] == s[i+1]){
				s.erase(i,2); 
				erased = true; 
				break; 
			}
		}
		if (!erased){
			cout << (turn == 0 ? "NO" : "YES") << endl; 
			return 0;  
		}else{
			turn = !turn; 
		}
	}
	cout << (turn == 0 ? "NO" : "YES") << endl;
	return 0;  
}
