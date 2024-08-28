// Jorge Gutierrez
// CECS 325-02
// Prog 5 - Sorting Contest (threading with thread)
// October 25, 2022
//
// I certify that this program is my own original work. I did not copy
// any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Please include input filename and output filename in param list.\n";
		cout << "Example:\n";
		cout << "     % mySortA numbers.txt mySorted.txt\n";
		exit(EXIT_SUCCESS);
	}


	const int MAX = 1000000;
  	ofstream fout;
	ifstream fin;
	int n;
	
	int v[MAX];
	int count = 0;
	
	fin.open(argv[1]);
	while (fin >> n )
	{
		v[count++] = n;	// insert a number into the arary and increase the index
	}

	int checker = 0;
	for(int i=0; i < (sizeof(v)/sizeof(v[0]))-1; i++){
		if(v[i] > v[i+1]){
			cout << (sizeof(v)/sizeof(v[0])) << " Not Sorted" << endl;
			cout <<"Line error: " << i << endl;
			checker = 1;
			break;
		}
	}
	if(checker == 0){
		cout << (sizeof(v)/sizeof(v[0])) << " Sorted" << endl;
	}

        //fout.open(argv[2], ios::out | ios::trunc);
        //for (int i = 0; i < count; i++)
	//	fout << v[i]<<endl;


        //fout.close();
	fin.close();
        return 0;
}	
