/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>


int main(int argc, char* argv[])
{
ULListStr dat;
dat.push_back("7");
dat.push_front("8");
dat.push_back("9");
std::cout << "E output" << "\n" << "8 7 9 3" << "\n";
std::cout <<"R output"<< "\n" << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " ";
// prints: 8 7 9
std::cout << dat.size() << "\n";  // prints 3 since there are 3 strings stored
ULListStr t1;
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
t1.push_back("7");
std::cout <<"\n" << "E Output ";
std::cout <<"777777777777" << "\n";
std::cout << "R Output ";
for(int i = 0; i<12; i++)
{
  std::cout<<t1.get(i);
}
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
std::cout <<"\n" << "E Output ";
std::cout <<"77777777" << "\n";
std::cout << "R Output ";
for(int i = 0; i<8; i++)
{
  std::cout<<t1.get(i);
}
t1.push_front("1");
t1.push_front("1");
t1.push_front("1");
t1.push_front("1");
std::cout <<"\n" << "E Output ";
std::cout <<"111177777777" << "\n";
std::cout << "R Output ";
for(int i = 0; i<12; i++)
{
  std::cout<<t1.get(i);
}
std:: cout << "\n";
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_back();
t1.pop_front();
t1.pop_front();
t1.pop_front();
t1.pop_front();
t1.push_front("1");
t1.push_front("2");
t1.push_front("3");
t1.push_front("4");
std::cout << "E Output 4" << "\n";
std::cout << "R Output ";
std::cout <<t1.get(0) << "\n";
std::cout <<"E Output 4" << "\n";
std:: cout <<"R Output " << t1.front() << "\n";
std::cout << "E Output 1" << "\n";
std::cout << "R Output " << t1.back() << "\n";
std::cout <<"E Output 1" << "\n";
std::cout << "R Output " << t1.get(3) << "\n";
std::cout << "E Output 3" << "\n";
std::cout << "R Output " << t1.get(1) << "\n";
  return 0;
}


