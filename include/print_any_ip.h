//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>  
#include <vector>
#include <list>
//---------------------------------------------------------------------------



/*!
    Используем is_integral для всех целочисленных, т.к. всякие float, double из is_arithmetic нам не подходят
*/
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print(T aArg) {

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
//---------------------------------------------------------------------------


/*!
    Специализация для строки
*/
template<typename T>
typename std::enable_if< std::is_same < T, std::string>::value, void>::type
print(T aArg) {
  std::cout << aArg << std::endl;
}
//---------------------------------------------------------------------------


/*!
    Специализация для вектора или листа
*/
template<typename T>
typename std::enable_if<
  std::is_same <T, std::vector<uint8_t>>::value ||
  std::is_same <T, std::list<uint8_t>>::value
, void>::type

print(T aArg) {

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
//---------------------------------------------------------------------------