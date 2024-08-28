#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>
using namespace std;

// Insertion Sort function that will be called in pthread_create
void insertionSort(int v[], int min, int max)
{
	for(int i=min; i<max; i++){
		int key = v[i];
		int j = i - 1;
		while(j>=min and v[j]>key){
			v[j+1] = v[j];
			j = j - 1;
		}
		v[j+1] = key;
	}
}

// Merge function to merge all the arrays togther
void merge(int A[], int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1];
	int R[n2];
	for(int i=0; i < n1; i++){
		L[i] = A[left+i];
	}
	for(int j=0; j < n2; j++){
		R[j] = A[mid + j + 1];
	}
	int i = 0;
	int j = 0;
	int k = left;
	while(i < n1 and j < n2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i = i + 1;
		}
		else{
			A[k] = R[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while(i < n1){
		A[k] = L[i];
		i = i + 1;
		k = k + 1;
	}
	while(j < n2){
		A[k] = R[j];
		j = j + 1;
		k = k + 1;
	}
}

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

	thread thread0(insertionSort, v, 0, 125000);
	thread thread1(insertionSort, v, 125000, 250000);
	thread thread2(insertionSort, v, 250000, 375000);
	thread thread3(insertionSort, v, 375000, 500000);
	thread thread4(insertionSort, v, 500000, 625000);
	thread thread5(insertionSort, v, 625000, 750000);
	thread thread6(insertionSort, v, 750000, 875000);
	thread thread7(insertionSort, v, 875000, 1000000);

	thread0.join();
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();
	thread6.join();
	thread7.join();

	// Merging first half
	merge(v, 0, 124999, 250000-1);
	merge(v, 250000, 374999, 500000-1);
	merge(v, 0, 249999, 500000-1);

	// Merging second half
	merge(v, 500000, 624999, 750000-1);
	merge(v, 750000, 874999, 1000000-1);
	merge(v, 500000, 749999, 1000000-1);

	// Merging first and second half together
	merge(v, 0, 499999, 1000000-1);

        fout.open(argv[2], ios::out | ios::trunc);
        for (int i = 0; i < count; i++)
		fout << v[i]<<endl;


        fout.close();
	fin.close();
        return 0;
}


