
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
        bool remove(T,T*);                   //remove one Node from list, not done
        bool retrieve(T,T*);                 //grab one Node from list, not done
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
            

            Node* head;         // pointer to first node in list
            int size;


};//end List






//-------------------------Constructor-----------------------------------
// @brief default constructor
template <typename T>
List<T>::List(){
    head = NULL;
    size = 0;
}//end List


//--------------------------Destructor-----------------------------------
//destructor, not done
template <typename T>
List<T>::~List(){
    
    //Enter data here
    
}//end ~List

//---------------------------copy-constructor-----------------------------
template <typename T>
List<T>::List(const List& aList) : size(aList.size) {
    Node* current = aList.head;     // Looking at the head of the linked list that needs to be copied
    Node* ourPtr = head;            // ourPtr is pointing to the head of the new linked list where data is going to be copied
    
    while(current != NULL){
        ourPtr = new Node();        // creates a new node in the new linked list
        ourPtr->data = new T(*current->data);   // copied the first data from aList linked list
        ourPtr->next = NULL;
        ourPtr = ourPtr->next;      // ourPtr moves to the next node of the new linked list
        // (to copy the next data if there is any)
        current = current->next;    // pointer on aList linked list moves to the second data
    }
   
}// end copy constructor


//---------------------------buildList-----------------------------------
//build list from data file
template <typename T>
void List<T>::buildList(ifstream& infile){
    T* toInsert;
    while (! infile.eof()){
        toInsert->setData(infile);
        insert(infile);
    }//end while
    
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
    size++;
    return true;
}//end insert
//----------------------------remove-------------------------------------
//remove one Node from list
template<typename T>
bool List<T>::remove(T data, T* dataPtr){
    // Check to see if list is empty
    if (head==NULL)
        return false;
    // Check to see if only one element in the list
    else if(size == ONE){
        // data == *head->data
        if(data == *head->data){
            dataPtr = head;
            delete head;
            head = NULL;
            size--;
            return true;
            // return false if data != *head->data
        }else
            return false;
        
        //Check if there are only 2 elements in the list
    }else if(size==TWO){
        Node* current = head->next;
        Node* previous = head;
        if(data==current->data){
            dataPtr = current->data;
            delete current->data;
            previous->next = NULL;
            current = NULL;
            size--;
            return true;
        } // end if data == current-> data
        if(data==previous->data){
            head = current;
            dataPtr = previous->data;
            delete previous;
            previous = NULL;
            size--;
            return true;
        } // end if data == previous->data
        
        // Return false if data != first and second elements in the list
        return false;
        
    }else{
        Node* current = head->next;
        Node* previous = head;
        // remove data if it's equal to the previous
        if (previous->data==data){
            head = current;
            dataPtr = previous->data;
            delete previous;
            previous = NULL;
            size--;
            return true;
        }
        // the data != previous, check current element
        while(current != NULL){
            // data == current->data
            if(current->data == data){
                previous->next = previous->next->next;
                dataPtr = current->data; // grab the data to be removed
                delete current;
                current = NULL;
                previous = NULL;
                size--;
                return true;
            }
            // the data != current->data
            else{
                current = current->next;    // current points to the next element
                previous = previous->next;  // previous points to where current was pointing
            }
        }
        // data != any elements in the list
        return false;
    } // end else list has > 2 elements
}//end remove


//----------------------------retrieve-----------------------------------
//grab one Node from list
bool List<T>::retrieve(T data, T* dataPtr){
    // Check to see if list is empty
    if (head==NULL)
        return false;
    // Check to see if only one element in the list
    else if(size == ONE){
        // the data == *head->data
        if(data == *head->data){
            dataPtr = head;
            return true;
            // return false if data != *head->data
        }else
            return false;
        
        //Check if there are only 2 elements in the list
    }else if(size==TWO){
        Node* current = head->next;
        Node* previous = head;
        if(data==current->data){
            dataPtr = current->data;
            return true;
        } // end if data == current-> data
        if(data==previous->data){
            dataPtr = previous->data;
            return true;
        } // end if data == previous->data
        
        // Return false if data != first and second elements in the list
        return false;
        
    }else{
        Node* current = head->next;
        Node* previous = head;
        // remove data if it's equal to the previous
        if (previous->data==data){
            dataPtr = previous->data;
            return true;
        }
        // the data != previous, check current element
        while(current != NULL){
            // data == current->data
            if(current->data == data){
                dataPtr = current->data;
                return true;
            }
            // the data != current->data
            else{
                current = current->next;    // current points to the next element
                previous = previous->next;  // previous points to where current was pointing
            }
        }
        // data != any elements in the list
        return false;
    } // end else list has > 2 elements
}//end retrieve

//-----------------------------merge-------------------------------------
//combines two sorted lists into one list, not done
template <typename T>
void merge(const List& firstList, const List& secondList){
    
    //Enter data here
    
}//end merge

//----------------------------intersect-----------------------------------
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

//-------------------------makeEmpty-------------------------------------
//empty out list, deallocate memory, not done
template <typename T>
void makeEmpty(const List& ){
    Node* current = aList.head->next;
    Node* previous = aList->head;
    
    if(aList.isEmpty())
        return;
    if(previous!=NULL && current==NULL){
        delete previous;
        previous = NULL;
        aList.head = NULL;
    }else{
        while (current != NULL){
            current = current->next;
            previous = previous->next
        }
        while(aList.size != ZERO){
            // not yet done
            // delete all nodes in the list
        }
    }
}//end makeEmpty


//-------------------------operator=-------------------------------------
//assings one list to another, not done
template <typename T>
List List::operator=(const List& secondList) const{
    
    //Enter data here
    
    }//end operator=
//-------------------------operator==----------------------------------
//determine equality, not done
template <typename T>
bool List::operator==(const List& secondList) const{
    
    //Enter data here
    
    }//end operator==

//-------------------------operator!=-----------------------------------
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