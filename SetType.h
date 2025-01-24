#ifndef SET_TYPE
#define SET_TYPE

#include<string>
#include<iostream>
#include<forward_list>
#include<unordered_map>
using namespace std;

class IteratorOutOfBounds {
public:
    string Msg() {
        return "Iterator is out of bounds.  Nothing left to iterate over.";
    }
};

const int DEFAULT_BUCKETS = 10;
const double DEFAULT_LOAD_FACTOR = 1.0;

template<class T>
class SetType
{
public:
    // Constructors

    /*
    * Function:
    * This is the default constructor
    *
    * Precondition:
    * None
    *
    * Postcondition:
    * None
    */
    SetType();

    /*
    * Function:
    * This constructor creates a SetType class object
    *
    * Precondition:
    * numBucks must be passed in
    *
    * Postcondition:
    * Will create an empty set with the number of buckets passed in.
    */
    explicit SetType(int numBucks);

    /*
    * Function:
    * This is the copy constructor that will copy the set passed in
    *
    * Precondition:
    * A set type object must be passed in
    *
    * Postcondition:
    * Set type object will be successfully copied
    */
    SetType(SetType& other);

    /*
    * Function:
    * Deconstructor
    *
    * Precondition:
    * None
    *
    * Postcondition:
    * None
    */
    ~SetType();

    /*
    * Function:
    * This function adds a type T element into the set
    *
    * Precondition:
    * Must pass in a type T element that doesn't already exist in the set
    *
    * Postcondition:
    * Will add the element into the Set if run is successful
    */
    void Add(T elem);

    /*
    * Function:
    * This function removes a type T element from the Set
    *
    * Precondition:
    * Must pass in a type T element
    *
    * Postcondition:
    * Will remove the element from the Set if run is successful
    */
    void Remove(T elem);

    /*
    * Function:
    * This function finds the element in the set
    *
    * Precondition:
    * Must pass in a type T element
    *
    * Postcondition:
    * Will return true if element is in the set or false if element is not in the set
    */
    bool Contains(T elem);

    /*
    * Function:
    * This function removes all the items from the set
    *
    * Precondition:
    * None
    *
    * Postcondition:
    * Will clear the entire set
    */
    void MakeEmpty();
    int Size() const {
        return numElems;
    }

    /*
    * Function:
    * This function will determine the load factor
    *
    * Precondition:
    * None
    *
    * Postcondition:
    * Will return the loadfactor
    */
    double LoadFactor() const;

    void SetMaxLoad(double max);

    /*
    * Function:
    * This function will increase the amount of buckets in the set
    *
    * Precondition:
    * Must pass in a positive integer
    *
    * Postcondition:
    * Will increase the amount of buckets and rehash the set
    */
    void Rehash(int newNumBuckets);

    /*
    * Function:
    * The function overloads the + operator to add the intended elements
    *
    * Precondition:
    * Type T variable, elem, must be passed in
    *
    * Postcondition:
    * Will add the element to the set
    */
    SetType operator+(T elem);				      // Add

    /*
    * Function:
    * The function overloads the - operator to remove the intended elements
    *
    * Precondition:
    * Type T variable, elem, must be passed in
    *
    * Postcondition:
    * Will remove the element from the set
    */
    SetType operator-(T elem);				      // Remove

    /*
    * Function:
    * The function overloads the + to get the union of the two sets
    *
    * Precondition:
    * Must pass in a set
    *
    * Postcondition:
    * Returns the result with the union of the two sets stored in it
    */
    SetType operator+(SetType& otherSet);         // Union

    /*
    * Function:
    * The function overloads the - to return the difference between the two sets
    *
    * Precondition:
    * Must pass in a set
    *
    * Postcondition:
    * Returns the difference of the two sets
    */
    SetType operator-(SetType& otherSet);         // Difference

    /*
    * Function:
    * The function overloads * to return the intersection of the two sets
    *
    * Precondition:
    * Must pass in a set
    *
    * Postcondition:
    * Returns the result with the intersection between the two sets
    */
    SetType operator*(SetType& otherSet);         // Intersection

    /*
    * Function:
    * This function overloads = operator to copy a set
    *
    * Precondition:
    * Must pass in a set
    *
    * Postcondition:
    * Copies the passed set if the function runs properly
    */
    SetType& operator=(SetType const& otherSet);  // Assignment (does deep copy)

    /*
    * Function:
    * This function will reset the iterator to all the default starting values
    *
    * Precondition:
    * None
    *
    * Postcondition:
    * Will set all iterators variables at their default starting values
    */
    void ResetIterator();	// Reset iterator

    /*
    * Function:
    * This function returns the next item
    *
    * Precondition:
    * None
    *
    * Postcondition:
    * Will return the current item the iterator points to
    */
    T GetNextItem();

private:
    forward_list<T>* buckets;	// An array of forward_list's
                                // (each index is a forward_list)

    int numBuckets;     // total number of buckets

    int GetHashIndex(const T& key);    // Gets the hash index given the elem

    int numElems;       // total number of elements

    double maxLoad;     // load factor of the Set

    // This function is used by the
    // copy constructor and the assignment operator.
    /*
    * Function:
    * This function will copy the passed in set
    *
    * Precondition:
    * Must pass in a set
    *
    * Postcondition:
    * Will copy the set if run is successful
    */
    void copySet(const SetType& otherSet);

    // Iterator variables
    int currBucket;											// What bucket is the iterator on?
    int iterCount;                                          // What element are we on?
    mutable typename forward_list<T>::iterator bucketIter;	// The iterator of the current bucket

    // Any other private functions and variables you want/need
};

#include "SetType.cpp"

#endif