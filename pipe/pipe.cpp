#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdint.h>

#define u64 long long int
#define endless true

using namespace std;

class House {
	public:
		u64 x;
		u64 y;
		
		House (u64 a, u64 b){
			x = a;
			y = b;
		}
};

class Pipe {
	public:
		u64 pivot1;
		u64 max1;
		u64 min1;
		u64 E;
		
		u64 stack;
		
		Pipe(House h, u64 e) {
			pivot1 = h.y;
			stack = 1;
			max1 = pivot1 + e;
			min1 = pivot1 - e;
			E = e;
		}
		
		void operate (House h){
			u64 temp = h.y;
			u64 up = temp+E, down = temp-E;
			
			if(max1 == min1 && temp == max1) {
					pivot1 = temp;
					max1 = up;
					min1 = down;
					stack += 1;
					
					return;
			}			
			else if (pivot1 > temp) {
				if(min1 <= up) {
					if (max1 > up){
						max1 = up;
					}
				}
				else {
					pivot1 = temp;
					max1 = up;
					min1 = down;
					stack += 1;
				}
			}
			else if (pivot1 < temp) {
				if(max1 >= down) {
					if (min1 < down){
						min1 = down;
					}
				}
				else {
					pivot1 = temp;
					max1 = up;
					min1 = down;
					stack += 1;
				}
			}
		}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	u64 N, E;
	cin >> N >> E;
	
	vector<House> houses;
	houses.reserve(N);
	
	for(int i=0;i<N;i++){
		u64 a, b;
		cin >> a >> b;
		
		bool stat = false;
		for(int j=0;j<=i;j++){
			if(houses[j].x > a){
				houses.insert(houses.begin()+j, House(a, b));
				stat = true;
				break;
			}
		}
		if(!stat) houses.push_back(House(a,b));
	}
	
/*	for(int i=0;i<N;i++){
		cout << houses[i].x << " " << houses[i].y << endl;
	}*/
	
	Pipe pipes(houses[0], E);
	
	for(int i=1;i<N;i++){
		pipes.operate(houses[i]);
	}
	
	cout << pipes.stack;
	
    return 0;
}
