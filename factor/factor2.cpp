#include <iostream>
#define u64 unsigned long
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	u64 a, b, result = 0;
	cin >> a >> b; a-= 1;
	for(u64 i=1;i<=b;i+=1) result += b/i - a/i;
	cout << result;
    return 0;
}
