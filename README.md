# Set-Type

For this project, we will be implementing a set using an array of link 
lists and a hash function to figure out what "bucket" and element should go 
into.  The set is a template and can store any type. Project created under the guidance of Dr. Varick Erickson. Copyright (c) 2021 Varick Erickson.

# SetType Descriptions

## `Basic_SetType_Test`

The `Basic_SetType_Test` can be used for development.  This program does several very basic tests of SetType.  It is 
useful starting point for testing your SetType.

## `SetType() Default Constructor`

The default constructor should use the default number of buckets and set the 
number of elements to 0.  This should also set the `maxLoad` to the default 
load factor.

## `SetType(SetType& other) Copy Constructor`

This function should call `copySet` to do a deep copy into `this`.

## `SetType(numBucks)`

This constructor should uses the `numBucks` to create the buckets and set the
number of elements to 0. This should also set the `maxLoad` to the default
load factor.

## `Size()`

This function returns the total number of elements in the set.

## `Add(T elem)`

This function should add `elem` to the set.  If `elem` already exists in the 
list, then the set should not change.  This function should use the 
`GetHashIndex` to figure out what bucket `elem` should be placed and the `elem`
should be pushed to the front of the forward_list.

## `Remove(T elem)`

This function should remove `elem` to the set.  If `elem` does not exist in the
list, then the set should not change.  This function should use the
`GetHashIndex` to figure out what bucket `elem` exists in and remove 
`elem` from the forward list.

## `Contains(T elem)`

This function should return true if `elem` is in the set.  You should find 
the bucket that `elem` is in and the search for that item within the bucket.

## `void MakeEmpty()`

The `MakeEmpty` function should remove all elements from the set.  This is 
done by clearing each bucket.

## `SetType operator+(T elem)`

This is an alternative way to add an element to a set.  However, this 
overload does ***not*** change the original calling set.

## `SetType operator-(T elem)`

This is an alternative way to remove an element to a set.  However, this
overload does ***not*** change the original calling set.

## `SetType operator+(SetType& otherSet)`

This function returns the union of `this` and `otherSet`. This overload
does ***not*** change the original instance or `otherSet`.

## `SetType operator-(SetType& otherSet)`

This function returns the difference of `this` and `otherSet`. This overload 
does ***not*** change the original instance or `otherSet`.

## `SetType operator*(SetType& otherSet)`

This function returns the intersection of `this` and `otherSet`. This overload
does ***not*** change the original instance or `otherSet`.

## `SetType& operator=(SetType const& otherSet)`

This function should call `copySet` to do a deep copy into `this`.

## `void copySet(SetType const& otherSet)`

This function does a deep copy into `this`.  The function should copy the 
contents of each bucket from `otherSet` into the buckets of `this`.  The 
function should also copy over the appropriate private variables from 
`otherSet` to `this`.  Since the otherSet is passed in as a const, it will 
not be able to use `otherSet.ResetIterator()` or `otherSet.GetNextItem()`.  
It will need to loop through each bucket and all the items within each bucket.

## `double LoadFactor()`

This function returns the load factor of the set.  This is total number of 
elements in the set divided by the total number of buckets.

## `void Rehash(int newNumBuckets)`

This function rehashes the elements stored in the set using the `newNumBuckets`.

A simple strategy is to start with an empty set with the 
appropriate number of buckets (let's call this `rehashSet`).  After that, we 
can use the iterator to add all the elements from `this` to the `rehashSet`. 
Once all the elements are copied into the `rehashSet`, we can use the 
assignment operator with `*this` and `rehashSet`.

## Variables used for the SetType iterator

Two variables are used to keep track of the current element that should be 
returned next; `currBucket` and `bucketIter`.  The `currBucket` is the index 
of the bucket that is currently being iterated over.  The `bucketIter` is 
the iterator of the bucket currently being iterated over.  A third variable 
called `iterCount` is used to determine how many iterations have occurred.  
This variable is used to throw an error if we try to get the next item when 
there is no more items to iterate over.

## `void ResetIterator()`

This function resets the iterator for the set.  It behaves similarly to the 
other data structures covered previously.  This function should set 
`bucketIter` to the beginning of the first bucket.  It should also set 
`currBucket` and `iterCount` appropriately.

## `T GetNextItem()`

This function should return the element that the `bucketIter` currently points 
to and then increment the `bucketIter`.  If there are no more elements in 
the `bucketIter` (it is at the end), then the `currBucket` should be 
incremented and `bucketIter` should be set to the beginning of the next bucket.  
If `GetNextItem()` is called and there are no more elements to iterate over, 
then it should throw a `IteratorOutOfBounds` error.

