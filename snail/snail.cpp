#include <iostream>

#define u64 long long
#define endless true

using namespace std;

void a(int N, int *v, int *h) {
	int pivot = (N+1)*5;
	int temp = pivot - 10;
	for(int i=0,stat=1;i<N;i++) {
		if(temp <= 0) {
			v[i] = pivot/10;
			h[i] = pivot/10;
			break;
		}
		if(stat){
			v[i] = (pivot + temp)/10;
			h[i] = (pivot - temp)/10;
			stat = 0;
		}
		else {
			v[i] = (pivot - temp)/10;
			h[i] = (pivot + temp)/10;
			stat = 1;
			temp-=10;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	int *v = new int[N];
	int *h = new int[N];
	int result[2] = {1,1};
	
	a(N, v, h);
	
	int vTemp = 0;
	int hTemp = 0;
	
	if(K-N <= 0) {
		result[0] = K;
	}
	else {
		bool isV = true;
		K -= N;
		N--;
		while(N>0) {
			if(isV){
				if(K-N <= 0) {
					result[0] = v[vTemp];
					result[1] = (h[hTemp] + (hTemp%2==0?K:K*=-1));
					break;
				}
				else {
					K -= N;
					isV = !isV;
					hTemp++;
				}
			}
			else{
				if(K-N <= 0) {
					result[0] = (v[vTemp] + (vTemp%2==1?K:K*=-1));
					result[1] = h[hTemp];
					break;
				}
				else {
					K -= N;
					N--;
					isV = !isV;
					vTemp++;
				}
			}
		}	
	}
	
	cout << result[0] << " " << result[1];
	
    return 0;
}
