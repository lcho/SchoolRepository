/** ---------------------------------------------------------------------------
 Name:              Terence Schumacher
 Project:           lab1.cpp
 Description:       This program reads from text file a stundent's first name,
                    last name, and grade, and then stores them into a Student 
                    Structure.
                    After a student is stored they are put into an array of
                    student structures and sorted by last name and then first 
                    name.
                    The grades are put into a histogram and then the histogram is
                    displayed.
 Environment:       MacOSX 10.8; Xcode 4.6.3
 Pre-Conditions:    Input File that the cpp can find
 Post-Conditions:   Typescript file is present as well as the program can print out

*/
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;            // maximum number of records in total
int const MAXLENGTH = 31;           // maximum string length
int const MAXGRADE = 100;           // highest possible grade
int const LOWGRADE = 0;             // lowest possible grade
int const GROUP = 10;               // group amount
int const HISTOGRAMSIZE = (MAXGRADE-LOWGRADE)/GROUP + 1;    // grouped by GROUP

struct StudentType  {               // information of one student
    int grade;                       // the grade of the student
    char last[MAXLENGTH];            // last name (MAXLENGTH-1 at most)
    char first[MAXLENGTH];           // first name (MAXLENGTH-1 at most)
};

// prototypes go here
void print(char sayIt[MAXSIZE]);
void print(char sayIt[MAXSIZE], string addToTheEnd);
int  setTheCount(char file[MAXSIZE]);
bool sortInput(char text[MAXSIZE],StudentType students[], int size);
void displayList(StudentType person[], int count);
void inSort(StudentType students[], int count);
void readInFile(StudentType students[], char file[MAXSIZE], int count);
void displayHistogram(string update[], int average);
void appender(string array[],int index);
void  setHistogram(StudentType students[], string update[], int size);
int  findAverage(StudentType students[], int size);
void line();


//------------------------------- main ----------------------------------------
int main()  {
    StudentType students[MAXSIZE];  //list of MAXSIZE number of students
    int size = 0;                   //total number of students
    string histogram[HISTOGRAMSIZE];  // grades grouped by GROUP
    int average = 0;                 // average exam score, truncated
    
    // creates file object and opens the data file
    ifstream infile("data1.txt");
    if (!infile)  {
        cout << "File could not be opened." << endl;
        return 1;
    }
    //sets the size
    size = setTheCount("data1.txt");
    line();
    
    // read and sort input by last then first name
    bool successfulRead =  sortInput("data1.txt", students, size);
    
    // display list, histogram, and class average
    if (successfulRead)  {
        displayList(students, size);
        line();
        setHistogram(students, histogram, size);
        line();
        displayHistogram(histogram, average);
        average = findAverage(students, size);
        cout << "Average grade: " << average << endl;
        line();
    }
    return 0;
}

// ----------------------------------------------------------------------------
// functions with meaningful doxygen comments and assumptions go here



/**print(char)
 *      Prints output to the console
    @param sayIt-String entered to display on the console 
                (used to test output)
 */
void print(char sayIt[MAXSIZE])
{
    cout << sayIt << endl;
}

/** print(char, string)
        Prints output to the histogram
    @param sayIt--What will be printed
    @param addToTheEnd--appended string of stars
 */

void print(char sayIt[MAXSIZE], string addToTheEnd)
{
    cout << sayIt << addToTheEnd << endl;
}

/** setTheCount
        Finds the Size of the StudentGrade Array
    @param file--String used to count number of name elements in
                 the file being read
 */
int setTheCount(char file[MAXSIZE])
{
    int count = 0;
    ifstream inFile;
    inFile.open(file);
    if(inFile.is_open()){
        char output[MAXSIZE];
        while (!inFile.eof()) {
            for (int i = 0; i < 3; i++) {
                inFile >> output;
            }
            count++;
        }
    }
    inFile.close();
    return count;
}

/** sortInput
        Sorts Array Struct according
    @param text--File path for the infile stream
    @param students--passing in the student structure array that 
                     should be sorted
    @param size--the size of the structure array
 */
bool sortInput(char text[MAXSIZE], StudentType students[], int size){
    bool sorted = false;
    ifstream  file(text);
        
    while (!sorted)     //assembles the students array
    {
        if (file.is_open())
        {
            while (!file.eof())
            {
                //output file data to StudentType array
                for (int i = 0; i < size; i++)
                {
                    file >> students[i].last;
                    file >> students[i].first;
                    file >> students[i].grade;
                }
            }
        }
        file.close(); //closes file for good data management
        //sorts the array by last name then first name
        inSort(students, size);     
        sorted = true; //done 
    }
    return sorted;
}

/**displayList
        printing out the StudentGrade array
    @param person--Struct Array of students to display
    @param count--number of elements in the array
 */
void displayList(StudentType person[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << person[i].grade << " " << person[i].last
        << " "<< person[i].first << endl;
    }
    
}

/** appender 
        Cleans up Code
    @param array--String being appended with stars (*) to represent 
                  a score within this grade range
    @param index--Index of the Array
 */
void appender(string array[],int index)
{
    array[index].append("*");
}

/** setHistogram
        Udateds the Histogram displaying proper score ranges and
        prints them
    @param students--Array of structs used to pull grades from
    @param update--the histogram array
    @param size--size of the struct array
 */
void  setHistogram(StudentType students[], string update[], int size)
{
    for (int i = 0; i < size; i++) {
        int temp = students[i].grade;
        if (temp > 100 || temp < 0 ) {
            temp = 0;}
        if (temp == 100) {
            appender(update, 10);
        }
        else if (temp > 90){
            appender(update, 9);
        }
        else if (temp > 80){
            appender(update, 8);
        }
        else if (temp > 70 ){
            appender(update, 7);
        }
        else if (temp > 60){
            appender(update, 6);
        }
        else if(temp > 50){
            appender(update, 5);
        }
        else if (temp > 40){
            appender(update, 4);
        }
        else if(temp > 30){
            appender(update, 3);
        }
        else if (temp > 20){
            appender(update, 2);
        }
        else if(temp > 10 ){
            appender(update, 1);
        }
        else if (temp > 0){
            appender(update, 0);
        }
        else
        {    temp = 0; }
    }
}

/** findAverage  
        Simple calculation to reduce coupling
    @param students-- Array of structs containing grades
    @param size--size of the Array
*/
int findAverage(StudentType students[], int size)
{
    int average = 0;
    for (int i = 0; i < size; i++) {
        average += students[i].grade;
    }
    average /= size;
    
    return average;
}

/** displayHistogram
        Print out The histogram with stars updated for values
    @param update--histogram array of stars(*)
    @param average--The average of all grades
 */
void displayHistogram(string update[], int average)
{
    print("Histogram of grades:");
    print("0--> 9:", update[0]);
    print("10--> 19:", update[1]);
    print("20--> 29:", update[2]);
    print("30--> 39:", update[3]);
    print("40--> 49:", update[4]);
    print("50--> 59:", update[5]);
    print("60--> 69:", update[6]);
    print("70--> 79:", update[7]);
    print("80--> 89:", update[8]);
    print("90--> 99:", update[9]);
    print("100--> 100:", update[10]);
}

/** inSort
        Insertion Sorts the Student array
    @param students--The array to be sorted
    @param count--the size of the array
 */
void inSort(StudentType students[], int count)
{
    for (int x=1; x< count; x++)
    {
        for (int j=x; j>0; j--)
        {
            if ( (strcmp(students[j].last, students[j-1].last)) < 0)
            {
                swap(students[j], students[j-1]);
            }
            
            if ((strcmp(students[j].last, students[j-1].last) == 0) &&
                (strcmp(students[j].first, students[j-1].first) < 0))
            {
                swap(students[j], students[j-1]);
            }
        }
    }
}


/** line
        Creates a New line of Separation
*/
void line()
{
    cout << endl;
}