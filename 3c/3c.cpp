#include <bits/stdc++.h>
using namespace std ;
class node {
    public:
    int data ;
    node *next ;
};
node *first ;
node *last ;
int static ctr = 0 ;
void push(int x){
if(ctr==0){
    ctr++ ;
    node *ptr = new node ;
    ptr->data = x;
    first = ptr ;
    last = ptr ;
    ptr->next = nullptr ;

}
else {ctr++ ;
     node *ptr = new node ;
    ptr->data = x;
    last->next = ptr ;
    last = ptr;
    ptr->next = nullptr ;
}
}// output file stream
 ofstream output("answer.txt" , ios::trunc);
void pop(){
    node *ptr = first ;
   if(first==last){ctr = 0 ; output<<first->data<<" element of linked list is deleted"<<endl; first->next=nullptr ;first=nullptr ; last = nullptr ;}
   else { while(ptr->next->next!=nullptr){
        ptr=ptr->next;
    }
    
  
    
output<<ptr->next->data<<" element of linked list is deleted"<<endl;
    node *kill = last ;
    last = ptr;
    last->next = nullptr ;
    delete kill ;}

}

void display(){
    
    node *ptr = first ;
   if(first==nullptr)output<<"List is empty :("<<endl;

    while(ptr!=nullptr){
       output<<ptr->data<<" "; ptr=ptr->next ;
    }
    output<<endl; output<<endl;
}
int main(){
   // reading file ifstream
   ifstream input("stackInput.txt");
   if(input)cout<<"filed opened"<<endl;
   else {cout<<"file not opened"<<endl;}
   int size ; input>>size ;
   int a[size];
   for(int i = 0  ; i<size ; i++){
     input>>a[i];
     push(a[i]);
   }
   

   display();

   pop();pop();pop(); pop();pop();pop(); display();
   push(1000);push(1000);
  display();
}