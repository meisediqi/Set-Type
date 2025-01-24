#include <string>
#include <iostream>
#include "SetType.h"

using namespace std;

template<class T>
SetType<T>::SetType() {
    // Create an array of forward_lists and initially set to an empty forward_list
    buckets = new forward_list<T>[DEFAULT_BUCKETS];

    // Your code here
    numBuckets = DEFAULT_BUCKETS;
    numElems = 0;
    maxLoad = DEFAULT_LOAD_FACTOR;

}

template<class T>
SetType<T>::SetType(SetType &otherSet) {
    // This should make use of copySet
    buckets = new forward_list<T>[DEFAULT_BUCKETS];

    // Your code here
    numBuckets = DEFAULT_BUCKETS;
    numElems = 0;
    maxLoad = DEFAULT_LOAD_FACTOR;
    copySet(otherSet);
}

template<class T>
SetType<T>::~SetType() {
    delete [] buckets;
}


template<class T>
SetType<T> SetType<T>::operator+(T elem) {
    SetType<T> result = *this;
    result.Add(elem);
    return result;
}

template<class T>
SetType<T> SetType<T>::operator-(T elem) {
    SetType<T> result =  *this;
    result.Remove(elem);
    return result;
}

template<class T>
SetType<T> SetType<T>::operator+(SetType& otherSet) {
    SetType<T> result = *this;

    for (int b = 0; b < numBuckets; b++) {
        for (auto it = otherSet.buckets[b].begin(); it != otherSet.buckets[b].end(); ++it) {
            result.Add(*it);
        }
    }
    return result;
}

template<class T>
SetType<T> SetType<T>::operator*(SetType& otherSet) {
    SetType<T> result = *this;

    for (int b = 0; b < numBuckets; b++) {
        for (auto it = otherSet.buckets[b].begin(); it != otherSet.buckets[b].end(); ++it) {
            if (!otherSet.Contains(*it)) {
                result.Remove(*it);
            }
        }
    }
    return result;
}

template<class T>
SetType<T> SetType<T>::operator-(SetType& otherSet) {
    SetType<T> result = *this;

    for (int b = 0; b < numBuckets; b++) {
        for (auto it = otherSet.buckets[b].begin(); it != otherSet.buckets[b].end(); ++it) {
            result.Remove(*it);
        }
    }
    return result;
}

// done
template<class T>
T SetType<T>::GetNextItem() {
    // Returns the current item and then move to the next item
    T item;

    // Your code here
    if (iterCount == numElems) {
        throw IteratorOutOfBounds();
    }
    while (bucketIter == buckets[currBucket].end()){
        currBucket++;
        bucketIter = buckets[currBucket].begin();

    }
    item = *bucketIter;
    ++iterCount;
    ++bucketIter;

    return item;
}

// done
template<class T>
int SetType<T>::GetHashIndex(const T& key) {
    // This is done... No touching!
    unordered_map<T,T> mapper;
    typename unordered_map<T,T>::hasher hashFunction = mapper.hash_function();
    return static_cast<int>(hashFunction(key) % numBuckets);
}

// done
template<class T>
void SetType<T>::SetMaxLoad(double max) {
    // This function is done
    if (max < 0.1)
        maxLoad = 0.1;
    else
        maxLoad = max;
}

// done
template<class T>
SetType<T>& SetType<T>::operator=(SetType const &other) {

    // Your code here
    copySet(other);
    return *this;
}

// done
template<class T>
void SetType<T>::Rehash(int newNumBuckets) {
    SetType<T> rehashedSet(newNumBuckets);

    // Your code here
    ResetIterator();
    for (int b = 0; b < numBuckets; b++) {
        for (auto it = buckets[b].begin(); it != buckets[b].end(); ++it) {
            rehashedSet.Add(*it);
        }
    }
    *this = rehashedSet;
}

// done
template<class T>
SetType<T>::SetType(int numBucks) {
    buckets = new forward_list<T>[numBucks];
    numBuckets = numBucks;
    numElems = 0;
    maxLoad = DEFAULT_LOAD_FACTOR;
}

// done
template<class T>
void SetType<T>::Add(T elem) {
    int bucket = GetHashIndex(elem);

    if (Contains(elem)){
        return;
    }

    ++numElems;
    buckets[bucket].push_front(elem);

    if (LoadFactor() > maxLoad) {
        Rehash(numBuckets * 2);
    }
}

// done
template<class T>
void SetType<T>::Remove(T elem) {
    int bucket = GetHashIndex(elem);
    if (Contains(elem)){
        buckets[bucket].remove(elem);
        --numElems;
    } else {
        return;
    }
}

// done
template<class T>
bool SetType<T>::Contains(T elem) {
    int bucket = GetHashIndex(elem);

    for (auto it = buckets[bucket].begin(); it != buckets[bucket].end(); ++it){
        if (*it == elem) {
            return true;
        }
    }
    return false;
}

template<class T>
void SetType<T>::MakeEmpty() {
    for (int b = 0; b < numBuckets; b++) {
        buckets[b].clear();
    }
    numElems = 0;
    ResetIterator();
}

// done
template<class T>
double SetType<T>::LoadFactor() const {
    return static_cast<double>(numElems)/numBuckets;
}

// done
template<class T>
void SetType<T>::ResetIterator() {
    bucketIter = buckets[0].begin();
    iterCount = 0;
    currBucket = 0;
}


template<class T>
void SetType<T>::copySet(const SetType &otherSet) {
    delete []buckets;
    buckets = new forward_list<T>[otherSet.numBuckets];
    numBuckets = otherSet.numBuckets;
    numElems = 0;

    for (int b = 0; b < otherSet.numBuckets; b++) {
        for (auto it = otherSet.buckets[b].begin(); it != otherSet.buckets[b].end(); ++it){
            Add(*it);
        }
    }
}
