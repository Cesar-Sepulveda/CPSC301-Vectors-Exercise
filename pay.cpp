#include "person.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

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

  while(myFile){
    Person emp;
    vec.push_back(emp);
    myFile >> fName >> lName;
    vec.at(i).setFirstName(fName);
    vec.at(i).setLastName(lName);
    myFile >> IDNum;
    vec.at(i).setEmployeeId(IDNum);
    myFile >> cName;
    vec.at(i).setCompanyName(cName);
    myFile >> pay >> hours;
    vec.at(i).setPayRate(pay);
    vec.at(i).setHoursWorked(hours);
    getline(myFile,space);
    ++i;
  }
  vec.pop_back();
  myFile.close();
}

void getCompanies(vector<Person> &vec, vector<string> &co){
  for(int i = 0; i < vec.size(); ++i){
    co.push_back(vec.at(i).getCompanyName());
  }
  sort( co.begin(), co.end());
  auto duplicates = unique( co.begin(), co.end());
  co.erase(duplicates, co.end());
}

void printHighestPaid(vector<Person> &vec){
  int find = 0;
  for(int i = 0; i < vec.size(); ++i){
    if(vec.at(find).totalPay() < vec.at(i).totalPay()){
      find = i;
    }
  }
  cout << "Highest paid: " << vec.at(find).fullName() << endl;
  cout << "Employee ID: " << vec.at(find).getEmployeeId() << endl;
  cout << "Employer: " << vec.at(find).getCompanyName() << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << "Total pay: $" << vec.at(find).totalPay() << endl;
}

void separateAndSave(vector<Person> vec, vector<string> co){
  fstream myFile;
  for(int i = 0; i < co.size(); ++i){
    myFile.open(co.at(i)+".txt");
    myFile << co.at(i)+".txt" << endl;
    myFile << "_______________________________________________________" << endl;
    float total = 0;
    for(int j = 0; j < vec.size(); ++j){
      if(vec.at(j).getCompanyName() == co[i]){
        total += vec.at(j).totalPay();
        myFile << fixed << showpoint << setprecision(2);
        myFile << setw(10) << vec.at(j).getFirstName();
        myFile << setw(10) << vec.at(j).getLastName();
        myFile << setw(5) << vec.at(j).getEmployeeId();
        myFile<< setw(10) << vec.at(j).getCompanyName();
        myFile << setw(3) << "$" << vec.at(j).totalPay() << endl;
        }
        if(j+1 == vec.size()){
          myFile << "Total" << setw(3) << "$" << total<<endl;
      }
    }
    myFile.close();
  }

}

int main(){
  vector<Person> employees;
  vector<string> companyNames;
  string fileName = "input.txt";
  readData(employees, fileName);
  printHighestPaid(employees);
  getCompanies(employees, companyNames);
  separateAndSave(employees, companyNames);

  return 0;
}

