#include <iostream>
#include <vector>

#define u64 unsigned long long
#define uu64 long long

#define endless true
#define endl "\n"

using namespace std;

class Ticket{
	public:
		u64 start;
		u64 end;
		
		Ticket (u64 s, u64 e){
			start = s;
			end = e;
		}
};

class Line {
	public:
		u64 date;
		u64 size;
		vector<Ticket> lines;
		vector<u64> blank;
		
		Line (Ticket t) {
			lines.push_back(t);
			date = t.end;
			size = 1;
			if(t.start!=1) blank.push_back(t.start-1);
		}
		
		Line (const Line &obj) {
			lines.assign(obj.lines.begin(),obj.lines.end());
			date = obj.date;
			size = obj.size;
		}
		
		void addT (Ticket t) {
			lines.push_back(t);
			date += t.end;
			size += 1;
			if(t.start-date!=1) blank.push_back(t.start-1);
		}
		
		void rollback () {
			date -= lines[size-1].end;
			lines.pop_back();
			size -= 1;
		}
		
		int operT (Ticket t) {
			u64 tempDate = date - lines[size-1].end;
			if(size == 1) {
				return 0;
			}
			else if(tempDate + t.end > date && tempDate < t.start) {
				return 1;
			}
			else {
				return 0;
			}
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	u64 N;
	cin >> N;
	
	u64 result = 0;
	
	vector<Ticket> ticket;
	ticket.reserve(N);
	
	for(int i=0;i<N;i++){
		u64 start, end;
		cin >> start >> end;
		
		u64 sum = start + end - 1;
		bool stat = false;
		
		for(int j=0,pp=(int)ticket.size();j<pp;j++){
			if(ticket[j].start > start){
				ticket.insert(ticket.begin()+j, Ticket(start, end));
				stat = true;
				break;
			}
			else if(ticket[j].start == start && ticket[j].end < end){
				ticket.insert(ticket.begin()+j, Ticket(start, end));
				stat = true;
				break;
			}
		}
		if(!stat) ticket.push_back(Ticket(start, end));
	}
	
/*	for(int i=0,pp=(int)ticket.size();i<pp;i++){
		cout << ticket[i].start << " " << ticket[i].end << endl;
	}*/
	
	vector<Line> line;
	line.reserve(N);
	line.push_back(Line(ticket[0]));
	
	for(int i=0;i<N;i++){
		bool stat = false;
		int pp2=(int)line.size();
		for(int j=0;j<pp2;j++){
			if(ticket[i].start <= line[j].date) {
				int vv = line[j].operT(ticket[i]);
				if(vv == 1){
					line.insert(line.begin()+j,Line(line[j]));
					line[j].rollback();
					line[j].addT(ticket[i]);
//					cout << "inher" << endl;
				}
				else if (!stat) {
					line.push_back(Line(ticket[i]));
					stat = true;
//					cout << "new" << endl;
				}
			}
			else {
				line[j].addT(ticket[i]);
//				cout << "add" << endl;
			}
		}
	}
	
	
/*	for(int i=0,pp1=(int)line.size();i<pp1;i++){
		cout << i << " : " << endl;
		for(int j=0,pp2=(int)line[i].lines.size();j<pp2;j++){
			cout << line[i].lines[j].start << " " << line[i].lines[j].end << " " << line[i].date << endl;
		}
	}*/
	
	u64 maxValue = 0;
	for(int i=0,pp1=(int)line.size();i<pp1;i++){
		if(maxValue < line[i].date) {
			maxValue = line[i].date;
		}
	}
	
	cout << maxValue;
	
    return 0;
}
