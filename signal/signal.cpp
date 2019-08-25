#include <iostream>
#include <vector>

#define u64 long long
#define endless true
#define endl '\n'

using namespace std;

class sign {
	private:
		
	public:
		int stat;
		int result;
		int resultStat;
		int NN;
		int MM;
		
		void setup (int x) {
			stat = x;
			result = -1;
			resultStat = -1;
		}
		
		sign (int x, int N, int M) {
			stat = x;
			NN = N;
			MM = M;
			result = -1;
			resultStat = -1;
		}
		
		void assign (int T, vector<vector<sign>> &signal) {
			if(T < result) {
				result = T;
				resultStat = (stat + T) % 4;
				
				if(NN!=0)signal[NN-1][MM].assign(signal[NN][MM].moveUp(),signal);
				if(NN!=(int)signal.size()-1)signal[NN+1][MM].assign(signal[NN][MM].moveDown(),signal);
				if(MM!=(int)signal[NN].size()-1)signal[NN][MM+1].assign(signal[NN][MM].moveRight(),signal);
				if(MM!=0)signal[NN][MM-1].assign(signal[NN][MM].moveLeft(),signal);
			}
			else if(result == -1) {
				result = T;
				resultStat = (stat + T) % 4;
			}
		}
		
		int moveRight() {
			return result + (((4-resultStat))%4) + 1;
		}
		int moveUp() {
			return result + (((4+(1-resultStat)))%4) + 1;
		}
		int moveLeft() {
			return result + (((4+(2-resultStat)))%4) + 1;
		}
		int moveDown() {
			return result + (((4+(3-resultStat)))%4) + 1;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, T, pivot[2];
	
	cin >> N >> M >> T >> pivot[0] >> pivot[1];

	vector<vector<sign>> signal(N);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int temp;
			cin >> temp;
			signal[i].push_back(sign(temp,i,j));
		}
	}
	signal[pivot[0]][pivot[1]].assign(T,signal);
	
	N-=1;M-=1;

	
	int _pivot[2] = {pivot[0], pivot[1]};
	
	for(int i=pivot[1]; i<=M; i++) { //¿À¸¥ÂÊ Å½»ö 
		if(_pivot[0]!=0)signal[_pivot[0]-1][i].assign(signal[_pivot[0]][i].moveUp(),signal);
		if(_pivot[0]!=N)signal[_pivot[0]+1][i].assign(signal[_pivot[0]][i].moveDown(),signal);
		if(i!=M)signal[_pivot[0]][i+1].assign(signal[_pivot[0]][i].moveRight(),signal);
		if(i!=0)signal[_pivot[0]][i-1].assign(signal[_pivot[0]][i].moveLeft(),signal);
	}
	for(int i=pivot[1]; i>=0; i--) { //¿ÞÂÊ Å½»ö 
		if(_pivot[0]!=0)signal[_pivot[0]-1][i].assign(signal[_pivot[0]][i].moveUp(),signal);
		if(_pivot[0]!=N)signal[_pivot[0]+1][i].assign(signal[_pivot[0]][i].moveDown(),signal);
		if(i!=M)signal[_pivot[0]][i+1].assign(signal[_pivot[0]][i].moveRight(),signal);
		if(i!=0)signal[_pivot[0]][i-1].assign(signal[_pivot[0]][i].moveLeft(),signal);
	}
	for(int i=pivot[0]; i<=N; i++) { //¾Æ·¡ Å½»ö 
		if(_pivot[1]!=0)signal[i][_pivot[1]-1].assign(signal[i][_pivot[1]].moveLeft(),signal);
		if(_pivot[1]!=M)signal[i][_pivot[1]+1].assign(signal[i][_pivot[1]].moveRight(),signal);
		if(i!=0)signal[i-1][_pivot[1]].assign(signal[i][_pivot[1]].moveUp(),signal);
		if(i!=N)signal[i+1][_pivot[1]].assign(signal[i][_pivot[1]].moveDown(),signal);
	}
	for(int i=pivot[0]; i>=0; i--) { //À§¿¡ Å½»ö 
		if(_pivot[1]!=0)signal[i][_pivot[1]-1].assign(signal[i][_pivot[1]].moveLeft(),signal);
		if(_pivot[1]!=M)signal[i][_pivot[1]+1].assign(signal[i][_pivot[1]].moveRight(),signal);
		if(i!=0)signal[i-1][_pivot[1]].assign(signal[i][_pivot[1]].moveUp(),signal);
		if(i!=N)signal[i+1][_pivot[1]].assign(signal[i][_pivot[1]].moveDown(),signal);
	}
	
	for(int j=1;_pivot[0]-j>=0 && _pivot[1]-j>=0;j++){  //¿ÞÂÊ  À§  
		int purpose[2] = {_pivot[0]-j,_pivot[1]-j};
		
		for(int i=purpose[0]; i>=0; i--) { //À§¿¡ Å½»ö 
			if(i!=0)signal[i-1][purpose[1]].assign(signal[i][purpose[1]].moveUp(),signal);
			if(i!=N)signal[i+1][purpose[1]].assign(signal[i][purpose[1]].moveDown(),signal);
			if(purpose[1]!=M)signal[i][purpose[1]+1].assign(signal[i][purpose[1]].moveRight(),signal);
			if(purpose[1]!=0)signal[i][purpose[1]-1].assign(signal[i][purpose[1]].moveLeft(),signal);
		}
	
		for(int i=purpose[1]; i>=0; i--) { //¿ÞÂÊ Å½»ö 
			if(purpose[0]!=0)signal[purpose[0]-1][i].assign(signal[purpose[0]][i].moveUp(),signal);
			if(purpose[0]!=N)signal[purpose[0]+1][i].assign(signal[purpose[0]][i].moveDown(),signal);
			if(i!=M)signal[purpose[0]][i+1].assign(signal[purpose[0]][i].moveRight(),signal);
			if(i!=0)signal[purpose[0]][i-1].assign(signal[purpose[0]][i].moveLeft(),signal);
		}
	}
	 
	for(int j=1;_pivot[0]-j>=0 && _pivot[1]+j<=M;j++){  //¿À¸¥ÂÊ À§  
		int purpose[2] = {_pivot[0]-j,_pivot[1]+j};
		
		for(int i=purpose[0]; i>=0; i--) { //À§¿¡ Å½»ö 
			if(i!=0)signal[i-1][purpose[1]].assign(signal[i][purpose[1]].moveUp(),signal);
			if(i!=N)signal[i+1][purpose[1]].assign(signal[i][purpose[1]].moveDown(),signal);
			if(purpose[1]!=M)signal[i][purpose[1]+1].assign(signal[i][purpose[1]].moveRight(),signal);
			if(purpose[1]!=0)signal[i][purpose[1]-1].assign(signal[i][purpose[1]].moveLeft(),signal);
		}
	
		for(int i=purpose[1]; i<=M; i++) { //¿À¸¥ÂÊ Å½»ö 
			if(purpose[0]!=0)signal[purpose[0]-1][i].assign(signal[purpose[0]][i].moveUp(),signal);
			if(purpose[0]!=N)signal[purpose[0]+1][i].assign(signal[purpose[0]][i].moveDown(),signal);
			if(i!=M)signal[purpose[0]][i+1].assign(signal[purpose[0]][i].moveRight(),signal);
			if(i!=0)signal[purpose[0]][i-1].assign(signal[purpose[0]][i].moveLeft(),signal);
		}
	}
	
	for(int j=1;_pivot[0]+j<=N && _pivot[1]-j>=0;j++){ // ¿ÞÂÊ ¾Æ·¡  
		int purpose[2] = {_pivot[0]+j,_pivot[1]-j};
		
		for(int i=purpose[0]; i<=N; i++) { //¾Æ·¡ Å½»ö 
			if(i!=0)signal[i-1][purpose[1]].assign(signal[i][purpose[1]].moveUp(),signal);
			if(i!=N)signal[i+1][purpose[1]].assign(signal[i][purpose[1]].moveDown(),signal);
			if(purpose[1]!=M)signal[i][purpose[1]+1].assign(signal[i][purpose[1]].moveRight(),signal);
			if(purpose[1]!=0)signal[i][purpose[1]-1].assign(signal[i][purpose[1]].moveLeft(),signal);
		}
	
		for(int i=purpose[1]; i>=0; i--) { //¿ÞÂÊ Å½»ö 
			if(purpose[0]!=0)signal[purpose[0]-1][i].assign(signal[purpose[0]][i].moveUp(),signal);
			if(purpose[0]!=N)signal[purpose[0]+1][i].assign(signal[purpose[0]][i].moveDown(),signal);
			if(i!=M)signal[purpose[0]][i+1].assign(signal[purpose[0]][i].moveRight(),signal);
			if(i!=0)signal[purpose[0]][i-1].assign(signal[purpose[0]][i].moveLeft(),signal);
		}
	}
	
	for(int j=1;_pivot[0]+j<=N && _pivot[1]+j<=M;j++){  //¿À¸¥ÂÊ ¾Æ·¡ 
		int purpose[2] = {_pivot[0]+j,_pivot[1]+j};
		
		for(int i=purpose[0]; i<=N; i++) { //¾Æ·¡ Å½»ö 
			if(i!=0)signal[i-1][purpose[1]].assign(signal[i][purpose[1]].moveUp(),signal);
			if(i!=N)signal[i+1][purpose[1]].assign(signal[i][purpose[1]].moveDown(),signal);
			if(purpose[1]!=M)signal[i][purpose[1]+1].assign(signal[i][purpose[1]].moveRight(),signal);
			if(purpose[1]!=0)signal[i][purpose[1]-1].assign(signal[i][purpose[1]].moveLeft(),signal);
		}
	
		for(int i=purpose[1]; i<=M; i++) { //¿À¸¥ÂÊ Å½»ö 
			if(purpose[0]!=0)signal[purpose[0]-1][i].assign(signal[purpose[0]][i].moveUp(),signal);
			if(purpose[0]!=N)signal[purpose[0]+1][i].assign(signal[purpose[0]][i].moveDown(),signal);
			if(i!=M)signal[purpose[0]][i+1].assign(signal[purpose[0]][i].moveRight(),signal);
			if(i!=0)signal[purpose[0]][i-1].assign(signal[purpose[0]][i].moveLeft(),signal);
		}
	}
	
	N+=1;M+=1;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M-1;j++){
			cout << signal[i][j].result << " ";
		}
		cout << signal[i][M-1].result << endl;
	}
	
    return 0;
}
