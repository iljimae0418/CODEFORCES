#include <iostream> 
#include <algorithm> 
#include <cstdlib>
#include <vector> 
#include <map> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
string s1,s2;  
int power(int x){
	// calculates 2^x 
	if (x == 0) return 1; 
	if (x == 1) return 2; 
	return power(x/2)*power(x/2)*power(x%2); 
}
string toBinary(int x,int len){
	string t = ""; 
	while (x){	
		t += char(x%2 + '0'); 
		x /= 2;  
	}
	reverse(t.begin(),t.end()); 
	while (t.size() < len){
		t = "0"+t;  
	}
	return t;  
}
int compute(string t){
	map<char,int> mp; 
	for (int i = 0; i < t.size(); i++){
		mp[t[i]]++; 
	}
	return mp['+']-mp['-'];  
}
int main(){
	IOFAST();  
	cin >> s1 >> s2;  
	// we simply try all possible cases
	int score = 0;  
	for (int i = 0; i < s1.size(); i++){
		if (s1[i] == '-') score--; 
		else if (s1[i] == '+') score++; 
	}
	int cnt = 0; 
	vector<int> qpos; // index of question marks  
	for (int i = 0; i < s2.size(); i++){
		if (s2[i] == '?'){
			qpos.push_back(i);  
			cnt++; 
		}
	}
	int cases = 0; 
	for (int i = 0; i < (1<<cnt); i++){
		string temp = s2; 
		string bin = toBinary(i,cnt);  
		for (int j = 0; j < bin.size(); j++){ // bin.size() == qpos.size()
			if (bin[j] == '0'){
				temp[qpos[j]] = '-'; 
			}else if (bin[j] == '1'){
				temp[qpos[j]] = '+';  
			}
		}
		if (compute(temp) == score){
			cases++; 
		}
	}
	double ans = (double)cases/(double)power(cnt);
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(12); 
	cout << ans << endl; 
	return 0; 
}
