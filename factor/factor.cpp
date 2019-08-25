#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	float a, b;
	cin >> a >> b;
	
	int result = 0;
	
	if(a==1){
		result += 1;
		a+=1;
	}
	
	for(float i=a;i<=b;i+=1){
		result+=2;
		
		if((int)i%2 != 0) {
			for(float j=3;j<i;j+=2){
				float temp = i/j;
		 		if(temp < j) break;
				else if (temp - (int)temp != 0) continue;
				else if (temp == j) result += 1;
				else result +=2;
			}
		}
		else{
			for(float j=2;j<i;j+=1){
				float temp = i/j;
				if(temp < j) break;
				else if (temp - (int)temp != 0) continue;
				else if (temp == j) result += 1;
				else {
					result +=2;
				}
			}
		}
	}
	
	cout << result;
	
    return 0;
}
