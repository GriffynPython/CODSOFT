#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
 //I used the range of [1-10] as it would be easier to guess the random number 
// and be less time consuming
 srand(static_cast<unsigned>(std::time(0)));
//random number is stored in a variable.
 int randomNumber = std::rand() % 10 + 1;
 int guess_no;
 while(guess_no!=randomNumber){
  cout<<"Enter your guess:"<<endl;
  cin>>guess_no;
  //If guess no is higher than randomnumber more than 1.
  if(guess_no-randomNumber>1){
    cout<<"Too High! Guess lower"<<endl;
  }
   //If guess no is higher than random number by 1.
  else if(guess_no-randomNumber==1){
    cout<<"A little lower"<<endl;
  }
   //If guess no is lower than random number more than 1.
  else if(randomNumber-guess_no>1){
    cout<<"Guess Higher"<<endl;
  }
   //If guess no is lower than random number by 1.
  else if(randomNumber-guess_no==1){
    cout<<"Very Close. Guess higher"<<endl;
  }
 }
 cout<<"Congratulations! Your guess was right"<<endl;
 cout<<"The random number was: "<<randomNumber<<endl; 
}
