// PROVIDED BY: Debasree Sen, dsen0000@citymail.cuny.edu
//ID: 24242663
//The work in this assignment is my own. Any outside sources have been properly cited.
#include "sequence3.h"
#include <cstdlib>
using namespace std;

//Invariant: The items in the array are stored in a linked list.
//The head pointer of the list is stored in the member variable headptr
//The total number of items in the list is stored in the member variable count

namespace main_savitch_5{
    sequence::sequence( ){ //O(1) with constant time
        headptr = NULL;
        currentptr = NULL;
        tailptr = NULL;
        prevptr = NULL;
        count = 0;
    }
    sequence::sequence(const sequence& source){ //O(n) with linear time
        //need to update cursor
        //to copy currentptr to where it points, it must point to the same position it pointed to in original set
        //traverse through both lists at once
        list_copy(source.headptr, headptr, tailptr);
        count = source.count;

        node *temp = source.headptr;
        node *i;
        currentptr = NULL; //initialize as NULL in new sequence, will be updated during traversal

        for(i = headptr; i != NULL; i = i->link()){
            if(temp == source.currentptr){
                currentptr = i; //temp has updated currentptr
            }
            temp = temp -> link();
        }
    };
    sequence::~sequence( ){ //O(n) with linear time
        list_clear(headptr);
    };
    void sequence::start(){ //O(1) with constant time
        if(headptr == NULL){
            currentptr = NULL;
        }
        else{
            currentptr = headptr;
            prevptr = NULL;
        }
    }
    void sequence::advance(){ //O(1) with constant time
        if(is_item()){
            if(currentptr == tailptr){
                currentptr = NULL;
            }
            else{
                prevptr = currentptr;
                currentptr = currentptr -> link();
            }
        }
    }
    void sequence::insert(const main_savitch_5::sequence::value_type &entry){ //O(1) with constant time
        if (currentptr == NULL || currentptr == headptr) {
            list_head_insert(headptr, entry);
            currentptr = headptr;
            prevptr = NULL;
        }
        else{
            list_insert(prevptr, entry);
            currentptr = prevptr->link();
        }
        count++;
    }
    void sequence::attach(const main_savitch_5::sequence::value_type &entry){ //O(1) with constant time
        if(headptr == NULL){ //can be empty even if there's a currentptr
            list_head_insert(headptr, entry);
            currentptr = headptr;
            tailptr = headptr; //only one element so far
            prevptr = NULL;
        }
        else if(currentptr == NULL){ //there are elements including headptr
            node *end = new node(entry);
            tailptr->set_link(end);
            tailptr = end;
        }
        else{ //attach after currentptr
            if(currentptr == tailptr){
                prevptr = currentptr;
                node *end = new node(entry);
                tailptr->set_link(end);
                tailptr = end;
                currentptr = tailptr;
            }
            else{ //attach in middle of list
                prevptr = currentptr;
                list_insert(currentptr, entry);
                currentptr = currentptr -> link();
            }
        }
        count ++;
    }
    void sequence::remove_current(){ //O(1) with constant time
        if(currentptr == headptr){
            if(currentptr -> link() != NULL){
                currentptr = currentptr -> link();
                list_head_remove(headptr);
                prevptr = NULL;
                headptr = currentptr;
            }
            else{
                list_head_remove(headptr);
                prevptr = NULL;
                currentptr = NULL;
            }

        }
        else if(currentptr == tailptr){
            currentptr = NULL;
            prevptr ->set_link(NULL);
            delete tailptr;
            tailptr = prevptr;
        }
        else{
            list_remove(prevptr);
            currentptr = prevptr -> link();

        }
        count --;
    }
    void sequence::operator =(const sequence& source){ //O(n) with linear time
        if(this == &source){ //self-assignment
            return;
        }

        list_clear(headptr); //clear current sequence
        list_copy(source.headptr, headptr, tailptr); //copy elements from source sequence
        count = source.count;

        currentptr = source.headptr; //update currentptr
        while (currentptr != NULL && currentptr != source.currentptr) {
            currentptr = currentptr->link();
        }
        /*
         *       node *temp = source.headptr;
        node *i;
        currentptr = NULL; //initialize as NULL in new sequence, will be updated during traversal

        for(i = headptr; i != NULL; i = i->link()){
            if(temp == source.currentptr){
                currentptr = i; //temp has updated currentptr
            }
            temp = temp -> link();
        }
         */
        //should be this, same as copy constructor but makes more errors
    }
}