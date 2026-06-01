#pragma once
#include <iostream>
#include <string>
using namespace std;

// ─── Array List ───────────────────────────────────────────────────────────────

template <class elemType>
class arrayListType {
protected:
    elemType* list;
    int length;
    int maxSize;
public:
    bool isEmpty() const;
    bool isFull() const;
    int  listSize() const;
    int  maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType& item) const;
    void insertAt(int location, const elemType& insertItem);
    void insertEnd(const elemType& insertItem);
    void retrieveAt(int location, elemType& retItem) const;
    void replaceAt(int location, const elemType& repItem);
    void clearList();
    int  seqSearch(const elemType& item) const;
    void insert(const elemType& insertItem);
    void remove(const elemType& removeItem);
    void removeAt(int location);
    void removeAll(const elemType& removeItem);

    arrayListType(int size = 100);
    ~arrayListType();
    arrayListType(const arrayListType<elemType>& otherList);
    const arrayListType<elemType>& operator=(const arrayListType<elemType>& otherList);
};

// ─── Node ─────────────────────────────────────────────────────────────────────

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type>* link;
};

// ─── Linked List Base ─────────────────────────────────────────────────────────

template <class Type>
class linkedListType {
protected:
    nodeType<Type>* first;
    nodeType<Type>* last;
    int count;
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    bool isEmptyList() const;
    void print() const;
    int  length() const;
    void destroyList();
    void copyList(const linkedListType<Type>& otherList);

    linkedListType();
    linkedListType(const linkedListType<Type>& otherList);
    ~linkedListType();
};

// ─── Unordered Linked List ────────────────────────────────────────────────────

template <class Type>
class unorderedLinkedList : public linkedListType<Type> {
public:
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    bool search(const Type& searchItem) const;
    void deleteNode(const Type& deleteItem);
};
