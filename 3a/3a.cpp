#include <bits/stdc++.h>
using namespace std ;
ofstream output("answer.txt" , ios::trunc);
class node{
public:
int studentId;
string name ;
int marks;
node *next ;
};

node *first , *last ;
void create(int *p ,int *q , string *s, int size ) {
     node *ptr = new node ;
     first = ptr ;
     ptr->marks = p[size-1] ;
     ptr->studentId = q[size -1] ;
     ptr->name = s[size-1] ;
     ptr->next = nullptr ;
     last = ptr ; 
for(int i = size-2 ; i>=0 ; i--){
    node *ptr = new node ;
    ptr->marks = *(p+i);
     ptr->studentId = *(q+i) ;
     ptr->name =*(s+i)  ;
   last->next = ptr ;
    last = ptr ;
    last->next = nullptr ;

}}
void display(node *ptr ){
int k = 1 ;
    while (ptr!=nullptr)
    {output<<"RANK "<<k<<" : "<<ptr->name<<endl;
    k++;
       
        ptr=ptr->next ;
        /* code */
    }
    
}
int main(){ 
// here goes the code 
// reading a file
// c++ ifstream 
ifstream input("list_of_student.txt");
if(input)cout<<"File is opdened"<<endl;
if(!input) cout<<"file is not opened"<<endl;

int no_of_student;
input>>no_of_student;
int idOfStudent[no_of_student] , marksOfStudent[no_of_student];
string nameOfStudent[no_of_student] ;
//cout<<no_of_student<<endl;

for(int i = 0 ; i<no_of_student ; i++){
    input>>idOfStudent[i];
 input>>nameOfStudent[i];
    input>>marksOfStudent[i];

}
//output file


output<<"Rank of students according to question :-"<<endl;
output<<endl;
// bubble sort implement here :)
int x , y ;
string s ;
for (int outer = 0; outer < no_of_student-1; outer++)
{
// Becomes 1 (true) if list is not yet ordered
for ( int inner = outer+1; inner < no_of_student; inner++)
{ 
if (marksOfStudent[inner] <= marksOfStudent[outer]) // is marks are not equal
{// cout<<"It is happening"<<endl;
x = marksOfStudent[inner]; // Must switch both arrays
y = idOfStudent[inner]; // or they are no longer
s = nameOfStudent[inner];
// linked
marksOfStudent[inner] = marksOfStudent[outer];
idOfStudent[inner] = idOfStudent[outer];
nameOfStudent[inner] = nameOfStudent[outer] ;
marksOfStudent[outer] = x;
idOfStudent[outer] = y;
nameOfStudent[outer] = s ;


}

}


}


create(marksOfStudent , idOfStudent , nameOfStudent,no_of_student);
display(first);

return 0 ;}
