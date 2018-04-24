#include <iostream>
using namespace std;

void towerOfHanoi(int n, char start, char inter, char last){
		if(n == 1){
				cout<<"Move"<<n<<"from"<<start<<"to"<<last<<endl;
				return;
			}
			
	     towerOfHanoi(n-1, start, last, inter);
	     cout<<"Move"<<n<<"from"<<start<<"to"<<last<<endl;
	     towerOfHanoi(n-1, inter, start, last);
	}
	
int main() {
		int noOfDiscs;
		cout<<"Enter the number of discs";
		cin>>noOfDiscs;
		
		towerOfHanoi(noOfDiscs, 'A', 'B', 'C');
		return 0;
	}
