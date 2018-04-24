#include<iostream>
#include<cmath>
using namespace std;

// class for showing the test 
class Set
{
	
	public:
	char *array; // pointer to the array input by the user
	int size; // size of the array input by the user 
	
        Set(int s) // Constructor 
	{
		array=new char[s];
		size=s;
	}
	~Set() // Destructor
        {
		delete []array;
        }
	void enter(); // function to get elements of the array by user
	void display(); // function to display the elements of the array
	void cardinality(); // function to find the cardinality of the set
	void duplicate(); // function to remove the duplicte elements form the array
	bool isMember(char a); // function to check if the given element is in the set or not
	Set setUnion(const Set &); // Function of the type "Set" which will give the union of two sets (one set is provided as argument to the function)
	Set setIntersection(const Set &); // Function of the type "Set" which will give the intersection of two sets (one set is provided as argument to the function)
	Set setDifference(const Set &); // Function of the type "Set" which will give the difference of two sets (one set is provided as argument to the function) 
	void setPowerSet(); // Function to find the power set of the given set
	bool setSubset(const Set &); // Function to check if the set given as arguments is the subset of the original set
		
};
void Set::enter() // function to get elements of the array by user
{   
	// getting the user input 
	for(int i=0  ;	 i<size   ;	 i++)
	{
		cout<<"Enter Element"<<(i+1)<<":";
		cin>>array[i]; 
	}
	return;
}

void Set::display() // function to display the elements of the array
{   
	// for loop to loop through each element of the array and displaying them
	for(int i=0  ;	 i<size ;  i++)
	{
		cout<<array[i]<<"	";
	}
	return;
}

void Set::cardinality() // function to find the cardinality of the set
{
	cout<<"\nCardinality="<<size<<endl; // since the size of the array is the cardinality of the array(set) 
	return;
}

void Set::duplicate()  // function to remove the duplicte elements form the array
{
	for(int i=0 ;  i<size ;  i++) // this for-loop will loop through the whole array 
	{
		for(int j=i+1 ;  j<size ; j++) // this for-loop will loop through the whole array starting from the element next to the "i"
		{
			if(array[j]==array[i]) // if the element (array[i]) is repeated in the array then ...
			{
				for(int k=j ;  k<size-1 ;  k++) // ... this will loop through the array starting form the point of duplication and .....
				{
					array[k]=array[k+1]; // ... every element will eventually become equal to their next counterpart.
				}
                		//j--; 
		                size--; // size will be decreased
			}
		}
	}
	return;
}
bool Set::isMember(char a)  // function to check if the given element is in the set or not
{
	for(int i=0 ;   i<size ;   i++)
	{
		if(array[i]==a)
		{
			return true;
		}
	}
	return false;
}

Set Set::setUnion(const Set &a) // Function of the type "Set" which will give the union of two sets (one set is provided as argument to the function)
{	
	int i;
    	Set temp(size+a.size);
	for( i=0 ; i<a.size ; i++)
	{
		temp.array[i]=a.array[i];
	}
		
	for(int j=0 ; j<size ; j++,i++)
	{
		temp.array[i]=array[j];
	}
	return temp;
}

Set Set::setIntersection(const Set &a) // Function of the type "Set" which will give the intersection of two sets (one set is provided as argument to the function)
{	
	int i,k=0;
    	Set temp(size+a.size);
	for( i=0 ; i<a.size ; i++)
	{
		for(int j=0 ; j<size ; j++)
		{
			if(a.array[i]==array[j])
			{
				temp.array[k]=array[j];
				k++;
				temp.size=k;
			}
		}
	}
	return temp;
}

Set Set::setDifference(const Set& a) // Function of the type "Set" which will give the difference of two sets (one set is provided as argument to the function) 
{
    int i,k=0,q=0;
    Set temp(size+a.size);
	for( i=0 ; i<a.size ; i++)
	{
		q=0;
		for(int j=0 ; j<size ; j++)
		{
			if(a.array[i]==array[j])
			{
				q=1;
				break;
			}
		}
		if(q==0)
		{
			temp.array[k]=a.array[i];
			k++;
			temp.size=k;
		}
	}
	return temp;
}

void Set::setPowerSet()  // Function to find the power set of the given set
{
	/*	int numOfPowerSet=pow(2,size);
	int **a=new int *[numOfPowerSet];
	int number,remainder;
	for(int i=0 ; i<numOfPowerSet ; i++)
	{
		a[i]=new int[size];
	}
	
	for(int i=0 ; i<numOfPowerSet ; i++)
	{
		number=i;
		for(int j=size-1 ; j>=0 ; j--)
		{
			remainder=number%2;
			a[i][j]=remainder;
			number=number/2;
		}
	}
	
	for(int i=0; i<numOfPowerSet ; i++)
	{
		number=0;
		cout<<i<<"==";
		for(int j=0 ; j<size ; j++)
		{
			cout<<a[i][j];
			if(a[i][j]==1)
				number++;
		}
		cout<<"  {";
		for(int j=0 ; j<size ; j++)
		{
			if(a[i][j]==1)
			{
				cout<<array[j];
				number--;
				if(number>0)
				{
					cout<<",";
				}
			}	
		}
		cout<<"}"<<endl;
	} */
	
	
	int numOfPowerSet=pow(2,size);
	int i,j,k,stringSize;
	for(i=0 ; i<numOfPowerSet ; i++)
	{
		k=1;
		for(j=0 ;  ; j++)
		{
			//k=pow(2,j);
			if(j==0)
				k=1;
			else 
				k=k<<1;
			if(k>i)
			{
				break;
			}
		}

		int n=i;
		string s1, s2;
		for(int l=j-1 ; l>=0 ; l--)
		{
			//int m=pow(2,l);
			k=k>>1;
			if(n>=k)
			{
				 s1="1";cout<<"1";
				n=n-k;
			}
			else
			{
				 s1="0";cout<<"0";
			}
			  
			 s2=s2+s1;
		}
		cout<<"\n"<<i<<"----"<<s2<<"\t";
		stringSize=s2.size();
		 s1="0";
		for(int h=1 ; h<=(size-stringSize) ; h++)
		{
			s2=s1+s2;
		}
		//s2=s1+s2;
		stringSize=s2.size();
		cout<<" s2=="<<s2<<"\t";
		for(int h=0 ; h<stringSize ; h++)
		{
			if(s2[h]!='0')
			{
				cout<<array[h]<<"\t";
			}
		}
		cout<<endl;
		s2.clear();
	}
}
bool Set::setSubset(const Set &a) // Function to check if the set given as arguments is the subset of the original set
{
	int q=size;
	// Logic to check if every element of the set a is in the set given by the user	
	for(int i=0 ; i<size ; i++) 
	{
		for(int j=0 ; j<a.size ; j++)
		{
			if(array[i]==a.array[j])
			{
				q--;
			}
		}
	}
	if(q==0)
		return true;
	else
		return false;
}
int main()
{
    cout<<endl<<"Set 1-----------"<<endl;
    Set s1(5);
    s1.enter();
    s1.duplicate();
    s1.display();
    
    cout<<endl<<"Set 2-----------"<<endl;
    Set s2(6);
    s2.enter();
    s2.duplicate();
    s2.display();
    
    cout<<endl<<"Set 3 (Union of Set 1 and Set 2)-----------"<<endl;
    Set s3=s2.setUnion(s1);
    s3.duplicate();
    s3.display();
    
    cout<<endl<<"Set 4 (Intersection of Set 1 and Set 2-----------"<<endl;
    Set s4=s2.setIntersection(s1);
    s4.duplicate();
    s4.display();
	
   cout<<endl<<"Set 5 (PowerSet-----------"<<endl;
   Set s5(4);
   s5.enter();
   s5.duplicate();
   s5.setPowerSet();
   
    s5=s1.setDifference(s2);
    
    
    
   
    cout<<endl<<"Set 6 (Set Difference of Set 1 and Set 2-----------"<<endl;
     Set s6=s1.setDifference(s2);
     s6=s2.setDifference(s1);
    s6.display();    
    cout<<endl<<"Set 7 (Set Difference of Set 1 and Set 2-----------"<<endl;
     Set s7=s2.setDifference(s1);
     s7=s5.setUnion(s6);
     //s7.display();cout<<endl;
    s7.display();
 	
    cout<<endl<<"Set 8 (Symmetric Difference of Set 1 and Set 2-----------"<<endl;
    Set s8=(s1.setDifference(s2)).setUnion(s2.setDifference(s1));
    s8.display();

    cout<<endl<<"Set 9 (is Set 1 subset of Set 2-----------"<<endl;
    cout<<s1.setSubset(s2);
    
    //Set s8=s1.setUnion(s2.setUnion(s7));
    cout<<endl;
    s8.duplicate();
    s8.display();

	return 0;
}

	
