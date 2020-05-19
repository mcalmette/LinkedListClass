//----------------------------------------------------------------------
// Author: Michael Calmette
// File:   linked_list_collection.h
// TODO: An implemented version of the Collection abstract class.  This
// has all of the files from the file and are written here.  
//----------------------------------------------------------------------

#ifndef LINKED_LIST_COLLECTION_H
#define LINKED_LIST_COLLECTION_H

#include <vector>
#include <algorithm>            
#include "collection.h"


template<typename K, typename V>
class LinkedListCollection : public Collection<K,V>
{
public:

  // constructor to initialize empty linked list
  LinkedListCollection();

  // copy constructor
  LinkedListCollection(const LinkedListCollection<K,V>& rhs);

  // assignment operator
  LinkedListCollection<K,V>& operator=(const LinkedListCollection<K,V>& rhs);
  
  // destructor to delete a linked list
  ~LinkedListCollection();
  
  // add a new key-value pair into the collection 
  void add(const K& a_key, const V& a_val);

  // remove a key-value pair from the collectiona
  void remove(const K& a_key);

  // find and return the value associated with the key
  bool find(const K& search_key, V& the_val) const;

  // find and return the values with keys >= to k1 and <= to k2 
  void find(const K& k1, const K& k2, std::vector<V>& vals) const;
  
  // return all of the keys in the collection 
  void keys(std::vector<K>& all_keys) const;

  // return all of the keys in ascending (sorted) order
  void sort(std::vector<K>& all_keys_sorted) const;

  // return the number of key-value pairs in the collection
  int size() const;

private:
  struct Node {
    K key;
    V value;
    Node* next;
  };
  Node* head;
  Node* tail;
  int length;

  // Optional: declare a void make_empty() helper function
  void make_empty();
};


// TODO: Implement member functions here
// 
// NOTE: Within the sort function, you can use the keys() function to
//       build up the all_keys_sorted vector, then call std::sort over
//       the all_keys_sorted list as in HW3

template<typename K, typename V>
LinkedListCollection<K,V>::LinkedListCollection() //constructor
{
   head = nullptr;
   tail = nullptr;
   length = 0;
}

template<typename K, typename V>
LinkedListCollection<K,V>::LinkedListCollection(const LinkedListCollection<K,V>& rhs) 
{
    *this = rhs; //copy constructor
}

template<typename K, typename V>
LinkedListCollection<K,V>& LinkedListCollection<K,V>::operator=(const LinkedListCollection<K,V>& rhs)
{
   //assign into existing object
   //delete lhs nodes
   //copy rhs to lhs
   if(this!= &rhs)
   {
	make_empty();
        head = nullptr;
	tail = nullptr;
 	length = 0;
	Node* tmp = rhs.head;
	while(tmp != nullptr)
	{
		add(tmp->key,tmp->value);
		tmp = tmp->next;
	}
	return *this;

   }
   return *this;
}


template<typename K, typename V>
LinkedListCollection<K,V>::~LinkedListCollection()
{
   make_empty(); //destructor
   head = nullptr;
   tail = nullptr;
}


template<typename K, typename V>
void LinkedListCollection<K,V>::add(const K& a_key, const V& v_val)
{
    Node* tmp = new Node;
    tmp->key = a_key;
    tmp-> value = v_val;
    if(length == 0) //empty list
    {
        head = tmp;
        tail = tmp;
        tmp -> next = nullptr;
    }
    else
    {
       tail-> next = tmp; //add to back
       tail = tmp;
       tmp -> next = nullptr;   
    }
    length++;

}


template<typename K, typename V>
void LinkedListCollection<K,V>::remove(const K& a_key)
{
  
  Node* tmp1 = head;
  if((tmp1->key) == a_key) //if key is equal to the head
  {
	head = head-> next;
 	delete tmp1;
	length--;
	tmp1 = nullptr;
 	return;
  }
  tmp1 = nullptr;
  
 
  Node* tmp = head;
  if(tmp->key == a_key)
  { 	
	if(length == 1) //get rid of list and make h/t null
	{
		head = nullptr;
		tail = nullptr;
	 	make_empty();
		length = 0;
		return;
	}
	else
	{
		head = tmp->next;
	}
	delete tmp;
	tmp = nullptr;
	length--;
	return;
  }

  while(tmp->next != nullptr) //anywhere else in list
  {
	if(tmp->next->key == a_key)
	{
		
		Node* ptr = tmp->next;
		tmp->next=ptr->next;
		delete ptr;
		ptr = nullptr;
		length=length-1;
		return;
		

	}
	tmp = tmp->next;
  }
  

}


template<typename K, typename V>
bool LinkedListCollection<K,V>::find(const K& search_key, V& the_val) const
{
  Node* tmp = head;
  while((tmp) != nullptr)
  {
      if(tmp->key == search_key)
   	{
		the_val = tmp-> value; //set val
                tmp = nullptr;
	 	return true; 
	}
      tmp=tmp->next;

  }
   tmp = nullptr;
   return false;

  
}


template<typename K, typename V>
void LinkedListCollection<K,V>::find(const K& k1, const K& k2, std::vector<V>& vals) const
{
     Node* tmp = head;
     while(tmp != nullptr)
     {
	if(tmp->key >= k1 && tmp->key <= k2) //compare
		vals.push_back(tmp->value); //add it to vector

	tmp = tmp->next;
     }
     tmp = nullptr;
}


template<typename K, typename V>
void LinkedListCollection<K,V>::keys(std::vector<K>& all_keys) const
{
    Node* tmp = head;
    while(tmp != nullptr) //return all keys
    {
        all_keys.push_back(tmp->key);
	tmp = tmp->next;
    }
   
}


template<typename K, typename V>
void LinkedListCollection<K,V>::sort(std::vector<K>& all_keys_sorted) const
{
   keys(all_keys_sorted); //use built in sort function
   std::sort(all_keys_sorted.begin(), all_keys_sorted.end());

}

template<typename K, typename V>
int LinkedListCollection<K,V>::size() const
{
    return length; //returns size
}

template<typename K, typename V>
void LinkedListCollection<K,V>::make_empty()
{
    while(head!= nullptr) //deletes all nodes
    {
	Node* ptr = head;
	head = head->next;
	delete ptr;
	length--;
    }

}

#endif
