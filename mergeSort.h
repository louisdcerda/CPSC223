/**
 * @file mergeSort.h
 * @author louis Cerda
 * @brief implementation of merge sort
 * @version 0.1
 * @date 9/31/2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "sort.h"
using namespace std;


class MergeSort : public Sort{
    public:
        MergeSort(){
            name = "Merge Sort";
        }

        void doSort(vector<int> &vec) 
        {
            // TODO: Implement insertion sort
           mergeSort(vec);
        }

        void mergeSort(vector<int> & a)
        {
            // creating a temp arr with size of arr a
            vector<int> temp (a.size());

            // calling mergeSort func with a, temp arr, left most value, and right most value(size of a)
            mergeSort(a, temp, 0, a.size() - 1);
        }

        void mergeSort(vector<int> & a, vector<int> & temp, int left, int right)
        {   
            // stop case
            if (left < right)
            {   
                // creating a center to begin dividing at
                int center = (left + right) / 2;

                // dividing the left side till stop case
                mergeSort(a, temp, left, center);
                // dividing the right side till stop case
                mergeSort(a, temp, center + 1, right);

                // merging
                merge(a, temp, left, center + 1, right);

            }
        }

        void merge(vector<int> & a, vector<int> & tmpArray, int leftPos, int rightPos, int rightEnd)
        {
            int leftEnd = rightPos - 1;
            int tempPos = leftPos;
            int elemNum = rightEnd - leftPos + 1;

            // this is where the pointers go into place checking the right and left end values
            while (leftPos <= leftEnd && rightPos <= rightEnd)
            {
                if (a[leftPos] <= a[rightPos]) //leftEnd && rightPos <= a[rightPos])
                    tmpArray[tempPos++] = move(a[leftPos++]);
                else
                    tmpArray[tempPos++] = move(a[rightPos++]);
            }


            // coping the rest of the right and left half into the arr
            while(leftPos <= leftEnd)
                tmpArray[tempPos++] = move(a[leftPos++]);
            while(rightPos <= rightEnd)
                tmpArray[tempPos++] = move(a[rightPos++]);
            

            // coping temp array nack 
            for (int i = 0; i < elemNum; ++i, --rightEnd)
                a[rightEnd] = move(tmpArray[rightEnd]);
        }
};

#endif



