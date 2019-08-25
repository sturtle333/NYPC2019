#include <iostream>
#include <vector>
#include <cmath>


#define endl '\n'

using namespace std;

int main () {
	int x;
	cin >> x;
	
	vector<int> v;
	
	for(int i=0;i<x;i++){
		v.push_back(i);
	}
	
	cin >> x;
	
	v.insert(v.begin()+x, -1);
	
	for(int i=0;i<(int)v.size();i++){
		cout << v[i];
	}
	
	return 0;
}
