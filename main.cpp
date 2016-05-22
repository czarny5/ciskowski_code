#include <iostream>
#include "SortingAlgoritms.h"
#include "cstdlib"
#include "ctime"
int main()
{
    if(!SortingAlgoritms::testRoutine())
    {
        std::cerr << "SmartPtrArray test routine failed exiting program" << std::endl;
        return -1;
    }
    std::cout<<"Generating arrays"<<std::endl;
    srand(time(NULL));

    float Time[30];



    SmartPtrArray<int> arrays[30];
    SmartPtrArray<int> array_to_sort(100);

   ///std::cout << std::endl << "Array Before sort:" << std::endl;
    array_to_sort.array[0] = rand()%10000/100.f;
   /// std::cout << array_to_sort.array[0] << std::endl;
    for(auto i = 1; i < array_to_sort.amount; i++)
    {
        array_to_sort.array[i] = rand()%10000/100.f;
      ///  std::cout << array_to_sort.array[i] << std::endl;
    }
    for(auto i = 0; i<30; i++)
    {
        arrays[i] = array_to_sort;
    }
    SortingAlgoritms::quickSort(array_to_sort);
   /// std::cout << std::endl << "Result Array:" << std::endl;
   /// for(auto i = 0; i < array_to_sort.amount; i++)
   ///     std::cout << array_to_sort.array[i] << std::endl;


    return 0;
}
