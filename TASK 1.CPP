#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
  string name;
  char ch;
  int inputuser;
  int score;
  cout<<endl;
  cout<<"Enter your name:";
  getline(cin,name);
  cout<<endl;
  do
  {
     srand(0);
     int variable=rand()%100+1;
     cout<<"Enter any number in between rang 1 to 100 -->  ";
     cin>>inputuser;
     cout<<endl;
     if(inputuser==variable)
     {
       cout<<"Congratulation ! Yoy guessed the correct number:"<<endl;
       score++;
     }
     else
     {
       cout<<"Soory, Yoy guessed wrong number Try agagin:"<<endl;
     }
     cout<<endl;
     cout<<"Would you like to try again [Y/N]:";
     cin>>ch;
     cout<<endl;

  }while(ch!='N');
  cout<<"YOUR SCORE IS --> "<<score<<endl;
  cout<<"GAME END "<<endl;
  
}
