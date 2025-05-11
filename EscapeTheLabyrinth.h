//Author: Dev Bhagat
// This file contains the path to solve both maze, function to verify
// that the path is valid, a function to through the maze
#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

// NetID to generate a unique maze
const string kYourNetID = "dbhag"; // this is where your string goes
// path to solve the maze
const string kPathOutOfRegularMaze = "WWWSSNNESEESWWESWW";// this is the path that I found using gdb for the regular maze
const string kPathOutOfTwistyMaze = "SWEEENSNSNEW"; // this is the path that I found using gdb for the twisty maze
// function to move through the maze
bool isPathToFreedom(MazeCell *start, const string& moves) {
    // if the given path is invalid return false
    for(std::string::size_type i = 0; i < moves.length(); ++i){
        if(moves[i]!='N'&&moves[i]!='S'&&moves[i]!='E'&&moves[i]!='W'){
        return false;
        }
    }
    (void) start;
    (void) moves;
    bool bookFound = false;
    bool wandFound = false;
    bool potionFound = false;
    // if an item is found at the start of 
    // the maze change that item's bool value to true
    if (start->whatsHere == "Spellbook") {
        bookFound = true;
    }
    if (start->whatsHere == "Wand") {
        wandFound = true;
    }
    if (start->whatsHere == "Potion") {
        potionFound = true;
    }
    // exploring the maze with one move at a time, 
    // if the move lead to nullptr return false
    // if an item is found changes that item's bool value to true 
    for(std::string::size_type i = 0; i < moves.length(); ++i){ 
        if(moves[i] =='N'){
            if(start->north == nullptr){
            cout<<"The path leads you to darkness"<<endl;
            return false;
            }

            else{
               start= start->north;
            }
        }

        if(moves[i] =='S'){
            if(start->south == nullptr){
            cout<<"The path leads you to darkness"<<endl;
            return false;
            }

            else{
                start=start->south;
            }
        }


        if(moves[i] =='W'){
            if(start->west == nullptr){
            cout<<"The path leads you to darkness"<<endl;
            return false;
            }

            else{
                start = start->west;
            }
        }

        if(moves[i] =='E'){
            if(start->east == nullptr){
            cout<<"The path leads you to darkness"<<endl;
            return false;
            }

            else{
                start = start->east;
            }
        }

        if(start->whatsHere=="Potion"){
        potionFound= true;
        }

        if(start->whatsHere=="Spellbook"){
        bookFound= true;
        }

        if(start->whatsHere=="Wand"){
        wandFound= true;
        }

    }
    // if all items are found return true
    if(bookFound&&wandFound&&potionFound){
        return true;
    }
    // if all items are not found return false
    return false;
    
}
