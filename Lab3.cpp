


#include <iostream>
using namespace std;

ifstream infile1("data31.txt"), infile2("data32.txt");
bool success;
Employee* oneEmployee;
List<Employee> company1, company2, company3, company4;


//Default constructor
List::List() : size(0), head(NULL)
{
    
}// end of default

/** Copy Constructor */
List::List(const List& aList) : size(aList.size)      // List yourList(myList);
{
    if (aList.head == NULL) {
        head = NULL; // original list is empty
    }
    else
    {   //copy first node
        head = new ListNode;
        head->item = aList.head->item;
        
        //copy the rest of the list
        ListNode *newPtr = head; //new list pointer
        //newPtr points to last node in new list
        //origPtr points to nodes in original list
        for (ListNode *origPtr = aList.head->next; origPtr != NULL;
             origPtr = origPtr->next)
        {
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }//end for
        newPtr->item = NULL;
    }//end if
}// end copy constructor



//Destructor
List::~List()
{
    while(!isEmpty())
    {
        remove(1);
    }//end while
}// end destructor



//----------------------------------------------------------------------------
// buildList
// continually insert new items into the list
void List::buildList(ifstream& infile) {
    NodeData* ptr;
    bool successfulRead;                            // read good data
    bool success;                                   // successfully insert
    for (;;) {
        ptr = new NodeData;
        successfulRead = ptr->setData(infile);       // fill the NodeData object
        if (infile.eof()) {
            delete ptr;
            break;
        }
        
        // insert good data into the list, otherwise ignore it
        if (successfulRead) {
            success = insert(ptr);
        }
        else {
            delete ptr;
        }
        if (!success) break;
    }//end if
}//end buildList


bool List::insert(int index, const ListItemType& newItem)
{
    int newLength = getLength() + 1;
    
    if ((index < 1) || (index > newLength))
    { cout << "ListIndexOutOfRangeException:retrieve index out of range"
        << endl;}
    else
    {   //create a new node and place newItem in it.
        try { //try to allocate memory
            ListNode *newPtr = new ListNode;
            size = newLength;
            newPtr->item = newItem;
            
            //attach a new node to the list.
            if (index == 1) {
                //insert new node at the beginning of the list
                newPtr->next = head;
                head = newPtr;
            }
            else
            { ListNode *prev = find(index -1);
                //inserts a new node after node to which prev points
                newPtr->next = prev->next;
                prev->next = newPtr;
            }
        } catch (bad_alloc e) {
            { cout << "ListIndexOutOfRangeException:retrieve index out of range"
                << endl;}
        }//end try catch
    } //end if
} //end insert


//Edit
bool remove()
{
    
    Employee target("duck", "donald");         // assume constructor exists
    success = company1.remove(target, oneEmployee);
    if (success) {
        cout << "removed: " << *oneEmployee << endl;
        delete oneEmployee;             // could be inserted into another list
    }//end if
}//end remove

    
//Edit
bool retrieve()
 {
     Employee target("duck", "donald");
     success = company1.retrieve(target, oneEmployee);
     if (success) { cout << "Found in list:  " << *oneEmployee << endl;
 }//end retrieve
        
        
        
//Edit
void merge()
 {
     // after this merge, company1 and company2 are empty,
     // company3 contains all employees of company1 and company2
     company3.merge(company1, company2);
     // after merge, company3 is empty,
     // company4 contains all employees of company3 and company4
     company4.merge(company4, company3);
 }//end merge
        
        
        
//Edit
void intersect()
 {
    // after intersect, company1 and company2 are unchanged,
    // company3 holds intersection of company1 and 2
    company3.intersect(company1, company2);
    // after intersect, company3 is unchanged,
    // company4 holds the intersection of company3 and 4
    company4.intersect(company3, company4);
 }//end intersect
        
        
//Edit
//----------------------------------------------------------------------------
//              Overloaded Input & Output Operators
//----------------------------------------------------------------------------
// operator<<
// overloaded <<: prints the set
// @param output output stream for data
// @param s IntSet set that is sent to stream
ostream& operator<<(ostream &output, const IntSet& s) {
   output << OPEN_BRACE;
   for (int counter = 0; counter < s.size; counter++){
    if (s.set[counter] == true){
    output << counter << SPACE;
        }//end if
      }// end for
    output << CLOSE_BRACE;
   return output;
} //end operator<<
        
        
        
        
        
//I think this is done
bool isEmpty()
{
    return size == 0;
}//end isEmpty
        
        
        
//Edit
void makeEmpty(Link<T> set)
    {
        while (!isEmpty()) {
            remove(1);
        }//end while
    }//end makeEmpty
        
//----------------------------------------------------------------------------
// operator=
// overloaded =: assigning an IntSet object to another
Link Link::operator=(const IntSet & assign){
  this->size = assign.size;
  for(int index = 0; index <= assign.size; index++){
  this->set[index] = assign.set[index];
      }//end for
        return *this;
    } // end operator=
        
        
        
//----------------------------------------------------------------------------
//              Boolean Comparison Operators
//----------------------------------------------------------------------------
// operator==
// overloaded ==: addition of 2 IntSets
bool Link::operator==(const IntSet & equal) const{
  if (size != equal.size){
          return false;
  }else{
  for(int counter=0; counter <=size; counter++){
    if( equal.set[counter]!=set[counter]){
         return false;
           }
       }
     }
    return true;
  } //end operator==
        
//----------------------------------------------------------------------------
// operator!=
// overloaded !=: addition of 2 IntSets
bool Link::operator!=(const IntSet & notEqual) const{
 if (size == notEqual.size){
   return false;
     }else{
    for(int counter=0; counter <=size; counter++){
    if( notEqual.set[counter]!=set[counter]){
        return true;
     }
    }
    }
            return false;
} //end operator!=
