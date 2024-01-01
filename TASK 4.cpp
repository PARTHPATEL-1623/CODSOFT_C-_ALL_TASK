 #include <iostream>
 #include <string>
 #include <fstream>
 using namespace std;

 struct todolist
 {
 	int id;
 	string task;
 };
 
 int ID = 1;
 void banner();
 void addtask();
 void showtask();
 int searchtask();
 void deletetask();
 void updatetask();
 
 int main()
 {
 	 system("cls");
 	 while (true)
 	 {
 	 	 banner();
 	 	 cout<< "\n\t1. Add Task -- ";
 	 	 cout<< "\n\t2. Show Task -- ";
 	 	 cout<< "\n\t3. Search Task -- ";
 	 	 cout<< "\n\t4. Delete Task -- ";
 	 	 cout<< "\n\t5. Update Task -- ";
 	 	 
 	 	 int choice;
 	 	 
 	 	 cout<<endl;
 	 	 cout<<" \n\t ENTER CHOICE --> ";
 	 	 cin>>choice;
 	 	 
 	 	 switch(choice)
 	 	 {
 	 	 	 case 1:
	 	 	 	addtask();
 	 	 	 	break;
 	 	 	 
			 case 2:
 	 	 	 	showtask();
 	 	 	 	break;
 	 	 	 	
 	 	 	 case 3:
	 	 	 	searchtask();
 	 	 	 	break;
 	 	 	 	
 	 	 	 case 4:
     	 	 	deletetask();
 	 	 	 	break;
 	 	 	 	
 	 	 	 case 5:
    	 	 	updatetask();
 	 	 	 	break;
 	 	 	 	
 	 	 	 	
 	 	 	 default:
				break;	
		 }
	  }
 }
 
 
 void banner()
 {
 	  cout<< "______________________________" <<endl;
 	  cout<< "\t        MY TODO             " <<endl;
 	  cout<< "______________________________" <<endl;
 
 }
 
 void addtask()
 {
 	  system("cls");
 	  banner();
 	  todolist todo;
 	  cout<< " ENTER NEW TASK --> "<<endl;
 	  cin.get();
 	  getline(cin,todo.task);
 	  char save;
 	  cout<< " Save ? [y/n]: ";
 	  cin>>save;
 	  
 	  if(save == 'y')
 	  {
 	  	  ID++;
 	  	  ofstream fout;
 	  	  fout.open("todo.txt", ios::app);
 	  	  fout<< "\n" <<ID;
 	  	  fout<< "\n" <<todo.task;
 	  	  fout.close();
 	  	  
 	  	  char more;
 	  	  
 	  	  cout<< "Add More Task [y/n]: ";
 	  	  cin >> more;
 	  	  
 	  	  if(more == 'y')
 	  	  {
 	  	  	 addtask();
		  }
		  
		  else 
		  {
		  	 system("cls");
		  	 cout<< " --- Added Successfully --- "<<endl;
		  	 return;
		  }
 	  }
 	  system("cls");
 }
 
 
 void showtask()
 {
 	  system("cls");
 	  banner();
 	  todolist todo;
 	  ifstream fin;
 	  fin.open("todo.txt");
	  cout<< " --- TASK --- "<<endl;
	  
	  while (!fin.eof())
	  {
	  	  fin >> todo.id;
	  	  fin.ignore();
	  	  getline(fin, todo.task);
	  	  
	  	  if(todo.task !="")
	  	  {
	  	  	 cout<< "\t" << todo.id << ": " << todo.task <<endl;
          }
          else
          {
          	 cout<< "\t EMPTY !!!" <<endl;
		  }
	  } 
	  fin.close();
	  char exit;
	  
	  cout<< " EXIT ? [y/n]: ";
	  cin >> exit;
	  
	  if(exit != 'y')
	  {
	  	showtask();
	  }
	  system("cls");
 }
 
 int searchtask()
 {
    system("cls");
	banner();
	int id;
	cout<< " ENTER TASK ID --> ";
	cin>>id;
	
	todolist todo;
	ifstream fin("todo.txt");
	
	while (!fin.eof())
	{
		fin >> todo.id;
		fin.ignore();
		getline(fin, todo.task);
		
		if(todo.id == id)
		{
			system("cls");
			cout<< "\t" << todo.id << ": " << todo.task <<endl;
			return id;
		}
	} 	 
	system("cls");
	cout<< " NOT FOUND !!! "<<endl;
	return 0;
 }
 
 void deletetask()
 {
 	 system("cls");
 	 int id = searchtask();
 	 
	 if (id != 0)
	 {
	 	char del;
	 	cout<< "\n\t DELETE ? [y/n]: ";
	 	cin>>del;
	 	
	 	if(del == 'y')
	 	{
	 		todolist todo;
	 		ofstream tempfile;
	 		tempfile.open("temp.txt");
	 		ifstream fin;
	 		fin.open("todo.txt");
	 		int index = 1;
	 		 
	 		while (!fin.eof())
	 		{
	 			fin >> todo.id;
	 			fin.ignore();
	 			getline(fin, todo.task);
	 			
	 			if(todo.id != id)
	 			{
	 				tempfile << "\n" <<index;
	 				tempfile << "\n" <<todo.task;
	 				index++;
	 				ID--;
				 }
			}
			fin.close();
			tempfile.close();
			remove("todo.txt");
			rename("temp.txt", "todo.txt");
			system("cls");
			cout<< "\n\t DELETE SUCCESSFULLY!" <<endl;
		 }
		 else
		 {
		 	system("cls");
		 	cout << " NOT DELETED !!!" <<endl;
		 }
	  } 
 } 
 
 
 void updatetask()
{
    system("cls");
    int id = searchtask();

    if (id != 0)
    {
        todolist todo;
        fstream file;
        file.open("todo.txt", ios::in | ios::out);

        while (file >> todo.id)
        {
            file.ignore();
            getline(file, todo.task);

            if (todo.id == id)
            {
            	file.seekp(file.tellg()- static_cast<streampos>(todo.task.length() + sizeof(todo.id) + 1));
                cout << "Enter the updated task: ";
                cin.get();
                getline(cin, todo.task);
                file << todo.task;
                break;
            }
        }
        file.close();
        system("cls");
        cout << "Task updated successfully!" << endl;
    }
    else
    {
        system("cls");
        cout << "Task not found!" << endl;
    }
}
