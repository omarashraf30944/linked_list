#include <cassert>
#include <iostream>
using namespace std;

class linked_list {
    
  struct node {
      int item;
      node *next;
  };


node*first;
node*last;
int length;
public:
linked_list(){
    length=0;
    first = last = NULL;
}


bool isEmpty(){
    
    return length == 0;
}


void insertFirst(int element){
    node *newnode = new node;
    newnode->item= element;
    if(length == 0){
        first = last = newnode;
         newnode->next = NULL;
    }else{
        newnode->next= first; 
    }
    length++;
}
void insertLast(int element){
    node *newnode = new node;
    newnode->item= element;
    if(length == 0){
        first = last = newnode;
         newnode->next = NULL;
    }else{
        last->next = newnode;
        newnode->next = NULL;
    last = newnode;
    
}
length++;
}
  
    
void insertAtPos(int pos, int element){
    node *newnode = new node;
    newnode->item = element;
    if(pos == 0){
    insertFirst( element);}
    else if(pos == length){
        insertLast( element);
    }else{
          node *curr = first;
          for(int i=0; i < pos; i++){
          curr = curr->next;}
        newnode->next = curr->next;
        curr->next = newnode;
        length++;
                
           
    }
    
    }
    
    
    void print()
    {
    node*curr = first;
    std::cout<<" [ ";
    while(curr != NULL){
        
        std::cout<< curr->item << " ";
        curr = curr->next; 
    }
    std::cout<<" ] ";

        }

};








