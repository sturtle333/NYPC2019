#include <iostream>

#define u64 long long
#define endless true

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	bool *stat = new bool[N];
	
	char email[100];
	for(int i=0;i<N;i++) {
		cin >> email;
		
		stat[i] = true;
		
		int length = -1;
		while (email[++length] != '\0');

		int atsign = -1;
		while (email[++atsign] != '@');
	
		if(atsign < 1 || atsign > 100 || atsign == length || length - atsign <= 1) stat[i] = false;
	
		for(int j=0;j<length && stat[i];j++) {
			int n = (int)email[j];
			if(n == '-' || n == '.') continue; // - , .
			else if(n >= (int)'0' && n <= (int)'9') continue; // number
			else if(n >= (int)'A' && n <= (int)'Z') continue; // Upcase
			else if(n >= (int)'a' && n <= (int)'z') continue; // Downcase
			else if(n == '@' && j == atsign) continue; // @
			else {
				stat[i] = false;
				break;
			}
		}
	}

	for (int i=0;i<N;i++) {
		if(stat[i]) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}

    return 0;
}
