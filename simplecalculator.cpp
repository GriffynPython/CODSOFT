#include <iostream>
#include <string>
using namespace std;
//I used the functions here to practice how to use them in a program effectively.
//They also help in increasing my programming skill and is good practice.
int add(int a,int b){
  return a+b;
}

int sub(int a,int b){
  return a-b;
}

int mul(int a,int b){
  return a*b;
}

int div1(int a,int b){
  //Error checking. Divide by zero
  if(b==0){
    cout<<"Invalid input.Divide by zero";
  }
  return a/b;
}

int main(){
  int x,y,result;
  cout<<"Enter first number:"<<" ";
  cin>>x;
  cout<<"Enter second number:"<<" ";
  cin>>y;
  string op;
  cout<<"Enter type of operation:+,-,*,/"<<" ";
  cin>>op;
  //Could have also used the switch case statement here but I like using if-else statements more.
  //They are much simpler than the switch case statements.
  if(op=="+"){
    result=add(x,y);
    cout<<"The addition between two numbers "<<x<<" and "<<y<<" is: "<<result<<endl;
  }
  else if(op=="-"){
    result=sub(x,y);
    cout<<"The subtraction between two numbers "<<x<<" and "<<y<<" is: "<<result<<endl;
  }
  else if(op=="*"){
    result=mul(x,y);
    cout<<"The multiplication between two numbers "<<x<<" and "<<y<<" is: "<<result<<endl;
  }
  else if(op=="/"){
    result=div1(x,y);
    cout<<"The division between two numbers"<<" "<<x<<" and "<<y<<" is: "<<result<<endl;
  }
  else{
    cout<<"Invalid input."<<endl;
    cout<<"Enter only: +,-,*,/"<<" ";
  }
}
