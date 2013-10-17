
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
//---------------------operator <<---------------------------------------
//@brief output operator for class List, print data,
//       responsibility for output is left to object
//       stored in the list
friend ostream& operator<<(ostream& output, const List<T>& listToPrint){
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
        };//end struct
            
<<<<<<< HEAD
<<<<<<< HEAD
            Node* head;         // pointer to first node in list
            int size;
=======
        Node* head;         // pointer to first node in list
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======
        Node* head;         // pointer to first node in list
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
};//end List






//-------------------------Constructor-----------------------------------
// @brief default constructor
template <typename T>
List<T>::List(){
    head = NULL;
    size = 0;
}//end List

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------destructor-----------------------------------------
=======
//--------------------------Destructor-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======
//--------------------------Destructor-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//destructor, not done
template <typename T>
List<T>::~List(){
    
    //Enter data here
    
}//end ~List

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------------copy-constructor-----------------------------
template <typename T>
List<T>::List(const List& aList) : size(aList.size) {
    
    if (aList.head == NULL){
        head = NULL;    //original list is empty
    }
    else
    {   //copying of first node
        head = new Node;
        head->data = aList.head->data;
        
        //continue copying the rest of the data
        Node *newPtr = head;    //new list pointer
        //newPtr points to last node in new list
        //origPtr points to nodes in original list
        for (Node *origPtr = aList.head->next;
             origPtr != NULL;
             origPtr = origPtr->next) {
            newPtr->next = new Node;
            newPtr->data = origPtr->data;
        }//end for
        newPtr->next = NULL;
    }//end if
}// end copy constructor


//---------------------buildList------------------------------------------
=======
=======
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//----------------------Copy Constructor---------------------------------
//copy constructor, not done
template <typename T>
List<T>::List(const List& copyData){
    List(copyData);
}//end cpyCnstr

<<<<<<< HEAD


//---------------------------buildList-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======


//---------------------------buildList-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//build list from data file
template <typename T>
void List<T>::buildList(ifstream& infile){
    T* ptr;
    bool successfulRead;            //read good data
    bool success;                   // successfully insert
    
    for (;;){
        ptr = new T;
        successfulRead = ptr->setData(infile);      //fill the T object
        if (infile.eof()) {
            delete ptr;
            break;
        }//end if
        
        if (successfulRead){
            success = insert(ptr);      //insert method?
             size++;
        }
        else {
            delete ptr;
        }//end if 2
        if (!success)
            break;
    }//end for
    
}//end buildList


//---------------------insert--------------------------------------------
// @brief insert
// @description insert one Node into list
// @param[in] dataPtr
// @return true if node is inserted correctly
//@Terence
template <typename T>
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

<<<<<<< HEAD
//---------------------remove -------------------------------------------
=======


//----------------------------remove-------------------------------------
<<<<<<< HEAD
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
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

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------retrieve-------------------------------------------
=======

//----------------------------retrieve-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======

//----------------------------retrieve-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//grab one Node from list, not done
bool retrieve(T* ){
    
    //Enter data here
    
}//end retrieve

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------merge----------------------------------------------
=======


//-----------------------------merge-------------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======


//-----------------------------merge-------------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//combines two sorted lists into one list, not done
template <typename T>
void merge(const List& firstList, const List& secondList){
    
    //Enter data here
    
}//end merge

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------intersect------------------------------------------
=======

//----------------------------intersect-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======

//----------------------------intersect-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//finds common elements in both
//lists and creates new list, not done
template <typename T>
void intersect(const List& firstList, const List& secondList){
    
    //Enter data here
    
}//end intersect

//-----------------------isEmpty------------------------------------------
// @brief isEmpty
// @description check list for values ------> this is suspicious
// @return true if linked list is empty
//@Terence
template <typename T>
bool List<T>::isEmpty() const
{
    return head == NULL;
}//end isEmpty

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------makeEmpty------------------------------------------
=======


//-------------------------makeEmpty-------------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======


//-------------------------makeEmpty-------------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//empty out list, deallocate memory, not done
template <typename T>
void makeEmpty(const List& ){}//end makeEmpty

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------operator=------------------------------------------
=======


//-------------------------operator=-------------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======


//-------------------------operator=-------------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//assings one list to another, not done
template <typename T>
List List::operator=(const List& secondList) const{
    
    //Enter data here
    
    }//end operator=
<<<<<<< HEAD
    
//---------------------operator==-----------------------------------------
=======


//-------------------------operator==----------------------------------
<<<<<<< HEAD
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//determine equality, not done
template <typename T>
bool List::operator==(const List& secondList) const{
    
    //Enter data here
    
    }//end operator==

<<<<<<< HEAD
<<<<<<< HEAD
//---------------------operator!=-----------------------------------------
=======

//-------------------------operator!=-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
=======

//-------------------------operator!=-----------------------------------
>>>>>>> 0def183bc6ddad6da47fb78593e6aecfe962a8e8
//determine inequality, not done
template <typename T>
bool List::operator!=(const List& secondList) const{
    
    //Enter data here
    
    }//end operator!=
    
//---------------------------getLength------------------------------------
//size of the linked list
template <typename T>
int List<T>::getLength()
{
    return size;
}


 #endif