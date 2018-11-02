#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <list>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class LinkedList
{
   private:
     list<T> theList;

   public:
     LinkedList();
     LinkedList(const LinkedList<T>& other);
     ~LinkedList();

     int  size() const;  // note: a const method
     void add(T element);

     T get(int index) const;  // note: a const method
     T remove(int index); 

     std::vector<T> toArray() const;  // note: a const method

     LinkedList<T>& operator+=( const T& item );
};

template <class T>
LinkedList<T>::LinkedList(){
    cout << "inside default constructor" << endl;
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    this->theList = other.theList;
    cout << "inside copy constructor" << endl;
}



template <class T>
LinkedList<T>::~LinkedList(){}



template <class T>
int LinkedList<T>::size() const
{
    return theList.size();
}


template <class T>
void LinkedList<T>::add(T element)
{
    theList.push_back(element);
}



template <class T>
T LinkedList<T>::get(int index) const
{
    if (index >= theList.size() || index < 0){
        throw std::invalid_argument( "Invalid index to get() " );
    }

    typename list <T>::const_iterator it = theList.begin();
    for(int i = 0; i < index; i++){
        it++;
    }

    return (*it);
}


template <class T>
T LinkedList<T>::remove(int index)
{
    if (index >= theList.size() || index < 0){
        throw std::invalid_argument( "Invalid index to remove() " );
    }

    typename list <T>::iterator it = theList.begin();
    for(int i = 0; i < index; i++){
        it++;
    }
    theList.remove(*it);
        
    return (*it);
}



template <class T>
std::vector<T> LinkedList<T>::toArray() const
{
    std::vector<T> final;

    typename list <T>::const_iterator it = theList.begin();
    for(int i = 0; i < theList.size(); i++){
        final.push_back(*it);
        it++;
    }

    return final;
}


template <class T>
LinkedList<T>& LinkedList<T>::operator+=(const T& item) 
{
    theList.push_back(item);
    //LinkedList<T> list2 = theList;
    //return list2; 
    LinkedList<T> list2;
    return list2;
}



#endif