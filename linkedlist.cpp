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
        first = newnode; 
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
    insertFirst(element);}
    else if(pos == length){
        insertLast(element);
    }else{
          node *curr = first;
          for(int i = 0; i <= pos; i++){
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

void remove_at_first(){
    if(length == 0){
        return;
    }else if(length == 1){
        first = last = NULL;
        length--;
    }else{
        node *curr = first;
        first = first->next;
        delete curr;
        length--;
    }
}


void remove_at_last(){
    node *prev = first;
    node *curr = first->next;
        if(length == 0){
        return;
    }else if(length == 1){
        first = last = NULL;
        length--;
    }else{
    while(curr != NULL){
        prev = curr;
        curr = curr->next;
    }
    
    delete curr;
     prev->next = NULL;
    last = prev;
    length--;
    }
}



void remove(int element){
if (isEmpty()){
    return;
}else{
    node *curr;
    node *prev;
     if(element == first->item){
         curr = first;
         first = first->next;
         delete curr;
         length--;
         if(length == 0){
             last = NULL;
         }
     }else{
         curr = first->next;
         prev = first;
        while(curr != NULL && curr->item == element){
            prev = curr;
            curr = curr->next;  
        }
     }
}    
}

void reverse(){
    node *curr , *prev , *next;
    
    prev = NULL;
    curr = first;
    next = curr->next;
    
    while(curr != NULL){
         
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
         
    }
    first = prev;

}
int search(int element){
    
    node *curr = first;
    int pos = 0;
    while(curr != NULL){
        if (curr->item == element){
            return pos;

        }
            curr = curr->next;
            pos++;
    }
return -1;
}
};
int main(){
    linked_list l1;
    l1.insertFirst(10);
    l1.insertLast(30);
    l1.insertLast(40);
    l1.insertAtPos(1 , 20);
    l1.insertLast(50);
    l1.insertAtPos(0 , 250);
    l1.print();
    l1.reverse();
    l1.insertFirst(123);
    l1.print();
    cout<<"the position is ("<< l1.search(30) << " )"<<endl;;
    return 0 ;
}
