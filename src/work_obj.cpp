//------------------------------
#include <string>
#include <iostream>
//------------------------------
#include "work_obj.h"
//------------------------------



int t_work_obj::func()
{

  std::cout << "start\n";

  print((char)-1);
  print((short)0);
  print((int)2130706433);

  print((long)8875824491850138409);

  print(std::string("8.8.8.8"));


  {
    std::vector<uint8_t> vecBytes = {127, 0, 0, 1};
    print(vecBytes);
  }

  {
    std::list<uint8_t> listBytes = {127, 0, 0, 5};
    print(listBytes);
  }


  std::cout << "finish" << std::endl;

  return 0;
}

