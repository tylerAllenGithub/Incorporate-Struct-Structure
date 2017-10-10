/*Tyler Allen
Lab 12-2
4-15-15
This program will output various details regarding an input file*/

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int MAX_EMP = 100;

struct employee
{
  string firstName;
  string lastName;
  char gender;
  double hourlyRate;
  int id;
  int age;
};

int readData(employee ar[]);
void findMale(const employee ar[], int numEmp);
void foundEmployee(const employee ar[], int numEmp);
employee findOldest(const employee ar[], int numEmp);
void printEmployee(employee e);
void printAllEmp(const employee ar[], int numEmp);
void giveRaise(double raise, employee ar[], int numEmp);
void swapEmp(int index, int index2, employee ar[], int numEmp);
void giveRaiseToOneEmployee(employee e, double raise);

  int main(){

  employee empAr[MAX_EMP];
  int numEmployees;
  numEmployees=readData(empAr);
  cout<<"There are "<<numEmployees<<" employees"<<endl;
  findMale(empAr, numEmployees);
  foundEmployee(empAr, numEmployees);
  employee oldest = findOldest(empAr, numEmployees);
  cout<<oldest.firstName<<endl;
   printEmployee(oldest);
   printAllEmp(empAr, numEmployees);
   giveRaise(5.5, empAr, numEmployees);
   printAllEmp(empAr, numEmployees);
   swapEmp(0, 15, empAr, numEmployees);
   printAllEmp(empAr, numEmployees);
   giveRaiseToOneEmployee(empAr[0], 2.0);
   printEmployee(empAr[0]);
  
     return 0;
  }

int readData(employee ar[])
{
  int count=0;
  ifstream inFile;

  inFile.open("employees.dat");

  if(!inFile)
    {
      cout<<"Cannot open the file"<<endl;
    }
  else
    {
      inFile>>ar[count].firstName;
      inFile>>ar[count].lastName;
      inFile>>ar[count].gender;
      inFile>>ar[count].hourlyRate;
      inFile>>ar[count].id;
      inFile>>ar[count].age;
      
      while(inFile)
      {
	count++;
	inFile>>ar[count].firstName;
	inFile>>ar[count].lastName;
	inFile>>ar[count].gender;
	inFile>>ar[count].hourlyRate;
	inFile>>ar[count].id;
	inFile>>ar[count].age;
       }
      inFile.close();
     }
  return count;
}

void findMale(const employee ar[], int numEmp)
{
  ofstream outFile;
  outFile.open("maleOut.dat");

  for(int i=0; i<numEmp; i++)
    {
      if(ar[i].gender=='M')
	{
	  outFile<<left<<setw(10)<<ar[i].id;
	  outFile<<left<<setw(10)<<ar[i].firstName;
	  outFile<<left<<setw(10)<<ar[i].lastName<<endl;
	}
    }
  outFile.close();
}

void foundEmployee(const employee ar[], int numEmp)
{
  int id;
  cout<<"Enter an employee id: ";
  cin>>id;
bool found = false; //set to false as long as the id hasn.t been found yet. !found is the same as found == false
//go through each slot in the array
for(int i = 0; !found && i < numEmp; i++)
  {
    if(ar[i].id==id)
      {
	cout<<ar[i].firstName<<" "<<ar[i].lastName<<endl;
        found = true; //set to true when the id is found.
      }
  }
 if(!found)
   cout<<"There is no employee with ID "<<id<<"."<<endl;
}

employee findOldest(const employee ar[], int numEmp)
{
  employee oldest = ar[0];

  for(int i=1;i<numEmp;i++)
    {
      if(ar[i].age>oldest.age)
	oldest=ar[i];
    }
  return oldest;
}

void printEmployee(employee e)
{
cout<<left<<setw(6)<<right<<e.firstName<<setw(10)<<e.lastName<<setw(10)<<e.gender
<<setw(10)<<fixed<<setprecision(2)<<e.hourlyRate<<setw(10)<<e.id<<setw(10)<<e.age<<endl;
}


void giveRaise(double raise, employee ar[], int numEmp)
{
  for(int i=0;i<numEmp;i++)
    {
        ar[i].hourlyRate=ar[i].hourlyRate*(raise/100)+ar[i].hourlyRate;
    }
}
void printAllEmp(const employee ar[], int numEmp)
{
  for(int i=0;i<numEmp;i++)
    {
      cout<<left<<setw(15)<<ar[i].firstName<<setw(15)<<ar[i].lastName
	  <<setw(15)<<ar[i].gender<<setw(15)<<fixed<<setprecision(2)<<ar[i].hourlyRate<<setw(15)
	  <<ar[i].id<<setw(15)<<ar[i].age<<endl;
    }
}

void swapEmp(int index, int index2, employee ar[], int numEmp)
{
  if((index<0||index>=numEmp)||(index2<0||index2>=numEmp))
    cout<<"Invalid index"<<endl;
  else
    {
      employee temp = ar[index];
      ar[index] = ar[index2];
      ar[index2] = temp; 
    }
}

void giveRaiseToOneEmployee(employee e, double raise)
{
  e.hourlyRate=e.hourlyRate*(raise/100)+e.hourlyRate;
}
