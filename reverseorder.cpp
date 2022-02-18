#include "reservoir.h"
#include "reverseorder.h"
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>
using namespace std;

void reverse_order(std::string date1, std::string date2){

  std::string z = date1;
  std::string y = date2;
  std::string date;

  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {

      cerr << "File cannot be opened for reading." << endl;

      exit(1);
  }

  double list[365]={};
  std::string list2[365]={};

  string junk;
  getline(fin, junk);
  double max = 0;
  double eastSt, eastEl, westSt, westEl;

  int count = 0;
 int x = 0;


  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {


    fin.ignore(INT_MAX, '\n');
    if (date == z){
      count += 1;
  }
  if (count == 1){
    list[x] = westSt;
    x++;
  }
  if (date == y){
    fin.close();
  }


}
int len = sizeof(list)/sizeof(list[0]);
for (int i = len; i >= 0; i-- ){
  if (list[i] != 0){
   std::cout << list[i] << std::endl;

}
}
}
