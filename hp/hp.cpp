#include <iostream>

#define u64 long long
#define endless true

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int hp, T;
	
	cin >> hp >> T;
	
	int Max = hp;
	
	for(int i=0;i<T;i++) {
		int a, b;
		cin >> a >> b;
		
		switch(a) {
			case 1:
				hp -= b;
				break;
			case 2:
				hp += b;
				Max = b==0? hp : Max;
				break;
			case 3:
				hp += b;
				Max = hp;
				break;
		}
	}
	
	cout << Max;
	
    return 0;
}
