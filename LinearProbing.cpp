#include "Hash.h"

using namespace std;

class LinearProbing : public Hash{
    

    public:

        // EVC construct
        //set the type to "Linear Probing"
        //set the initial table size to be length of the vector passed in
        //set initial load factor to 0.0
        //set item count to 0
        LinearProbing(vector<string> & vec)
        {
            setType("Linear Probing");
            setTableSize(vec.size());
            setLoadFactor(0.0);
            setItemCount(0);
        }



        //Given a string, calculate the hashkey based on the sum of the chars
        int hashFunction(string str)
        {
            int key = 0;
            int totalChar = 0;
            
            // ADDING TOTAL ASCII VALUES OF STRING 
            for(int i = 0; i < str.size(); i++)
                totalChar = totalChar + str[i];
            
            key = totalChar % getTableSize();
            return key; 
        }



        //Use linear probing strategy to insert an item into the hashtable
        //If a collision occurs, it should probe until it finds an empty location.
        //  an empty, or free location, is either the empty string "" or an element
        //  marked by lazy deletion.
        //After each insert, check if the table needs to be rehashed. If it does,
        //  perform the rehash
        void insertItem(vector<string> & vec, string str)
        {
            bool flag = true;
            int i = hashFunction(str);
            int count = 0;
            int item = getItemCount();
            setItemCount(item + 1);
            double load = (double)getItemCount()/(double)getTableSize();
            setLoadFactor(load);

            // WHILE FLAG (INSERTION POINT NOT FOUND) TRUE 
            // ADDING I + 1 TO GET LINEAR PROBINB AND % TS
            while (flag)
            {
                if (vec[i] == "" || vec[i] == "DELETED")
                {
                    vec[i] = str;
                    flag = false;
                } else
                {
                    i = (i + 1) % getTableSize();
                    count ++;
                }
            }

            // IF COUNT > 0 THERE IS A COLLISION FOUND SO COUNT GOES UP
            if (count > 0)
                setCollisions(getCollisions() + 1);
            if (checkRehash(vec))
                rehash(vec);        
        }

        //Perform lazy deletion on the hash table
        //To mark an element as deleted, use the string "DELETED"
        //When removing an item it should also decrease the load factor
        void removeItem(vector<string> & vec, string str)
        {
            // IF ITEM IS IN VEC THEN GO THIS
            if (findItem(vec, str))
            {
                int i = 0;
                while (vec[i] != str)
                    i++;
                vec[i] = "DELETED";

                // SETTIING ITEM COUNT  - 1 AND LOAD FACTOR BEING CHANGED
                setItemCount(getItemCount() - 1);
                setLoadFactor(getItemCount()/getTableSize());
            }
        }




        //Search the hashtable for an item
        //Use the hashkey to find the index where the item should belong
        //  and perform linear traversal until you find the item or reach
        //  empty space.
        //Function should return true if the item was found, and false if not found
        bool findItem(vector<string> & vec, string str)
        {
            // grabs the index it should be at
            int item = hashFunction(str);

            // checking to see if youve gone thru the whole table with a counter var
            int count = 0;

            // going throuhg the whole table 
            while(count <= getTableSize())
            {
                if (vec[item] == str) return true;
                else 
                {   
                    // update vars (count and item)
                    // to get the next idnex and compare
                    count++;
                    item = (item + 1) % getTableSize();
                }
            }
            // item was not in hash table 
            return false;
        }




        //Rehash the hash table
        //double the size of the table to the next largest prime
        //move all the elements over from the old table to the new table
        //update all attributes of the hash table (size, load factor, etc.)
        void rehash(vector<string> & vec)
        {
            int prevSize = getTableSize();
            int size = calcNewTableSize(prevSize);
            setTableSize(size);
            // creating a temp table to 
            vector<string> temp (size);


            // INSERTING REHASHED ITEMS INTO TEMP VEC AS TEMP PLACE HOLDER
            for (int i = 0 ; i < vec.size(); i ++)
            {
                if (vec[i] == "" || vec[i] == "DELETED")
                    continue; 
                else
                    insertItem(temp, vec[i]);
            }


            // CLEARING VEC, CHANGING THE SIZE AND INSERTING ITEMS BACK
            vec.clear();
            vec.resize(getTableSize());
            for (int i = 0; i < vec.size(); i++)
                vec[i] = temp[i];
            
            // CHANGING LOAD FACTOR
            double load = (double)getItemCount()/(double)getTableSize();
            setLoadFactor(load);
        }




        //Print the stats of the hash table first, then the contents
        //stats include: table size, load factor, number of collisions, and any others you may think of
        void printTable(vector<string> &vec)
        {
            cout << "The table size is: " << getTableSize() << endl;
            cout << "The load factor is: " << getLoadFactor() << endl;
            cout << "The number of collisions is: " << getCollisions() << endl;
            cout << "The number of items in the table is: " << getItemCount() << endl;
            for (int i = 0; i < getTableSize(); i++ )
                cout << i << " : " << vec[i] << endl;
        }




        //checkRehash will return true if the current table needs to be rehash, false if not
        //This function should also print a message indicating a rehash is occuring as well as
        //  the current load factor
        bool checkRehash(vector<string> & vec)
        {
            // CHEKCING IF LOAD IS TOO BIG
            if (getLoadFactor() >= 0.5)
            {
                cout << "This table is being rehashed. The current load factor is: " << getLoadFactor() << endl;
                setCollisions(0);
                setItemCount(0);
                return true;
            }
            return false;
        }
};