#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
char type11[4] = {'^','>','v','<'}; // cw 
char type12[4] = {'^','<','v','>'}; // ccw
char type21[4] = {'<','^','>','v'}; // cw 
char type22[4] = {'<','v','>','^'}; // ccw
char type31[4] = {'v','<','^','>'}; // cw
char type32[4] = {'v','>','^','<'}; // ccw 
char type41[4] = {'>','v','<','^'}; // cw 
char type42[4] = {'>','^','<','v'}; // ccw 
int main(){
 	char init,final;  
	int n; 
	cin >> init >> final; 
	cin >> n; 
	n %= 4; 
	if (init == '^'){
		if (type11[n] == final && type12[n] == final) cout << "undefined" << endl; 
		else if (type11[n] == final) cout << "cw" << endl; 
		else if (type12[n] == final) cout << "ccw" << endl; 
		else cout << "undefined" << endl;  
	}else if (init == '<'){
		if (type21[n] == final && type22[n] == final) cout << "undefined" << endl; 
		else if (type21[n] == final) cout << "cw" << endl; 
		else if (type22[n] == final) cout << "ccw" << endl; 
		else cout << "undefined" << endl; 
	}else if (init == 'v'){
		if (type31[n] == final && type32[n] == final) cout << "undefined" << endl; 
		else if (type31[n] == final) cout << "cw" << endl; 
		else if (type32[n] == final) cout << "ccw" << endl; 
		else cout << "undefined" << endl; 
	}else if (init == '>'){
		if (type41[n] == final && type42[n] == final) cout << "undefined" << endl; 
		else if (type41[n] == final) cout << "cw" << endl; 
		else if (type42[n] == final) cout << "ccw" << endl; 
		else cout << "undefined" << endl; 
	}
	return 0;  
}
