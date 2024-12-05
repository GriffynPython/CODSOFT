#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Library{
  int price;
  string ISBN;
  string title;
  string author;
  bool Available;
};

vector<Library> lib;

void bookReturn(string s){
  bool found=false;
  for(auto& book:lib){
    if(s==book.title){
      found=true;
      if(!book.Available){
        cout<<"The book is returned to the Library"<<endl;
        book.Available=true;
      }
      else{
        cout<<"The book is already available in the library so you did not borrow it"<<endl;
      }
      break;
    }
    else if(s==book.ISBN){
      found=true;
      if(!book.Available){
        cout<<"The book is returned to the Library"<<endl;
        book.Available=true;
      }
      else{
        cout<<"The book is already available in the library so you did not borrow it"<<endl;
      }
      break;
    }
    else if(s==book.author){
      found=true;
      if(!book.Available){
        cout<<"The book is returned to the Library"<<endl;
        book.Available=true;
      }
      else{
        cout<<"The book is already available in the library so you did not borrow it"<<endl;
      }
      break;
    }
  }

  if(!found){
    cout<<"No book is found in the library matching:"<<s<<"Please check again";
  }
}

void checkOut(string s){
  for(auto& book:lib){
    if(s==book.title){
      if(book.Available){
        cout<<"The book is available to borrow"<<endl;
        book.Available=false;
      }
      else{
        cout<<"The book is not available in the Library and cannot be borrowed";
      }
    }
    else if(s==book.ISBN){
      if(book.Available){
        cout<<"The book is available to borrow";
        book.Available=false;
      }
      else{
        cout<<"The book is not available in the Library and cannot be borrowed";
      }
    }
    else if(s==book.author){
      if(book.Available){
        cout<<"The book is available to borrow";
        book.Available=false;
      }
      else{
        cout<<"The book is not available in the Library and cannot be borrowed";
      }
    }
  }
}

void bookSearch(string search){
  for(auto& book:lib){
    if(search==book.title){
      if(book.Available){
        cout<<"The book"<<book.title<<"is available and present in the library."<<endl;
      }
      else{
        cout<<"The book"<<book.title<<"is not present in the Library. But the library has this book in its collection"<<endl;
      }
    }
    else if(search==book.ISBN){
      if(book.Available){
        cout<<"The book"<<book.ISBN<<"is available and present in the library."<<endl;
      }
      else{
        cout<<"The book"<<book.ISBN<<"is not present in the Library. But the library has this book in its collection"<<endl;
      }
    }
    else if(search==book.author){
      if(book.Available){
        cout<<"The author"<<book.author<<"'s book is available and present in the library."<<endl;
      }
      else{
        cout<<"The author"<<book.title<<"'s book is not present in the Library. But the library has this book in its collection"<<endl;
      }
    }
  }
}

int main(){

  lib.push_back({499,"187987","Harry Potter 1","J.K Rowling",true});
  lib.push_back({499,"187988","Harry Potter 2","J.K Rowling",true});
  lib.push_back({499,"187989","Harry Potter 3","J.K Rowling",true});
  lib.push_back({499,"187990","Harry Potter 4","J.K Rowling",true});
  lib.push_back({499,"187991","Harry Potter 5","J.K Rowling",true});
  lib.push_back({499,"187992","Harry Potter 6","J.K Rowling",true});
  lib.push_back({499,"187993","Harry Potter 7 I","J.K Rowling",true});


  cout<<"Welcome to the Library."<<endl;
  cout<<"The books available in the library are:"<<endl;
  //Display information regarding all the books present in the library
  for(const auto& book:lib){
    cout<<"- "<<book.price;
    cout<<"- "<<book.ISBN;
    cout<<"- "<<book.title;
    cout<<"- "<<book.author;
    if(book.Available){
      cout<<" (Available)"<<endl;
    }
  }
  int x,y,ct,z;
  string str;
  while(x!=0){
    if(y==1){
      cout<<"Tell me which book you want to borrow:"<<endl;
      cin>>str;
      cout<<"Tell me how many days do you want to borrow the book for:"<<endl;
      cin>>z;
      checkOut(str);
    }
    else if(y==2){
      cout<<"Tell me which book you want to return:"<<endl;
      cin>>str;
      bookReturn(str);
    }
    else if(y==3){
      cout<<"Tell me which book you want to search for"<<endl;
      cin>>str;
      bookSearch(str);
    }
    cout<<"Enter a value other than 0 to keep the library going"<<endl;
    cout<<"Enter 0 to close the Library"<<endl;
    cin>>x;
    z--;
    
  }
}
