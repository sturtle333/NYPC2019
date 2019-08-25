#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	
    int N;  //입력
	cin >> N;
	
	int *ing = new int[N];
	int *req = new int[N];
	for(int i=0;i<N;i++){
		cin >> ing[i];
	}
	for(int i=0;i<N;i++){
		cin >> req[i];
	}
	
	int result = 100; 
	for(int i=0;i<N;i++) { //연산
		int temp;
		if(req[i] != 0) temp = ing[i] / req[i];
		else continue;
		
		result = result > temp ? temp : result;
	}
	
	cout << result;
	
    return 0;
}
