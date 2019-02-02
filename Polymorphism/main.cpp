#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

/*Start of Code */
/* This code must be compiled with C++14 */
/*if you are using C++11 replace auto with std::map<int,Node*>::iterator */

class LRUCache: public Cache{

    public:
        LRUCache(int in_capacity){cp = in_capacity;};
        void set(int KeyIn, int ValIn){
            Node* NewNode;
            if(mp.empty()){
                NewNode = new Node(KeyIn, ValIn);
                tail = head = NewNode;
                mp[KeyIn] = NewNode;
                return;
            }
            auto iterator = mp.find(KeyIn);
            if(iterator != mp.end()){
                iterator->second->value = ValIn;
                if(head == iterator->second) return;

                if(tail==iterator->second) {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else {
                    iterator->second->prev->next = iterator->second->next;
                    iterator->second->next->prev = iterator->second->prev;
                }
                iterator->second->next = head;
                iterator->second->prev = NULL;
                head->prev = iterator->second;
                head = iterator->second;
            }
            else{
                NewNode = new Node(head->prev,head,KeyIn,ValIn);
                head->prev = NewNode;
                head = NewNode;
                mp[KeyIn] = NewNode;
                if (mp.size()>cp){
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    delete tail->next;
                    tail->next = NULL;
                }
            }
        }
        int get (int KeyIn){
            auto iterator = mp.find(KeyIn);
            if ( iterator != mp.end())
                return iterator->second->value;
            else return -1;
        }
};

/*End of Code*/

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

