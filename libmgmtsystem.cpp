#include <iostream>
#include <string>
#include <vector>
using namespace std;

//This is a struct dat structure for a book.It contains a book's information. 
struct Library{
  int price;
  string ISBN;
  string title;
  string author;
  bool Available;
  int borrow_time;
};
//This is a vector created to store a book struct data structure. It is a collection of books(struct).
//It is also called a Library.
vector<Library> lib;
//A function created to return a book.
//I made this to divide the management system into smaller tasks like this function.
//Also to help me practice functions in a big(moderate) program.
//This function is used to return a borrowed book.
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
    cout<<"S does not match any known books, ISBN or author name."<<endl;
  }
}
//This function is used to borrow a book from a Library(vector).
//It has a string parameter whiich it uses to find out the book the user wants to borrow.
void checkOut(string s){
  int z;
  bool found=false;
  for(auto& book:lib){
    if(s==book.title){
      found=true;
      if(book.Available){
        cout<<"Enter no of days you want to borrow the book for: 7 or 14 ";
        cin>>z;
        book.borrow_time=z;
        cout<<"You have borrowed the book. Please return the book before or on the last due date."<<endl;
        book.Available=false;
      }
      else{
        cout<<"The book is not available in the Library and cannot be borrowed";
      }
      break;
    }
    else if(s==book.ISBN){
      found=true;
      if(book.Available){
        cout<<"Enter no of days you want to borrow the book for: 7 or 14 ";
        cin>>z;
        book.borrow_time=z;
        cout<<"The book is available to borrow";
        book.Available=false;
      }
      else{
        cout<<"The book is not available in the Library and cannot be borrowed";
      }
      break;
    }
    else if(s==book.author){
      found=true;
      if(book.Available){
        cout<<"Enter no of days you want to borrow the book for: 7 or 14 ";
        cin>>z;
        book.borrow_time=z;
        cout<<"The book is available to borrow";
        book.Available=false;
      }
      else{
        cout<<"The book is not available in the Library and cannot be borrowed";
      }
      break;
    }
  }
  if(!found){
    cout<<"S does not match any known books, ISBN or author name."<<endl;
  }
}
//It is a function used to search for a book in a Library.
//The user uses this function to find a book he likes or has an interest in borrowing.
void bookSearch(string search){
  bool found=false;
  for(auto& book:lib){
    if(search==book.title){
      found=true;
      if(book.Available){
        cout<<"The book "<<book.title<<" is available and present in the library."<<endl;
      }
      else{
        cout<<"The book "<<book.title<<" is not present in the Library. But the library has this book in its collection"<<endl;
      }
      break;
    }
    else if(search==book.ISBN){
      found=true;
      if(book.Available){
        cout<<"The book "<<book.ISBN<<" is available and present in the library."<<endl;
      }
      else{
        cout<<"The book "<<book.ISBN<<" is not present in the Library. But the library has this book in its collection"<<endl;
      }
      break;
    }
    else if(search==book.author){
      found=true;
      if(book.Available){
        cout<<"The author "<<book.author<<"'s book is available and present in the library."<<endl;
      }
      else{
        cout<<"The author "<<book.title<<"'s book is not present in the Library. But the library has this book in its collection"<<endl;
      }
      break;
    }
  }
  //Found is a good flag. It is used in all the functions.
  if(!found){
    cout<<"S does not match any known books, ISBN or author name."<<endl;
  }
}

int main(){
  //This code pushes information about books into the Library.
  lib.push_back({499,"187987","Harry Potter 1","J.K Rowling",true,0});
  lib.push_back({499,"187988","Harry Potter 2","J.K Rowling",true,0});
  lib.push_back({499,"187989","Harry Potter 3","J.K Rowling",true,0});
  lib.push_back({499,"187990","Harry Potter 4","J.K Rowling",true,0});
  lib.push_back({499,"187991","Harry Potter 5","J.K Rowling",true,0});
  lib.push_back({499,"187992","Harry Potter 6","J.K Rowling",true,0});
  lib.push_back({499,"187993","Harry Potter 7 I","J.K Rowling",true,0});
  lib.push_back({699, "194376", "The Hobbit", "J.R.R. Tolkien", true,0});
  lib.push_back({899, "198743", "1984", "George Orwell", true,0});
  lib.push_back({499, "187123", "To Kill a Mockingbird", "Harper Lee", true,0});
  lib.push_back({349, "193456", "The Catcher in the Rye", "J.D. Salinger", true,0});
  lib.push_back({799, "192345", "The Great Gatsby", "F. Scott Fitzgerald", true,0});
  lib.push_back({599, "194321", "Pride and Prejudice", "Jane Austen", true,0});
  lib.push_back({1099, "196543", "The Lord of the Rings", "J.R.R. Tolkien", true,0});
  lib.push_back({399, "195432", "Animal Farm", "George Orwell", true,0});



  cout<<"Welcome to the Library."<<endl;
  cout<<"The books available in the library are:"<<endl;
  //Display information regarding all the books present in the library including its availability and borrow time.
  for (const auto& book : lib) {
    cout << " - " << book.title
         << " | Borrow Time: " << (book.Available ? "N/A" : to_string(book.borrow_time))
         << (book.Available ? " (Available)" : " (Not Available)") << endl;
}
  /*for(const auto& book:lib){
    cout<<" - "<<book.borrow_time;
    cout<<" - "<<book.price;
    cout<<" - "<<book.ISBN;
    cout<<" - "<<book.title;
    cout<<" - "<<book.author;
    if(book.Available){
      cout<<" (Available)"<<endl;
    }
    else{
      cout<<" (Not Available)"<<endl;
    }
  }*/
  //Fine is declared and initialized for calculation.
  int x=1,y,ct,Fine=10;
  string str;
  while(x!=0){
    //Options that the user can do. 
    cout<<"Press 1 to borrow a book"<<endl;
    cout<<"Press 2 to return the book"<<endl;
    cout<<"Press 3 to search for a book"<<endl;
    cout<<"What do you want to do? Enter a number: ";
    cin>>y;
    //I used cin.ignore here to clear out the input buffer.
    cin.ignore();
    if(y==1){
      cout<<"Tell me which book you want to borrow: ";
      //I used the getline function with the cin here to include multi word inputs as cin only handles one word.
      getline(cin,str);
      checkOut(str);
    }
    else if(y==2){
      cout<<"Tell me which book you want to return:"<<endl;
      getline(cin,str);
      for (auto& book : lib) {
        //Traverse throguh every book struct data structure, check if the user input matches and the book is available and calculate its borrow time.
            if ((str == book.title || str == book.ISBN || str == book.author) && !book.Available) {
                if (book.borrow_time < 0) {
                    int oD = abs(book.borrow_time);
                    cout << "You have an overdue fine of " << Fine*oD << " for the book '" << book.title << "'." << endl;
                }
                break;
            }
        }
      //This function returns the book.
      bookReturn(str);
    }
    else if(y==3){
      cout<<"Tell me which book you want to search for: ";
      getline(cin,str);
      //This function searches the book by taking in the user input as an argument.
      bookSearch(str);
    }
    cout<<"Enter a value other than 0 to keep the library going"<<endl;
    cout<<"Enter 0 to close the Library: ";
    //This is a flag variable used to control the while loop.
    cin>>x;
    
  }
}
