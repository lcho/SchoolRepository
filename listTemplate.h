
/** 
    @file listTemplate.h
    @brief Full ordered List class turned into a template
           of objects
    @author Lance Cho
    @author Terence Schumacher
    @version 1.1
    
*/




#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
using namespace std;


const string PTR_INSERT_FAILURE = "Failed: Error inserting pointer";
const string PTR_INSERT_SUCCESS = "Success: Insertion complete";

//This file should contain all class def and function code
template <typename T>
class List
{
    //operator <<
    //@brief output operator for class List, print data,
    //       responsibility for output is left to object
    //       stored in the list
    friend ostream& operator<<(ostream& output, const List<T>& listToPrint)
     {
        Node* current = listToPrint.head;
        while (current != NULL){
            output << *current->data;       
            current = current->next;
        }//end while
     }// end operator<< 
public:
        List();                             //default constructor
        ~List();                            //destructor, not done
        List(const List& );                 //copy constructor, not done
        void buildList(ifstream& );         //build list from data file
        bool insert(T* );                   //insert one Node into list
        bool remove(T* );                   //remove one Node from list, not done
        bool retrieve(T* );                 //grab one Node from list, not done
        void merge(const List& firstList, const List& secondList);  //combines two sorted lists into one list, not done
        void intersect(const List& firstList, const List& secondList); //finds common elements in both
                                                                       //lists and creates new list, not done
        bool isEmpty() const;               //check list for values
        void makeEmpty(const List& );       //empty out list, deallocate memory, not done
        List::operator=(const List& secondList) const;  //assings one list to another, not done
        bool List::operator==(const List& secondList) const;    //determine equality, not done
        bool List::operator!=(const List& secondList) const;    //determine inequality, not done
        
        
private:
            struct Node {       // the node in a linked list
                T* data;        // pointer to actual data, operation in T
                Node* next;
            }//end struct
            
            Node* head;         // pointer to first node in list
}//end List






//-------------------------Constructor-----------------------------------
// @brief default constructor
template <typename T>
List<T>::List(){
    head = NULL;
}//end List

//destructor, not done
~List(){
    
    //Enter data here
    
    }//end ~List

//copy constructor, not done
List(const List& ){
    
    //Enter data here
    
    }//end cpyCnstr

//build list from data file
void buildList(ifstream& ){
    
    //Enter data here
    
    }//end buildList


//---------------------insert--------------------------------------------
// @brief insert
// @description insert one Node into list
// @param[in] dataPtr
// @return true if node is inserted correctly
//@Terence
bool List<T>::insert(T* dataPtr ){
    
    Node* ptr = new Node;
    if (ptr == NULL) {
        cout << PTR_INSERT_FAILURE << endl; //error message
        return false;}  //there is no pointer 

    ptr->data = dataPtr;
    
    // if the list is empty or if the node should be inserted before
    // the first node of the list
    if (isEmpty() || *ptr->data < *head->data){
        ptr->next = head;
        head = ptr;
    }
    
    //then check the rest of the list until we find where it belongs
    else {
        Node* current = head->next;     //to walk the list
        Node* previous = head;          //to walk the list, lags behind
        
        //walk until the end of the list or found position to insert
        while (current != NULL && *current->data < *ptr->data) {
            previous = current;         // walk to the next node
            current = current->next;
        }//end while
        
        //insert new node, link it in
        ptr->next = current;
        previous->next = ptr;
    }//end if
    
    cout << PTR_INSERT_SUCCESS << endl; //succes message
    return true;
}//end insert


//remove one Node from list, not done
// I don't know if this is correct or not
//@Terence
template<typename T>
bool List<T>::remove(T data, T* dataPtr){
    T target(data);
    success = List.remove(targetData, dataPtr);
    if(success){
        cout << "Removed: " << *dataPtr << endl;
        delete dataPtr;         //could be inserted into another list
    }//end if
    }//end remove

//grab one Node from list, not done
bool retrieve(T* ){
    
    //Enter data here
    
}//end retrieve

//combines two sorted lists into one list, not done
void merge(const List& firstList, const List& secondList){
    
    //Enter data here
    
}//end merge

//finds common elements in both
//lists and creates new list, not done
void intersect(const List& firstList, const List& secondList){
    
    //Enter data here
    
}//end intersect

//-----------------------isEmpty-----------------------------------------
// @brief isEmpty
// @description check list for values ------> this is suspicious
// @return true if linked list is empty
//@Terence
template <typename T>
bool List<T>::isEmpty() const{
    return head == NULL;
    }//end isEmpty
    
//empty out list, deallocate memory, not done
void makeEmpty(const List& ){}//end makeEmpty

//assings one list to another, not done
List List::operator=(const List& secondList) const{
    
    //Enter data here
    
    }//end operator=

//determine equality, not done
bool List::operator==(const List& secondList) const{
    
    //Enter data here
    
    }//end operator==

//determine inequality, not done
bool List::operator!=(const List& secondList) const{
    
    //Enter data here
    
    }//end operator!= 


 #endif