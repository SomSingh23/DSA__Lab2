#include <bits/stdc++.h>
using namespace std ;
class node{
public:
int studentId;
string name ;
int marks;
node *next ;
};

node *first , *last ;
void create( int p[]  , int b[] , string c[] , int size){
  node *ptr = new node ;
     first = ptr ;
     ptr->marks = p[size] ;
     ptr->studentId = b[size] ;
     ptr->name = c[size] ;
     ptr->next = nullptr ;
     last = ptr ; 
for(int i = size-1 ; i>=0; i--){
    node *ptr = new node ;
    ptr->marks = *(p+i);
    ptr->studentId = *(b+i) ;
     ptr->name = *(c+i) ;
   last->next = ptr ;
    last = ptr ;
    last->next = nullptr ;

}}
void touch(){
    cout<<"touched here"<<endl;
}
void display(node *ptr){
  cout<<"Checked"<<endl;
    while (ptr!=nullptr)
    {
        cout<<ptr->studentId<<" ";
        ptr=ptr->next ;
        /* code */
    }
    
}
int main(){
   // here goes the code 

// reading a file
// c++ ifstream 
ifstream input("list_of_student.txt");
if(input)cout<<"File is opened"<<endl;
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
ofstream output("answer.txt" , ios::trunc);

output<<endl;
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


for(int i = 0 ; i<no_of_student ; i++){
  output<<idOfStudent[i]<<endl;;
 output<<nameOfStudent[i]<<endl;
 output<<marksOfStudent[i]<<endl;
   

}
create(marksOfStudent ,idOfStudent, nameOfStudent , no_of_student);
display(first);
cout<<first<<endl;
touch();
return 0 ;
}