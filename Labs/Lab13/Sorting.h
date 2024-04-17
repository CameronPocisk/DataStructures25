#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <chrono>
using namespace std;
typedef chrono::high_resolution_clock Clock;



class Sorting{
    private:
        const static int size10 = 10;
        const static int size100 = 100;
        const static int size500 = 500;
        const static int size5000 = 5000;
        const static int size25000 = 25000;
        const static int size100000 = 100000;

        int arr10[size10];
        int arr100[size100];
        int arr500[size500];
        int arr5000[size5000];
        int arr25000[size25000];
        int arr100000[size100000];

        int sizes[6];
        int* arrays[6];

    public:
        Sorting(){
            sizes[0] = size10;
            sizes[1] = size100;
            sizes[2] = size500;
            sizes[3] = size5000;
            sizes[4] = size25000;
            sizes[5] = size100000;
            
            arrays[0] = arr10;
            arrays[1] = arr100;
            arrays[2] = arr500;
            arrays[3] = arr5000;
            arrays[4] = arr25000;
            arrays[5] = arr100000;

            srand(time(NULL));
            //Populate the arrays
            for(int i = 0; i < 6; i++){
                int size = sizes[i];
                int* arr = arrays[i];
                for(int j = 0; j < size; j++){
                    arr[j] = rand() % (2*size) + 1;
                }
            }
            cout << "Arrays created" << endl;
        }

        void BubbleSort(int *arr, int size){
            for(int i = 0; i < size - 1; i++){
                bool swapped = false;
                for(int j = 0; j < size - i - 1; j++){
                    if(arr[j] > arr[j+1]) {
                        int hold = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = hold;
                        swapped = true;
                    }
                }
                if(!swapped){
                    //No swaps were made already in order
                    break;
                }
            }


            if(CheckSorting(arr, size)){
                cout << "Sorted!" << endl;
            } else {
                cout << "uhh" << endl;
            }
        }
        void BubbleAll(){
            for(int i = 0; i < 6; i++){
                int size = sizes[i];
                int* arr = arrays[i];
                

                auto t1 = Clock::now();
                //Put the algorithm inbetween
                BubbleSort(arr, size);
                auto t2 = Clock::now();
                 cout << "Bubble Sorted " << size << " in:" << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
            }
 
        }

        void InsertionSort(int *arr, int size){
            for(int i = 0;i < size; i++){
                int hold = arr[i];
                int j = i-1;

                while(j >= 0 && arr[j] > hold) {
                    arr[j+1] = arr[j];
                    j--;
                }

                arr[j+1] = hold;
            }

            if(CheckSorting(arr, size)){
                cout << "Sorted!" << endl;
            } else {
                cout << "uhh" << endl;
            }
        }

        void InsertionAll(){
            for(int i = 0; i < 6; i++){
                int size = sizes[i];
                int* arr = arrays[i];
                

                auto t1 = Clock::now();
                //Put the algorithm inbetween
                InsertionSort(arr, size);
                auto t2 = Clock::now();
                 cout << "Insertion Sorted " << size << " in:" << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
            }
        }

        void MergeSort(int* arr, int left, int right){
            if(left < right){
                int mid = left + (right - left) / 2;

                MergeSort(arr, left, mid);
                MergeSort(arr, mid + 1, right);

                Merge(arr, left, mid, right);
            } 
            // else{
            //     //Will do multiple since recursion calls
            //     if(CheckSorting(arr, right + 1)){
            //         cout << "Sorted!" << endl;
            //     }
            // }
        }

        void Merge(int * arr, int left, int mid, int right){
            int lSize = mid - left + 1;
            int rSize = right - mid;

            int* leftArr = new int[lSize];
            int* rightArr = new int[rSize];

            for(int i = 0; i < lSize; i++){
                leftArr[i] = arr[left + i];
            }
            for(int i = 0; i < rSize; i++){
                rightArr[i] = arr[mid + 1 + i];
            }

            int i = 0, j = 0, pos = left;
            while(i < lSize && j < rSize){
                if(leftArr[i] <= rightArr[j]){
                    arr[pos] = leftArr[i];
                    i++;
                } else {
                    arr[pos] = rightArr[j];
                    j++;
                }
                pos++;
            }

            while(i < lSize){
                arr[pos] = leftArr[i];
                i++;
                pos++;
            }

            while(j < lSize){
                arr[pos] = rightArr[j];
                j++;
                pos++;
            }

            delete[] leftArr;
            delete[] rightArr;
        }

        void MergeAll(){
            for(int i = 0; i < 6; i++){
                int size = sizes[i];
                int* arr = arrays[i];
                

                auto t1 = Clock::now();
                //Put the algorithm inbetween
                MergeSort(arr, 0, size - 1);
                auto t2 = Clock::now();
                 cout << "Merge Sorted " << size << " in:" << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
            }
        }

        void QuickSort(int* arr, int low, int high){
            // need pivot(random?) i = first - 1
            if(low < high){
                int pivot = QuickPartition(arr, low, high);

                QuickSort(arr, low, pivot - 1);
                QuickSort(arr, pivot + 1, high);
            }
            // else{
            //     //Will do multiple since recursion calls
            //     if(CheckSorting(arr, high + 1)){
            //         cout << "Sorted!" << endl;
            //     }
            // }

        }

        int QuickPartition(int* arr, int low, int high){
            int pivot = arr[rand() % high];
            int i = low - 1;

            for(int j = low; j < high; j++){
                if(arr[j] <= pivot){
                    i++;
                    int hold = arr[i];
                    arr[i] = arr[j];
                    arr[j] = hold;
                }
            }

            int hold = arr[i+1];
            arr[i+1] = arr[high];
            arr[high] = hold;
            return i+1;
        }

        void QuickAll(){
            for(int i = 0; i < 6; i++){
                int size = sizes[i];
                int* arr = arrays[i];
                

                auto t1 = Clock::now();
                //Put the algorithm inbetween
                QuickSort(arr, 0, size - 1);
                auto t2 = Clock::now();
                 cout << "Quick Sorted " << size << " in:" << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
            }
        }

        void CountingSort(){

        }

        void RadixSort(){

        }

        bool CheckSorting(int* arr, int size){
            for(int i = 0; i < size - 1; i++){
                if(arr[i] > arr[i+1]){
                    return false;
                }
            }
            return true;
        }

};


#endif