#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
		for(int i=0; i<size; i++){
				int temp =0;
				for(int j=i; j<size; j++){
						if(array[i] > array[j]){
							temp = array[i];
							array[i] = array[j];
							array[j] = temp;
							}
					}
				cout<<"Array in"<<i<<" pass:";
				for(int k=0; k<size; k++){
					 cout<<array[k];
					}
				cout<<endl;
			}
		cout<<"Final Array:";
		for(int z=0; z<size; z++){
				cout<<array[z];
			}
	}


int main() {
		int size;
		cout<<"Enter the size of the array:";
		cin>>size;
		int array[size];
		cout<<"Enter the array elements:";
		for(int i=0; i<size; i++){
			cin>>array[i];
		}	
	    bubbleSort(array, size);
	    return 0;
	}
