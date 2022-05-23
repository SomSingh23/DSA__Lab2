#include <bits/stdc++.h>
using namespace std ;
#include <bits/stdc++.h>
using namespace std ;
int sie ; // global variable
class node {
    public:
    int data;
    node *next ;
};
node *first , *second , *last ;
void create(int *p , int size ) {
     node *ptr = new node ;
     first = ptr ;
     ptr->data = p[0] ;
     ptr->next = nullptr ;
     last = ptr ; 
for(int i = 1 ; i<size ; i++){
    node *ptr = new node ;
    ptr->data = *(p+i);
   last->next = ptr ;
    last = ptr ;
    last->next = nullptr ;

}
sie = size ;}
void create2(int *p , int size ) {
     node *ptr = new node ;
     second = ptr ;
     ptr->data = p[0] ;
     ptr->next = nullptr ;
     last = ptr ; 
for(int i = 1 ; i<size ; i++){
    node *ptr = new node ;
    ptr->data = *(p+i);
   last->next = ptr ;
    last = ptr ;
    last->next = nullptr ;

}
}
   ofstream output("answer.txt" , ios::trunc) ;
void display(node *ptr){
 
    while (ptr!=nullptr)
    {
       output<<ptr->data<<endl;
        ptr=ptr->next ;
        /* code */
    }
    cout<<endl;
}



node *third , *endptr ;
void mergeTwoSortedList(){// cout<<"madhar cod"<<endl;
    // step 1 check
    if(first->data>=second->data){ 
       third = second ;
       endptr = second ;
             cout<<third->data <<endl;
        second=second->next ; endptr->next = nullptr ;
        
    }
   else if(first->data<second->data){
      third = first ;
      endptr = first ;
   //   cout<<third->data <<endl;
        first=first->next ;
        endptr->next = nullptr ;
          
    }
    while (first!=nullptr or second!=nullptr)
    {
         if(first->data>=second->data){
       endptr->next = second ;
      endptr = second;
       
       second=second->next ;  endptr->next = nullptr ;if(second==nullptr){ endptr->next = first ;break ; } 
    }
   else if(first->data<second->data){
      endptr->next = first ;
      endptr = first ;
      
        first=first->next ;   endptr->next = nullptr ; if(first==nullptr){ endptr->next = second ;break ; }
    }

    
    }
     

}
int main(){
    // output file stream declared here

    // two input file declared here
  ifstream input1("list1.txt");
ifstream input2("list2.txt");
if(input1 and input2) cout<<"Files opended"<<endl;
else cout<<"files are not opened"<<endl;
int list1_total_elements , list_2_total_elements ;
input1>>list1_total_elements;
input2>>list_2_total_elements;
int ar1[list1_total_elements];
int ar2[list_2_total_elements];
for(int i = 0 ; i<list1_total_elements ;i++){
    input1>>ar1[i];
}
for(int i = 0 ; i<list_2_total_elements ;i++){
    input2>>ar2[i];
}
output<<"My merged list is here :-"<<endl;
create(ar1 , list1_total_elements) ;
   create2(ar2 , list_2_total_elements) ;
  
 
   mergeTwoSortedList();

display(third);

}