#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Astruct data sttructure that stores a string and a bool.
struct Task {
    string description;
    bool complete;
};

int main() {
    //A vector of the struct data structure where every element in it is a struct containing a strings and bool value.
    //This is a to-do list.
    vector<Task> todolist;

    // Adding tasks to the to-do list
    //For practice and learning.
    todolist.push_back({"Grocery", false});
    todolist.push_back({"Report", false});
    todolist.push_back({"Study",false});

    // Marking a task as complete. 
    //I did this for practice and to experience how a struct data structure changes and is manipulated.
    todolist[1].complete = true;

    // Displaying tasks
    //Lets the user see the tasks already present in the to-do list.
    cout << "To-Do List:" << endl;
    for(const auto& task : todolist) {
        cout << " - " << task.description;
        if (task.complete) {
            cout << " (Completed)";
        }
        cout << endl;
    }
    int i=1;
    while(i!=0){    
    int choice;
        //These are the options that the user has when he interacts with the to-do list.
    cout << "Enter 1 to add tasks" << endl;
    cout << "Enter 2 to remove the last task added" << endl;
    cout << "Enter 3 to display the total tasks" << endl;
    cout << "Enter 4 to change a task to true" << endl;
    cin >> choice;
//I used switch case statements here because I wanted  to practice them. 
    //Although I like using the if-else statements.
    switch(choice) {
        case 1: {
            string task_desc;
            cout << "Enter description of task" << endl;
            cin >> task_desc;
            todolist.push_back({task_desc,false});
            for(const auto& task : todolist) {
                cout << "- " << task.description;
                if (task.complete) {
                  cout << " (Completed)";
              }
            cout << endl;
          }
          break;
        }

        case 2:{
            //removing the last task added using the erase function of vectors
            if (!todolist.empty()) {
                todolist.erase(todolist.end() - 1);
                cout << "Last task removed successfully." << endl;
            } else {
                cout << "The to-do list is already empty." << endl;
            }
            break;
        }

        case 3:{
            for(const auto& task:todolist){
                cout<<"-"<<task.description;
            }
            break;
        }

        case 4: {
            int index;
            cout<<"Enter index of a task you want to mark as true"<<endl;
            cin>>index;
            if(index>=0 && index<todolist.size()){
                todolist[index].complete=true;
                cout<<"The task is completed"<<endl;
            }
            
            else{
                cout<<"Invalid input"<<endl;
            }
        } 

        cout << "To-Do List:" << endl;
            for(const auto& task : todolist) {
                cout << "- " << task.description;
            if (task.complete) {
                cout << " (Completed)";
            }
            cout << endl;
    }
        //This is the option when there is an invalid input by the user.
        default:{
            cout << "Invalid input" << endl;
        }
    }
    //This is a flag variable used to control the while loop.
    //I like using these for while loops.
    cout<<"Enter a number other than 0 to start the to-do list"<<endl;
    cout<<"Enter 0 to stop the to-do list: ";
    cin>>i;
  }

  cout<<"The to-do list has finished working"<<endl;
    

    return 0;
}
