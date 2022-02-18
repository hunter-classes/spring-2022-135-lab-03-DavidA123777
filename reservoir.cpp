#include <iostream>
#include "reservoir.h"
#include <fstream>
#include <cstdlib>
#include <climits>



double get_east_storage(std::string date){
std::ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {

  std::cerr << "File cannot be opened for reading." << std::endl;

  exit(1);

}
std::string a = date;
std::string remove;
getline(fin, remove);
double storage = 0;
double eastSt, eastEl, westSt, westEl;
while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
  fin.ignore(INT_MAX, '\n');
  //std::cout << date << " " << eastSt << std::endl;
  if (date == a){
    storage = eastSt;
  }

}

fin.close();
std::cout << storage << std::endl;
return storage;


}

double get_min_east(){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {

    std::cerr << "File cannot be opened for reading." << std::endl;

    exit(1);

  }
  std::string remove;
  getline(fin, remove);
  std::string date;
  double min  = 0;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n');
    if (date == "01/01/2018"){
     min = eastSt;

    }
    if (eastSt < min){
      min = eastSt;
    }

  }

  fin.close();
  std::cout << min << std::endl;
  return min;

}

double get_max_east(){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {

    std::cerr << "File cannot be opened for reading." << std::endl;

    exit(1);

  }
  std::string remove;
  getline(fin, remove);
  std::string date;
  double max  = 0;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n');
    if (date == "01/01/2018"){
     max = eastSt;

    }
    if (eastSt > max){
      max = eastSt;
    }

  }

  fin.close();
  std::cout << max << std::endl;
  return max;

  }


std::string compare_basins(std::string date){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {

  std::cerr << "File cannot be opened for reading." << std::endl;

  exit(1);

}
std::string b = date;
std::string remove;
getline(fin, remove);
double storage = 0;
std::string answer;
double eastSt, eastEl, westSt, westEl;
while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
  fin.ignore(INT_MAX, '\n');
  //std::cout << date << " " << eastSt << std::endl;
  if (date == b){
    if (eastSt > westSt){
      answer = "East";}

    else if (westSt > eastSt){
     answer = "West";

    }
    else{
      answer = "Equal";


    }
  }

}

fin.close();
std::cout << answer << std::endl;
return answer;


}
