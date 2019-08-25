#include <iostream>
#include <vector>
#include <stdint.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define uiny long int

using namespace std;

void vectorRst (vector<uiny> &v) {
	vector<uiny> temp(0);
	temp.swap(v);
}

class obj {
	private:
		bool first = false;
	public:
		uiny owner;
		uiny ID;
		uiny score;
		uiny defeat;
		
		obj(uiny x, uiny n) {
			if(!first){
				owner = x;
				ID = x;
				score = 0;
				defeat = 0;
				first = !first;
			}
		}
		
		void ownerChg (uiny x) {
			owner = x;
		}
		
		void win () {
			score+=1;
		}
		
		void lose () {
			defeat += 1;
		}
};

class group {
	public:
		vector <uiny> players;
		uiny member;
		
		group (uiny x){
			players.assign(1,x);
			member = 1;
		}
		
		void addMem (uiny x) {
			member += x;
		}
		
		void del () {
			vectorRst(players);
			member = 0;
		}
};

int main () {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	
	uiny N, M;
	cin >> N >> M;
	
	uiny maxMember = 1;
	vector <obj> Object;
	vector <group> Group;
	
	Object.reserve(N);
	Group.reserve(N);
	
	for(uiny i=1;i<=N;i++){
		Object.push_back(obj(i, N));
		Group.push_back(group(i));
	}
	
	for(auto i=0;i<M;i++){
		uiny a, b;
		cin >> a; a-=1;
		cin >> b; b-=1;
		
//		cout << endl << "a stat : " << Object[a].owner << " " << Object[a].score <<endl;
//		cout << endl << "b stat : " << Object[b].owner << " " << Object[b].score <<endl;
		
		Object[a].win();
		Object[b].lose();
		
		uiny A_G = Object[a].owner; A_G -= 1;
		uiny B_G = Object[b].owner; B_G -= 1;
		
		if(A_G == B_G) {
//			cout << "just : " << a+1 << " " << b+1 << endl;
			continue;
		}
		else {
			Group[A_G].addMem(Group[B_G].member);
			
			for(uiny j=0;j<Group[B_G].member;j++){
				uiny temp = Group[B_G].players[j];
				Group[A_G].players.push_back(temp);
				Object[temp-1].ownerChg(A_G+1);
			}
			maxMember = Group[A_G].member >= maxMember? Group[A_G].member : maxMember;
			
			Group[B_G].del();
//			cout << "sum : " << a+1 << " " << b+1 << endl;
		}
//		cout << endl << "a stat : " << Object[a].owner << " " << Object[a].score <<endl;
//		cout << endl << "b stat : " << Object[b].owner << " " << Object[b].score <<endl;
	}
	
	uiny winner = N+1;
	
	for(int i=0;i<N;i++) {
/*		for(int j=0;j<Group[i].member;j++) {
			cout << endl << " : " << Group[i].players[j] << endl;
		}*/
		if(Group[i].member == maxMember) {
			const group &G = Group[i];
			
			vector <uiny> max(1,N+1);
			vector <uiny> min(1,N+1);
			uiny maxNum = 0;
			uiny minNum = N+1;
			uiny minPlayer = N+1;
			
			for(auto j=0;j<G.member;j++){
				const obj &temp = Object[G.players[j]-1];
				
				if(temp.score > maxNum){
					vectorRst(max);
					max.assign(1,temp.ID);
					maxNum = temp.score;
				}
				else if(temp.score == maxNum){
					max.push_back(temp.ID);
				}
				if(temp.defeat < minNum){
					vectorRst(min);
					min.assign(1,temp.ID);
					minNum = temp.defeat;
				}
				else if(temp.defeat == minNum){
					min.push_back(temp.ID);
				}
				if(minPlayer < temp.ID) {
					minPlayer = temp.ID;
				}
			}
			if((int)max.size() == 1 && winner > max[0]){
				winner = max[0];
			}
			else if((int)min.size() == 1 && winner > min[0]) {
				winner = min[0];
			}
			else if (winner > minPlayer){
				winner = minPlayer;
			}
			vectorRst(max);
			vectorRst(min);
		}
	}
	
	cout << winner;
	return 0;
}
