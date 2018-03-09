#include <iostream> 
#include <string>
#include <algorithm> 
using namespace std;  
int main(){
	string s; 
	cin >> s; 
	for (int i = 0; i < s.size(); i++){
		if (9-(s[i]-'0') < s[i]-'0' && !(i == 0 && s[i] == '9')){
			s[i] = char((9-(s[i]-'0')) + '0');  
		}
	}
	cout << s << endl; 
	return 0; 
}
