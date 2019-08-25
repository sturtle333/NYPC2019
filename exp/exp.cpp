#include <iostream>
#include <vector>

#define u64 long long
#define endless true

using namespace std;

u64 table[15][15];
	
int f(int pivot, int N, vector <u64> exp) {	
	vector <u64> result;
	vector <u64> v(exp);
	u64 temp = v[pivot];
	
	for(int i=0;i<N;i++){
		v[i] = v[i]> 0? v[i]-table[i][pivot] : 0;
	}

	u64 max = 0;
	int index = -1;
	for(int j=0;j<N;j++){
		if(v[j] > max) {
			max = v[j];
			index = j;
		}
	}
	
	if(index == -1) return temp;
	
	for(int j=0;j<N;j++){
		if(v[j] <= 0) continue;
		else if(v[j] == max && j != index) {
			result.push_back(f(j,N,v));
		}
	}
	result.push_back(f(index,N,v));

	u64 ret = 0;
	for(int i=0;i<(int)result.size();i++){
		if(ret < result[i]) {
			ret = result[i];
		}
	}
	return temp + ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N = 0;
	cin >> N;
	
	vector <u64> result;
	vector <u64> exp;
	
	for(int i=0;i<N;i++){
		u64 temp = 0;
		for(int j=0;j<N;j++){
			cin >> table[i][j];
			temp += table[i][j];
			if(i == j) {
				table[i][i] = 0;
			}
		}
		exp.push_back(temp);
	}

	u64 max = 0;
	int index = 0;
	for(int j=0;j<N;j++){
		if(exp[j] > max) {
			max = exp[j];
			index = j;
		}
	}
	
	for(int j=0;j<N;j++){
		if(exp[j] == max && j != index) {
			result.push_back(f(j,N,exp));
		}
	}
	result.push_back(f(index,N,exp));

	
	u64 ret = 0;
	for(int i=0;i<(int)result.size();i++){
		if(ret < result[i]) ret = result[i];
	}
	
	cout << ret;
	
    return 0;
}
