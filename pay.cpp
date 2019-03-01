#include "person.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void readData(vector<Person> &vec,string fileName){
  fstream myFile;
  myFile.open(fileName);
  string fName;
  string lName;
  string cName;
  int IDNum;
  float pay;
  float hours;
  int i = 0;
  string space;

  while(i <= 16){
    myFile >> fName >> lName;
    //vec[i].setFirstName(fName);
    //vec[i].setLastName(lName);
    myFile >> IDNum;
    //vec[i].setEmployeeId(IDNum);
    myFile >> cName;
    //vec[i].setCompanyName(cName);
    myFile >> pay >> hours;
    //vec[i].setPayRate(pay);
    //vec[i].setHoursWorked(hours);
    getline(myFile,space);
    ++i;
  }
  myFile.close();
}

void getCompanies(vector<Person> &vec, vector<string> &co){
  for(int i = 0; i < vec.size(); ++i){
    co[i] = vec[i].getCompanyName();
  }
  for(int j = 0; j < co.size(); ++j){
    for(int k = 1; k < co.size(); ++k){
      if(co[j] == co[k]){
        co[k].erase();
      }
    }
  }
}

void printHighestPaid(vector<Person> &vec){
  int find = 0;
  for(int i = 0; i < vec.size(); ++i){
    if(vec[find].totalPay() < vec[i].totalPay()){
      find = i;
    }
  }
  cout << "Highest paid: " << vec[find].getFirstName() << endl;
  cout << "Employee ID: " << vec[find].getEmployeeId() << endl;
  cout << "Employer: " << vec[find].getCompanyName() << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << "Total pay: $" << vec[find].totalPay() << endl;
}

void separateAndSave(vector<Person> vec, vector<string> co){
  for(int i = 0; i < co.size(); ++i){
    fstream myFile;
    myFile.open(co[i]+".txt");
    for(int j = 0; j < vec.size(); ++j){
      if(vec[j].getCompanyName() == co[i]){

      }
    }
    myFile.close();
  }

}

int main(){
  vector<Person> employees;
  vector<string> compantNames;
  string fileName = "input.txt";
cout << "ok" << endl;
  readData(employees, fileName);
cout << "ok" << endl;
  for(int i =0; i < employees.size(); ++i){
    cout << employees[i].getFirstName() << endl;
  }

  printHighestPaid(employees);


  return 0;
}
