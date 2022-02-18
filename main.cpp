// add your code as appropriate
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
std::string a = "01/07/2018";
get_east_storage(a);





get_min_east();





get_max_east();





std::string b = "04/07/2018";
compare_basins(b);





std::string c = "01/01/2018";
std::string d = "01/31/2018";
reverse_order(c,d);

  return 0;
}
