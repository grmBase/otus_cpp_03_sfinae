//-----------------------------------------------------------------------------
#include <iostream>
//-----------------------------------------------------------------------------
#include "work_obj.h"
//-----------------------------------------------------------------------------


/*!
    Здесь только "запуск основного кода", настройка перехватов всяких исключений
*/
int main(int, const char* [])
{

  t_work_obj workObj;

  try 
  {
    int nResult = workObj.func();
    if(nResult) {
      std::cout << "Error in func(), code: " << nResult << std::endl;
      return nResult;
    }
  }
  catch(const std::exception& exc)
  {
    std::cout << "Exception caught. Info: " << exc.what() << std::endl;
    return -33;
  }

  return 0;
}
//-----------------------------------------------------------------------------
