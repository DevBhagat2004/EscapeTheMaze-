//-------------------------------------------------
// Author: Dev Bhagat
// This file contains definition of the grid class and
// its helper functions 
//-------------------------------------------------


#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
    struct CELL {
        CELL* Next;
        T Val;
        size_t NumCols;  // total # of columns (0..NumCols-1)
        CELL(CELL* _Next = nullptr, T _Val = T(), size_t _NumCols = 0) {
            Next = _Next;
            Val = _Val;
            NumCols = _NumCols;
        }
    };
    
    size_t NumRows;  // total # of rows (0..NumRows-1)
    CELL** Rows;     // C array of linked lists
public:
    //
    // default constructor:
    //
    // Called automatically by C++ to construct a 4x4 Grid.  All
    // elements are initialized to the default value of T.
    //
    Grid() {
        // initialize 4 rows
        Rows = new CELL*[4];
        NumRows = 4;
        
        // allocate the first cell of the linked list with default value:
        for (size_t r = 0; r < NumRows; ++r) {
            Rows[r] = new CELL(nullptr, T(), 4);
            CELL* cur = Rows[r];
            
            // create the linked list for this row.
            for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
                cur->Next = new CELL(nullptr, T());
                cur = cur->Next;
            }
        }
        
    }
    // Parametrized Constructor: This will create a 
    // grid object based on users input and 
    //initialize all values inside the grid to T()

    Grid(size_t R, size_t C) {

        Rows = new CELL*[R];
        NumRows = R;
        
        for(size_t i = 0; i<NumRows;++i){
            Rows[i] = new CELL(nullptr,T(),C);
            CELL* cur = Rows[i];
            for(size_t j = 1; j < C; ++j) {
                cur->Next = new CELL(nullptr, T());
                cur = cur->Next;
            }
        }
    }
    
    // Destructor: It will delete the grid
    virtual ~Grid() {

        for(size_t i =0;i<NumRows;++i){
            CELL* temp = Rows[i];
            
            while(temp!=NULL){
                CELL* curr = temp;
                temp = temp->Next;
                delete curr;
            }
        
        }
        delete[] Rows;
    }


    
    // Copy constructor: Make a copy of the grid 
    //object of an existing grid
    Grid(const Grid<T>& other) {
      
        this->Rows = new CELL *[other.NumRows];  
        this->NumRows = other.NumRows;

        for (size_t r = 0; r < other.NumRows; ++r) {
            size_t other_numcols = other.Rows[r]->NumCols;

            CELL* newOther = other.Rows[r];
            this->Rows[r] = new CELL(nullptr, newOther->Val, newOther->NumCols);
            newOther = newOther->Next;
            CELL * ptr  = Rows[r];

            for (size_t c = 1; c < other_numcols; ++c) {
                ptr->Next = new CELL (nullptr,newOther->Val);
                ptr = ptr->Next;
                newOther= newOther->Next;
            }
        }
        
    }
    
    // Copy operator=: Replace values in this existing grid 
    // with values from another grid
    
    Grid& operator=(const Grid& other) {
    if (this == &other) {
            return *this; // handle self-assignment
        }

        for (size_t i = 0; i < NumRows; ++i) {
            CELL* current = Rows[i];
            while (current != nullptr) {
                CELL* next = current->Next;
                delete current;
                current = next;
            }
        }
        delete[] Rows;

        NumRows = other.NumRows;
        Rows = new CELL*[NumRows];

        for (size_t r = 0; r < NumRows; ++r) {
            CELL* src = other.Rows[r];
            Rows[r] = new CELL(nullptr, src->Val, src->NumCols);
            CELL* dst = Rows[r];
            src = src->Next;

            while (src != nullptr) {
                dst->Next = new CELL(nullptr, src->Val);
                dst = dst->Next;
                src = src->Next;
            }
        }

        return *this;
    }
    
    // return the nummber of rows in grid
    size_t numrows() const {
        
        return NumRows;  
    }
    
    
    // return the number of columns in a 
    //particular row of the grid 
    size_t numcols(size_t r) const {
        

        return Rows[r]->NumCols;  
        
    }
    
    // returns the total size of the grid
    size_t size() const {
        
       size_t size =0;

        for(size_t i =0;i<NumRows;++i){
            size+= Rows[i]->NumCols;
        }
              
        return size;  
    }
    
    // reference operator: returns a specific location of the grid 
    // base on the users row and column number input
    T& operator()(size_t r, size_t c) {
      
        if(r<0||r>=NumRows){
            throw out_of_range("Invalid Rows");
        }
        
        size_t totalCols = Rows[r]->NumCols;

        CELL* tempPtr = Rows[r];
        for(size_t i = 0;i<totalCols;++i){
            if(i == c){
                return tempPtr->Val;
                
            }
            else{
                tempPtr = tempPtr->Next;
            }
        }

        throw out_of_range("C is out of bound");
        
    }
    
    // prints out the grid
    void _output() {
        for(size_t i=0;i<NumRows;++i){
            CELL* temp = Rows[i];
            cout<<"| ";
            while(temp!= NULL){
                CELL* curr = temp;
                T value = curr->Val;
                cout<< value<< " |";
                temp = temp->Next;
            }
            cout<<endl;
        }
    }
    
};
