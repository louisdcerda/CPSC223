#ifndef HASH_H
#define HASH_H

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Hash{

    public:

        //
        int calcNewTableSize(int prevSize)
        {
            int size = prevSize*2;
            while (isPrime(size) == false)
                size++;
            return size;
        }

        int getTableSize(){
            return tableSize;
        }

        double getLoadFactor(){
            return loadFactor;
        }

        string getType(){
            return type;
        }

        void setTableSize(int size){
            this->tableSize = size;
        }

        void setLoadFactor(double loadFactor){
            this->loadFactor = loadFactor;
        }

        void setType(string type){
            this->type = type;
        }

        int getItemCount(){
            return this->itemCount;
        }

        void setItemCount(int count){
            this->itemCount = count;
        }

        //helper function that checks if a number is prime
        bool isPrime(int number)
        {
            for (int i = 2; i <= number/2; ++i)
            {
                if (number % i == 0)
                    return false;
            }
            return true;
        }

        void setCollisions(int num)
        {
            this->collisions = num;
        }

        int getCollisions()
        {
            return this->collisions;
        }



        virtual ~Hash(){

        }

        virtual int hashFunction(string) = 0;
        virtual void insertItem(vector<string> & vec, string str) = 0;
        virtual void removeItem(vector<string> & vec, string str) = 0;
        virtual bool findItem(vector<string> & vec, string str) = 0;
        virtual void rehash(vector<string> & vec) = 0;
        virtual void printTable(vector<string> & vec) = 0;
        virtual bool checkRehash(vector<string> & vec) = 0;

    private:

        string type;
        int tableSize;
        int itemCount;
        double loadFactor;
        int collisions;

};

#endif