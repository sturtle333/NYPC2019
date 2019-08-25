#include <iostream>
#include <vector>

#define u64 long long
#define endless true
#define endl '\n'

using namespace std;

class gold {
	public:
		u64 num;
		u64 value;
};

void VRST (vector<gold> &v) {
	vector<gold> temp(0);
	temp.swap(v);
}

void VRST (vector<u64> &v) {
	vector<u64> temp(0);
	temp.swap(v);
}

void maxSearch (const vector<gold> v, vector<gold> &purpose){
	vector<gold> max;
	max.assign(1,v[0]);
	u64 maxValue = v[0].value;
	for(int i=1;i<(int)v.size();i++){
		if(maxValue < v[i].value) {
			VRST(max);
			max.push_back(v[i]);
			maxValue = v[i].value;
		}
		else if(maxValue == v[i].value) {
			max.push_back(v[i]);
		}
	}
	purpose.swap(max);
}

u64 calcV (const u64 index, vector<gold> v, const vector<vector<gold>> &table) {
	vector<gold> exp(v);
	u64 expSize = (int)exp.size();
	u64 result = exp[index-1].value;
	
	exp[index-1].value = 0;
	
	for(int i=0;i<expSize;i++){
		if(exp[i].value != 0) {
			exp[i].value -= table[i][index-1].value;
		}
	}
	
	u64 tempR = 0;
	vector<gold> temp;
	maxSearch(exp, temp);
	
	if(temp[0].value == 0) return result;
	
	for(int i=0;i<(int)temp.size();i++){
		u64 baba = calcV(temp[i].num,exp,table);
		tempR = tempR < baba ? baba : tempR;
	}
	
	return result + tempR;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N ,result = 0;
	cin >> N;
	
	vector<vector<gold>> table(N);
	vector<gold> exp(N);
	
	for(int i=0;i<N;i++){
		u64 Sum = 0;
		for(int j=0;j<N;j++){
			gold temp;
			cin >> temp.value;
			temp.num = j+1;
			table[i].push_back(temp);
			Sum += temp.value;
		}
		exp[i].value = Sum;
		exp[i].num = i+1;
	}
	
	vector<gold> temp;
	maxSearch(exp, temp);
	for(int i=0;i<(int)temp.size();i++){
		u64 baba = calcV(temp[i].num,exp,table);
		result = result < baba ? baba : result;
	}
	
	cout << result;
    return 0;
}
