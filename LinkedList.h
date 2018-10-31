#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <list>
#include <vector>

using namespace std;

template <class T>
class LinkedList
{
   private:
     std::list<T> theList;

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
LinkedList<T>::LinkedList(){}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    this->theList = other.theList;
}



template <class T>
LinkedList<T>::~LinkedList(){}



template <class T>
int LinkedList<T>::size() const{

    return theList.size();
}


template <class T>
void LinkedList<T>::add(T element){
    theList.push_back(element);
    return;
}



template <class T>
T LinkedList<T>::get(int index) const{
    if (index >= theList.size() || index < 0){
        string msg = "Invalid index to get(): " + to_string(index) + ", list size= " +  to_string(theList.size());
        throw invalid_argument(msg.c_str());
    }

    list<T>::const_iterator it = theList.begin();
    for(int i = 0; i < index; i++){
        it++;
    }

    return (*it);

}


template <class T>
T LinkedList<T>::remove(int index){
    if (index >= theList.size() || index < 0){
        string msg = "Invalid index to remove(): " + to_string(index) + ", list size= " +  to_string(theList.size());
        throw invalid_argument(msg.c_str());
    }

    list<T>::iterator it = theList.begin();
    for(int i = 0; i < index; i++){
        it++;
    }
    theList.remove(*it);
        
    return (*it);
}



template <class T>
std::vector<T> LinkedList<T>::toArray() const{
    std::vector<T> final;
    while (! theList.empty()) {
        final.push_back(theList.front());
        theList.pop_front();
    }

    return final;
}


template <class T>
LinkedList<T>& LinkedList<T>::operator+=(const T& item) {
    theList.append(item);
    
    return *theList;

}



#endif