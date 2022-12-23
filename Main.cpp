#include "Main.h"

using namespace std;

int main(){

    //TODO: adequately test your hashTable with
    //  insertions, deletions, searches, etc.
    // add more test cases
    // place tests inside of functions and call those functions from main

    
    // visualTestCaseLinear();
    testLinearInsertOneCollision();
    // testLinearInsertMultipleCollisionRehash();
    // testQuadInsertOneCollision();
    // testRemovingElem();
    // testRehash();
    // testFindItem();
    // testExcessItems();
    // testDeleted();


    // quad 
    // testQuadInsertOneCollision();
    // visualTestCaseQuad();
    // testQuadInsertMultipleCollisionRehash();
    // testRemovingElemQuad();
    // testRehashQuad();
    // testFindItemQuad();
    // testExcessItemsQuad();
    // testDeletedQuad();


}

//print out the hash table after each operation
//showing your program can resolve collisions and
//rehash properly.
void visualTestCaseLinear()
{
    vector<string> hashTable(11);

    LinearProbing* linearHash = new LinearProbing(hashTable);

    // inserting a collison and seeing if it rehashes properly
    linearHash->insertItem(hashTable, "abc");
    // linearHash->printTable(hashTable);
    linearHash->insertItem(hashTable, "acb");
    // linearHash->printTable(hashTable);

    linearHash->printTable(hashTable);

    delete linearHash;
}


//sample test case that should check the hashtable changes in size from 11 to 23
void testLinearInsertMultipleCollisionRehash(){

    //creates a new vector of size 11
    vector<string> hashTable(11);

    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);

    //print the empty hash table
    //linearHash->printTable(hashTable);

    //each of these strings hash to be the same
    linearHash->insertItem(hashTable, "abcdefg"); // 1
    linearHash->insertItem(hashTable, "bcdefga");
    linearHash->insertItem(hashTable, "cdefgab");
    linearHash->insertItem(hashTable, "defgabc");
    linearHash->insertItem(hashTable, "efgabcd");    
    linearHash->insertItem(hashTable, "fgabcde");
    linearHash->insertItem(hashTable, "gabcdef"); // 7

    //print the new hashTable
    linearHash->printTable(hashTable);

    //since load factor increased beyond threshold, table should have been rehashed
    assert(linearHash->getTableSize() == 23); 

    cout << "test passed: multiple collisions" << endl;
    delete linearHash;
}




// simple test case to check that a collision is resolved with quad probing
void testLinearInsertOneCollision(){

    //setup the states of the test
    vector<string>hashTable(11);

    LinearProbing* linearHash = new LinearProbing(hashTable);

    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "bac");

    //check that "abc" and "bac" were placed in the correct locations
    int index = linearHash->hashFunction("abc");
    linearHash->printTable(hashTable);
    assert(hashTable.at(index) == "abc" && hashTable.at(index + 1) == "bac");

    cout << "test case passed: linear probing insertion one collison" << endl;

    delete linearHash;
}



// testing to see if an elem can be removed
void testRemovingElem()
{
    vector<string>hashTable(11);

    LinearProbing* linearHash = new LinearProbing(hashTable);

    string item = "abc";

    linearHash->insertItem(hashTable, item);
    linearHash->printTable(hashTable);
    linearHash->removeItem(hashTable, item);
    linearHash->printTable(hashTable);
    // testing to see if item was removed by trying to find it
    assert(linearHash->findItem(hashTable, item) == false);

    cout << "test case passed: inserting an item and deleting it" << endl;
    delete linearHash;
}


void testRehash()
{
    vector<string>hashTable(11);

    LinearProbing* linearHash = new LinearProbing(hashTable);

    linearHash->insertItem(hashTable, "abc"); // 1
    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "abc");
    linearHash->printTable(hashTable);
    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "abc"); // 8

    // should rehash since load factor is bigger

    linearHash->printTable(hashTable);

    assert(linearHash->checkRehash(hashTable) == true);

    cout << "test case passed: rehashing" << endl;
    delete linearHash;
}

void testFindItem()
{
    vector<string> hashTable(11);
    
    LinearProbing* linearHash = new LinearProbing(hashTable);

    linearHash->insertItem(hashTable, "ABC");

    assert(linearHash->findItem(hashTable, "ABC") == true);

    cout << "test passed: item found in hash table";
}



void testExcessItems()
{
    vector<string> hashTable(7);
    
    LinearProbing* linearHash = new LinearProbing(hashTable);


    linearHash->insertItem(hashTable, "ABC"); // 1
    linearHash->insertItem(hashTable, "ABC");
    linearHash->insertItem(hashTable, "ABC");
    linearHash->insertItem(hashTable, "ABC");
    linearHash->insertItem(hashTable, "ABC");
    linearHash->insertItem(hashTable, "ABC");
    linearHash->insertItem(hashTable, "ABC");
    linearHash->insertItem(hashTable, "ABC"); // 8

    linearHash->printTable(hashTable);

    assert(linearHash->getTableSize() == 17);

    cout << "test passed: excess amount of items";
}


// TEST TO SEE IF DELTED ITEM INDEX IS AVAILABLE
void testDeleted()
{
    vector<string> hashTable(7);
    
    LinearProbing* linearHash = new LinearProbing(hashTable);


    linearHash->insertItem(hashTable, "ABC"); // 1

    linearHash->removeItem(hashTable,"ABC");

    linearHash->insertItem(hashTable,"ACB");

    int index = linearHash->hashFunction("ACB");

    assert(hashTable.at(index) == "ACB");
}






// quad tests


//simple test case to check that a collision is resolved with linear probing
void testQuadInsertOneCollision(){

    //setup the states of the test
    vector<string>hashTable(11);

    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable,"abc");
    quadHash->insertItem(hashTable,"abc");

    //check that "abc" and "bac" were placed in the correct locations
    int index = quadHash->hashFunction("abc");
    quadHash->printTable(hashTable);
    assert(hashTable.at(index) == "abc" && hashTable.at(index + 1) == "bac");

    cout << "test case passed: linear probing insertion one collison" << endl;

    delete quadHash;
}




void visualTestCaseQuad()
{
    vector<string> hashTable(11);

    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    // inserting a collison and seeing if it rehashes properly
    quadHash->insertItem(hashTable, "abc");
    // linearHash->printTable(hashTable);
    quadHash->insertItem(hashTable, "acb");
    // linearHash->printTable(hashTable);

    quadHash->printTable(hashTable);

    delete quadHash;
}



//sample test case that should check the hashtable changes in size from 11 to 23
void testQuadInsertMultipleCollisionRehash(){

    //creates a new vector of size 11
    vector<string> hashTable(11);

    //create a new linearHash object
    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    //print the empty hash table
    //linearHash->printTable(hashTable);

    //each of these strings hash to be the same
    quadHash->insertItem(hashTable, "abcdefg"); // 1
    quadHash->insertItem(hashTable, "bcdefga");
    quadHash->insertItem(hashTable, "cdefgab");
    quadHash->insertItem(hashTable, "defgabc");
    quadHash->insertItem(hashTable, "efgabcd");    
    quadHash->insertItem(hashTable, "fgabcde");
    quadHash->insertItem(hashTable, "gabcdef"); // 7

    //print the new hashTable
    quadHash->printTable(hashTable);

    //since load factor increased beyond threshold, table should have been rehashed
    assert(quadHash->getTableSize() == 23); 

    cout << "test passed: multiple collisions" << endl;
    delete quadHash;
}



// testing to see if an elem can be removed
void testRemovingElemQuad()
{
    vector<string>hashTable(11);

    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    string item = "abc";

    quadHash->insertItem(hashTable, item);
    quadHash->printTable(hashTable);
    quadHash->removeItem(hashTable, item);
    quadHash->printTable(hashTable);
    // testing to see if item was removed by trying to find it
    assert(quadHash->findItem(hashTable, item) == false);

    cout << "test case passed: inserting an item and deleting it" << endl;
    delete quadHash;
}



void testRehashQuad()
{
    vector<string>hashTable(11);

    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    quadHash->insertItem(hashTable, "abc"); // 1
    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "abc");
    quadHash->printTable(hashTable);
    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "abc");
    quadHash->insertItem(hashTable, "abc"); // 8

    // should rehash since load factor is bigger

    quadHash->printTable(hashTable);

    assert(quadHash->checkRehash(hashTable) == true);

    cout << "test case passed: rehashing" << endl;
    delete quadHash;
}




void testFindItemQuad()
{
    vector<string> hashTable(11);
    
    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);

    quadHash->insertItem(hashTable, "ABC");
    quadHash->printTable(hashTable);

    assert(quadHash->findItem(hashTable, "ABC") == true);

    cout << "test passed: item found in hash table";

    delete quadHash;
}



void testExcessItemsQuad()
{
    vector<string> hashTable(7);
    
    LinearProbing* quadHash = new LinearProbing(hashTable);


    quadHash->insertItem(hashTable, "ABC"); // 1
    quadHash->insertItem(hashTable, "ABC");
    quadHash->insertItem(hashTable, "ABC");
    quadHash->insertItem(hashTable, "ABC");
    quadHash->insertItem(hashTable, "ABC");
    quadHash->insertItem(hashTable, "ABC");
    quadHash->insertItem(hashTable, "ABC");
    quadHash->insertItem(hashTable, "ABC"); // 8

    quadHash->printTable(hashTable);

    assert(quadHash->getTableSize() == 17);

    cout << "test passed: excess amount of items";


    delete quadHash;
}


// TEST TO SEE IF DELTED ITEM INDEX IS AVAILABLE
void testDeletedQuad()
{
    vector<string> hashTable(7);
    
    QuadraticProbing* quadHash = new QuadraticProbing(hashTable);


    quadHash->insertItem(hashTable, "ABC"); // 1
    quadHash->printTable(hashTable);

    quadHash->removeItem(hashTable,"ABC");
    quadHash->printTable(hashTable);

    quadHash->insertItem(hashTable,"ACB");
    quadHash->printTable(hashTable);

    int index = quadHash->hashFunction("ACB");

    assert(hashTable.at(index) == "ACB");

    delete quadHash;
}



