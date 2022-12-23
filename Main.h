#ifndef MAIN_H
#define MAIN_H

#include<vector>
#include<iostream>
#include<assert.h>

//include files
#include "Hash.h"
#include "LinearProbing.cpp"
// quadratic probing file
#include "QuadraticProbing.cpp"

using namespace std;

//function prototypes
void testLinearInsertOneCollision();
void testLinearInsertMultipleCollisionRehash();
void visualTestCaseLinear();
//add more
void testRemovingElem();
void testRehash();
void testFindItem();
void testExcessItems();
void testDeleted();


// quad
void testQuadInsertOneCollision();
void visualTestCaseQuad();
void testQuadInsertMultipleCollisionRehash();
void testRemovingElemQuad();
void testRehashQuad();
void testFindItemQuad();
void testExcessItemsQuad();
void testDeletedQuad();


#endif