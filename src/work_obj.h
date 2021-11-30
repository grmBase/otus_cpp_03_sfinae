//---------------------------------------------------------------------------
#ifndef __work_obj_h__
#define __work_obj_h__
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <list>
//---------------------------------------------------------------------------


/*!
    Template for all arithmetic number. Uses is_arithmetic
*/
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, void>::type
print(T aArg) {

  // some debug
  //std::cout << "in print() for digitals, arg: " << aArg << std::endl;

  T tmp = aArg;
  for (size_t i = 0; i < sizeof(tmp); ++i) {
    uint8_t tmp2 = *((uint8_t*)(&tmp) + sizeof(tmp) - i - 1);
    std::cout << (int)tmp2;
    if (i != sizeof(aArg) - 1) {
      std::cout << '.';
    }
  }

  std::cout << std::endl;

}



template<typename T>
typename std::enable_if< std::is_same < T, std::string>::value, void>::type
print(T aArg) {
  // std::cout << "in print for string()" << std::endl;
  std::cout << aArg << std::endl;
}


template<typename T>
typename std::enable_if<
  std::is_same <T, std::vector<uint8_t>>::value ||
  std::is_same <T, std::list<uint8_t>>::value
, void>::type

print(T aArg) {

  //std::cout << "in print for vector(), arg: " << aArg << std::endl;

  bool f_is_it_first = true;

  for(const auto& curr_item : aArg) {

    if(!f_is_it_first) {
      std::cout << '.';
    }
    else {
      f_is_it_first = false;
    }

    std::cout << (int)curr_item;

  }
  std::cout << std::endl;
}



class t_work_obj
{
  public:

    int func();
};
//---------------------------------------------------------------------------

#endif
