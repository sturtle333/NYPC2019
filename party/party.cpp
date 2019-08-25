#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdint.h>
#include <algorithm>

#define u64 unsigned long long int
#define endless true

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
  while (begin != end) {
    std::cout << *begin << " ";
    begin++;
  }
  std::cout << std::endl;
}

void checking (const vector<u64> &v, u64 a, u64 b, u64 c, u64 d) {
	vector<u64> front(v.begin()+(a-1),v.begin()+b);
	vector<u64> back(v.begin()+(c-1),v.begin()+d);
	
//	print(front.begin(),front.end());
//	print(back.begin(),back.end());
	
	sort(front.begin(),front.end());
	sort(back.begin(),back.end());
	
//		print(front.begin(),front.end());
//	print(back.begin(),back.end());
	
	for(int i=0,pp=(int)front.size()-1;i<pp;i++){
		if(front[i] == front[i+1]) {
			front.erase(front.begin()+i);
			pp-=1;
		}
	}
	for(int i=0,pp=(int)back.size()-1;i<pp;i++){
		if(back[i] == back[i+1]) {
			back.erase(back.begin()+i);
			pp-=1;
		}
	}
//		print(front.begin(),front.end());
//	print(back.begin(),back.end());
	
	
	if(front == back) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int N, Q;
    cin >> N >> Q;
    
    vector<u64> job;
    job.reserve(N);
    
    for(int i=0;i<N;i++){
    	u64 tmp;
    	cin >> tmp;
    	job.push_back(tmp);
	}
	
	for(int i=0;i<Q;i++){
		u64 a, b, c, d;
		cin >> a >> b >> c >> d;
		
		checking(job, a, b, c, d);
	}
    
    return 0;
}
