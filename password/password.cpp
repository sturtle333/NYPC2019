#include <iostream>
#include <vector>

#define endless true
#define u64 long long

using namespace std;

int strlen (char *str) {
	int result = 0;
	while (str[result++] != '\0');
	return result - 1;
}

int checking (char *str) {
	bool isUp = false;
	bool isDown = false;
	bool isNum = false;
	bool isSpe = false;
	
    for(int i=0;i<strlen(str);i++){
    	int n = (int)str[i];
    	if(n >= (int)'a' && n <= (int)'z') {
    		isDown = true;
    		continue;
		}
		else if(n >= (int)'A' && n <= (int)'Z') {
			isUp = true;
			continue;
		}
		else if(n >= (int)'0' && n <= (int)'9') {
			isNum = true;
			continue;
		}
		else if(n >= (int)'!' && n <= (int)'~') {
			isSpe = true;
			continue;
		}
		else {
			return 0;
		}
	}
	return isUp*isDown*isNum*isSpe;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int result;
	
    char str[100];
    cin >> str;
    
    int length = strlen(str);
    
    if(length < 8 || length > 15) result = 0;
    else result = checking(str);
    
	if(result) cout<<"valid";
	else cout<<"invalid";

    return 0;
}
