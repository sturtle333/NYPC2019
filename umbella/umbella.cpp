#include <iostream>

#define u64 long long
#define endless true
#define uint unsigned int

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, pivot;
	cin >> N >> M >> pivot;
	
	int result = 0;
	int *build = new int[N+1];
	
	for(int i=0;i<N+1;i++) build[i] = 0;
	
	for(int a=0;a<M;a++) {
		int i, Bi;
		cin >> i >> Bi;
		
		if (Bi) {
			if(build[pivot]){
				build[pivot] -= 1;
				build[i] += 1;
			}
			else {
				result++;
				build[i] += 1;
			}
			pivot = i;
		}
		else {
			pivot = i;
		}
	}
	
	cout << result;

    return 0;
}
