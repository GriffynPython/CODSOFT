#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
 srand(static_cast<unsigned>(std::time(0)));

 int randomNumber = std::rand() % 10 + 1;
 int guess_no;
 while(guess_no!=randomNumber){
  cout<<"Enter your guess:"<<endl;
  cin>>guess_no;
  if(guess_no>randomNumber){
    cout<<"Too High"<<endl;
  }
  else{
    cout<<"Too Low"<<endl;
  }
 }
 cout<<"Congratulations! Your guess was right"<<endl;
 cout<<"The random number was:"<<randomNumber<<endl; 
}