/**
 * @file main.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include "sort.h"
#include "bubbleSort.h"
#include "bubblesort_optimized.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "standardSort.h"
#include "mergeSort.h"

using namespace std;

void printVector(vector<int> &vec);
void fillVectorRandom(vector<int> &vec, int count);
void fillVectorAsc(vector<int> &vec, int count);
void fillVectorDsc(vector<int> &vec, int count);
void testSort(Sort* sort, vector<int> &vec, string initialCondition, int size, int iterationCount);

#endif