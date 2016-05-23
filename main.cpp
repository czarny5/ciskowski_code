#include <iostream>
#include <ctime>
#include "SortingAlgoritms.h"
#include <cstdlib>
#define NDEBUG
#include"debugging_tolls.h"
typedef float tested_type;

template <typename T>
void runMethode(SmartPtrArray<T>& array_to_sort)
{


    register clock_t begin = 0;
    register clock_t end = 0;
    register clock_t clocks_elapsed = 0;

    double average_time_boubleSort = 0.00;
    double average_time_selectionSort = 0.00;
    double average_time_insertionSort = 0.00;
    double average_time_shellSort = 0.00;
    double average_time_mergeSort = 0.00;
    double average_time_quickSort = 0.00;


    int amount_of_average_arrays = 1;


    SmartPtrArray<T> arrays_boubleSort[amount_of_average_arrays];
    SmartPtrArray<T> arrays_selectionSort[amount_of_average_arrays];
    SmartPtrArray<T> arrays_insertionSort[amount_of_average_arrays];
    SmartPtrArray<T> arrays_shellSort[amount_of_average_arrays];
    SmartPtrArray<T> arrays_mergeSort[amount_of_average_arrays];
    SmartPtrArray<T> arrays_quickSort[amount_of_average_arrays];
    for(auto i = 0; i<amount_of_average_arrays; i++)
    {
        arrays_boubleSort[i] = array_to_sort;
        arrays_selectionSort[i] = array_to_sort;
        arrays_insertionSort[i] = array_to_sort;
        arrays_shellSort[i] = array_to_sort;
        arrays_mergeSort[i] = array_to_sort;
        arrays_quickSort[i] = array_to_sort;
    }

    ///////////////BoubleSort///////////////////////////
        begin = clock();
        for(auto i = 0; i<amount_of_average_arrays; i++)
        {
           // SortingAlgoritms::boubleSort(arrays_boubleSort[i]);
        }
        end = clock();
        clocks_elapsed= end - begin;
        average_time_boubleSort=clocks_elapsed / static_cast<double>(CLOCKS_PER_SEC);
        average_time_boubleSort=average_time_boubleSort/amount_of_average_arrays;
    ////////////////SelectionSort////////////////////////////////////////////////
        begin = clock();
        for(auto i = 0; i<amount_of_average_arrays; i++)
        {
            //SortingAlgoritms::selectionSort(arrays_selectionSort[i]);
        }
        end = clock();
        clocks_elapsed= end - begin;
        average_time_selectionSort=clocks_elapsed / static_cast<double>(CLOCKS_PER_SEC);
        average_time_selectionSort=average_time_selectionSort/amount_of_average_arrays;
    ///////////////InsertionSort/////////////////////////////
        begin = clock();
        for(auto i = 0; i<amount_of_average_arrays; i++)
        {
            //SortingAlgoritms::insertionSort(arrays_insertionSort[i]);
        }
        end = clock();
        clocks_elapsed= end - begin;
        average_time_insertionSort=clocks_elapsed / static_cast<double>(CLOCKS_PER_SEC);
        average_time_insertionSort=average_time_insertionSort/amount_of_average_arrays;
    ///////////////ShellSort/////////////////////////////////
        begin = clock();
        for(auto i = 0; i<amount_of_average_arrays; i++)
        {
            SortingAlgoritms::shellSort(arrays_shellSort[i], SortingAlgoritms::reverseMode);
        }

        end = clock();
        clocks_elapsed= end - begin;
        average_time_shellSort=clocks_elapsed / static_cast<double>(CLOCKS_PER_SEC);
        average_time_shellSort=average_time_shellSort/amount_of_average_arrays;
    ////////////////MergeSort///////////////////////////////
        begin = clock();
        for(auto i = 0; i<amount_of_average_arrays; i++)
        {
            SortingAlgoritms::mergeSort(arrays_mergeSort[i]);
        }
        end = clock();
        clocks_elapsed= end - begin;
        average_time_mergeSort=clocks_elapsed / static_cast<double>(CLOCKS_PER_SEC);
        average_time_mergeSort=average_time_mergeSort/amount_of_average_arrays;
    ///////////////QuickSort///////////////////////////////
        begin = clock();
        for(auto i = 0; i<amount_of_average_arrays; i++)
        {
            SortingAlgoritms::quickSort(arrays_quickSort[i]);
        }
        end = clock();
        clocks_elapsed= end - begin;
        average_time_quickSort=clocks_elapsed / static_cast<double>(CLOCKS_PER_SEC);
        average_time_quickSort=average_time_quickSort/amount_of_average_arrays;


    std::cout<<"Average times of algorithms:"<<std::endl;
    std::cout<<"BoubleSort: "<<average_time_boubleSort<<std::endl;
    std::cout<<"SelectionSort: "<<average_time_selectionSort<<std::endl;
    std::cout<<"InsertionSort: "<<average_time_insertionSort<<std::endl;
    std::cout<<"ShellSort: "<<average_time_shellSort<<std::endl;
    std::cout<<"MergeSort: "<<average_time_mergeSort<<std::endl;
    std::cout<<"QuickSort: "<<average_time_quickSort<<std::endl;

   /* std::cout << std::endl << "Result Array:" << std::endl;
    for(auto i = 0; i < arrays_boubleSort[1].amount; i++)
        std::cout << arrays_boubleSort[1].array[i] << std::endl;*/



}
int main()
{
    srand(time(NULL));
    if(!SortingAlgoritms::testRoutine())
    {
        std::cerr << "SmartPtrArray test routine failed exiting program" << std::endl;
        return -1;
    }
    int array_to_sort_amount       = 10000000;

    SmartPtrArray<tested_type> array_to_sort(array_to_sort_amount);
    SmartPtrArray<tested_type> test;
    DEBUG_MSG(array_to_sort.amount<<std::endl);
    SmartPtrArray<tested_type> array_to_sort1(array_to_sort_amount/4);
    DEBUG_MSG(array_to_sort1.amount<<std::endl);
    SmartPtrArray<tested_type> array_to_sort2(array_to_sort_amount/2);
    DEBUG_MSG(array_to_sort2.amount<<std::endl);
    SmartPtrArray<tested_type> array_to_sort3(array_to_sort_amount*95/100);
    DEBUG_MSG(array_to_sort3.amount<<std::endl);
    array_to_sort.array[0] = rand()%10000/100.f;
    for(auto i = 0; i < array_to_sort.amount; i++)
    {
        array_to_sort.array[i] = rand()%10000/100.f;

        if(array_to_sort1.amount>i)
        {
                            ///1/4 poczatkowych elementow
            array_to_sort1.array[i]=array_to_sort.array[i];

        }
        if(array_to_sort2.amount>i)
        {
                             ///1/2 poczatkowych elementow
            array_to_sort2.array[i]=array_to_sort.array[i];
        }
        if(array_to_sort3.amount>i)
        {
                        ///95% poczatkowych elementow
            array_to_sort3.array[i]=array_to_sort.array[i];
        }
    }

    /*test=array_to_sort;
    for(auto i = 0; i < array_to_sort.amount; i++)
            std::cout << array_to_sort.array[i] << std::endl;
        std::cout << std::endl;
    selectionSort(test,SortingAlgoritms::reverseMode);
    for(auto i = 0; i < test.amount; i++)
        std::cout << test.array[i] << std::endl;*/
    std::cout << std::endl;
    std::cout<<"100% of initial elements:"<<std::endl;
    runMethode(array_to_sort);
    std::cout<<"25% of initial elements:"<<std::endl;
    runMethode(array_to_sort1);
    std::cout<<"50% of initial elements:"<<std::endl;
    runMethode(array_to_sort2);
    std::cout<<"95% of initial elements:"<<std::endl;
    runMethode(array_to_sort3);
    return 0;
}
