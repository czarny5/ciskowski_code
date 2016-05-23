#ifndef SORTINGALGORITMS_H
#define SORTINGALGORITMS_H
#include <SmartPtrArray.h>
#include <algorithm>
namespace SortingAlgoritms
{
    enum Mode{
    noMode = 0b0,
    reverseMode = 0b1
    };
    template <typename T>
    void reverse(SmartPtrArray<T>& array_before)
    {
        for(auto i = 0; i < array_before.amount/2; i++)
        {

            std::swap(array_before.array[i], array_before.array[array_before.amount-i-1]);
        }
    }
    template <typename T>
    void merge(SmartPtrArray<T>& array_a, SmartPtrArray<T>& array_b, SmartPtrArray<T>& result_array)
    {
        if(result_array.array!=nullptr)
            result_array.array.reset();
        std::unique_ptr <T[]> tmp (new T [array_a.amount+array_b.amount]);
        result_array.array = std::move(tmp);// now result_array is only pointer with ownership
        result_array.amount= array_a.amount + array_b.amount;


        if(array_a.array[array_a.amount-1] <= array_b.array[0])//1 przypadek
        {
            for(auto i = 0; i < array_a.amount; i++)
                 result_array.array[i] = array_a.array[i];
            for(auto i = array_a.amount; i < ( array_a.amount + array_b.amount ); i++)
                result_array.array[i] = array_b.array[i - array_a.amount];


        }else
        {                                                  //2 przypadek
            auto j = 0;
            auto i = 0;
            for(i = 0; i <= array_a.amount - 1; i++)
            {
                while(j < array_b.amount && array_b.array[j] <= array_a.array[i])
                {
                    result_array.array[i+j] = array_b.array[j];
                    j++;
                }
                result_array.array[i+j] = array_a.array[i];
            }
            while(j < array_b.amount)
            {
                result_array.array[array_a.amount+j] = array_b.array[j];
                j++;
            }

        }
    }


    template <typename T>
    void boubleSort(SmartPtrArray<T>& array_before)
    {
        for(auto i = 0; i < array_before.amount; i++)
        {
            for(auto j = array_before.amount-1; j >0; j--)
            {
                if(j-1 < 0 || j >= array_before.amount)
                    DEBUG_MSG("LOL"<<std::endl);
                if(array_before.array[j-1] > array_before.array[j])
                     std::swap(array_before.array[j-1], array_before.array[j]);
            }
        }
    }


    template <typename T>
    void selectionSort(SmartPtrArray<T>& array_before,int mode = 0b0)
    {
        auto k = 0;
        for( int i = 0; i < array_before.amount; i++ )
        {
            k = i;
            for(auto j = i + 1; j < array_before.amount; j++ )
            if( array_before.array[ j ] < array_before.array[ k ] )
                 k = j;
            std::swap(array_before.array[ k ], array_before.array[ i ]);
        }
    if(mode&reverseMode)
        reverse(array_before);
    }

    template <typename T>
    void insertionSort(SmartPtrArray<T>& array_before)
    {
        T tmp=0;
        auto j=0;
        for(auto i = 1; i < array_before.amount; i++)
        {
            tmp = array_before.array[ i ];
            for(j = i - 1; j >= 0 && array_before.array[j] > tmp; j--)
                 array_before.array[j + 1] = array_before.array[j];
            array_before.array[j + 1] = tmp;
        }
    }

    template <typename T>
    void shellSort(SmartPtrArray<T>& array_before, int mode = 0b0)
    {
        int h=0;
        int i=0;
        int j=0;
        T tmp;

        for(h = 1; h < array_before.amount; h = 3 * h + 1);
            h /= 9;
        if(h == 0)
            h++;
        while(h != 0)
        {
            for(j = array_before.amount-h-1; j >= 0; j--)
            {
                tmp = array_before.array[j];
                i = j + h;
                while((i < array_before.amount) && (tmp > array_before.array[i]))
                {
                    array_before.array[i - h] = array_before.array[i];
                    i += h;
                }
                array_before.array[i - h] = tmp;
            }
            h /= 3;
        }
    if(mode&reverseMode)
        reverse(array_before);
    }

    bool testRoutine()
    {
    {//MERGETEST1

        SmartPtrArray<float> array_a(5);
        SmartPtrArray<float> array_b(4);
        SmartPtrArray<float> result;
        array_a.array[0]=0.f;
        array_a.array[1]=1.f;
        array_a.array[2]=2.f;
        array_a.array[3]=3.f;
        array_a.array[4]=8.f;

        array_b.array[0]=1.f;
        array_b.array[1]=1.f;
        array_b.array[2]=4.f;
        array_b.array[3]=4.f;
        merge(array_a, array_b, result);
        if(
           result.amount != (5+4)   ||
           result.array[0] != 0.f   ||
           result.array[1] != 1.f   ||
           result.array[2] != 1.f   ||
           result.array[3] != 1.f   ||
           result.array[4] != 2.f   ||
           result.array[5] != 3.f   ||
           result.array[6] != 4.f   ||
           result.array[7] != 4.f   ||
           result.array[8] != 8.f         )
                return false;

    }
    {//MERGETEST2

        SmartPtrArray<int> array_a(5);
        SmartPtrArray<int> array_b(6);
        SmartPtrArray<int> result;
        array_a.array[0]=1;
        array_a.array[1]=4;
        array_a.array[2]=5;
        array_a.array[3]=8;
        array_a.array[4]=9;

        array_b.array[0]=1;
        array_b.array[1]=2;
        array_b.array[2]=3;
        array_b.array[3]=4;
        array_b.array[4]=5;
        array_b.array[5]=6;
        merge(array_a, array_b, result);
        if(
           result.amount != (5+6) ||
           result.array[0] != 1   ||
           result.array[1] != 1   ||
           result.array[2] != 2   ||
           result.array[3] != 3   ||
           result.array[4] != 4   ||
           result.array[5] != 4   ||
           result.array[6] != 5   ||
           result.array[7] != 5   ||
           result.array[8] != 6   ||
           result.array[9] != 8   ||
           result.array[10] != 9      )
                return false;

    }
    {//MERGETEST3

        SmartPtrArray<int> array_a(1);
        SmartPtrArray<int> array_b(1);
        SmartPtrArray<int> result;
        array_a.array[0]=2;
        array_b.array[0]=1;

        merge(array_a, array_b, result);
        if(
           result.amount != (2) ||
           result.array[0] != 1   ||
           result.array[1] != 2     )
                return false;

    }
    return true;
}

    template <typename T>
    void mergeSort(SmartPtrArrayIterrator<T> array_before, SmartPtrArray<T>& result)
    {
        SmartPtrArray<T> tmp_left;
        SmartPtrArray<T> tmp_right;
        if(array_before.amount!=1)
        {
            SmartPtrArrayIterrator<T> left(array_before, 0, array_before.amount/2);
            SmartPtrArrayIterrator<T> right(array_before, array_before.amount/2, array_before.amount);
            mergeSort(left, tmp_left);
            mergeSort(right, tmp_right);
            merge(tmp_left, tmp_right, result);
        }else
        {
            if(result.array!=nullptr)
                result.array.reset();
            SmartPtrArray<T> tmp(array_before.amount);
            result.amount=array_before.amount;
            tmp.array[0] = array_before.array[0];
            result.array=move(tmp.array);
        }

    }
    template <typename T>
    void mergeSort(SmartPtrArray<T>& array_before)
    {
        if(array_before.amount>1)
        {
            SmartPtrArray<T> result;
            SmartPtrArray<T> tmp_left;
            SmartPtrArray<T> tmp_right;
            SmartPtrArrayIterrator<T> left(array_before, 0, array_before.amount/2);
            SmartPtrArrayIterrator<T> right(array_before, array_before.amount/2, array_before.amount);
            mergeSort(left, tmp_left);
            mergeSort(right, tmp_right);

            merge(tmp_left, tmp_right, result);
            if(array_before.array!=nullptr)
                array_before.array.reset();
            array_before=result;
        }
    }
    template <typename T>
    void quickSort(SmartPtrArrayIterrator<T> array_before, SmartPtrArray<T>& result)
    {
        T pivot = array_before.array[0];
        if(array_before.amount>1){
            SmartPtrArray<T> array_after(array_before.amount);
            auto j = 0;
            auto k = array_before.amount-1;
            for(auto i = 0; i<array_before.amount; i++)
                if(array_before.array[i]<pivot)
                {
                    array_after.array[j]=array_before.array[i];
                    j++;
                }
                else
                {
                    array_after.array[k]=array_before.array[i];
                    k--;
                }
            array_after.amount=array_before.amount;
            SmartPtrArray<T> tmp_left;
            SmartPtrArray<T> tmp_right;
            SmartPtrArrayIterrator<T> left(array_after, 0, array_after.amount/2);
            SmartPtrArrayIterrator<T> right(array_after, array_after.amount/2, array_after.amount);
            quickSort(left, tmp_left);
            quickSort(right, tmp_right);
            merge(tmp_left, tmp_right, result);
        }else
        {
            if(result.array!=nullptr)
                result.array.reset();
            SmartPtrArray<T> tmp(1);
            result.array = move(tmp.array);
            result.amount = 1;
            result.array[0] = array_before.array[0];
        }

    }
    template <typename T>
    void quickSort(SmartPtrArray<T>& array_before)
    {
        T pivot = array_before.array[0];
        if(array_before.amount>1){
            SmartPtrArray<T> array_after(array_before.amount);
            auto j = 0;
            auto k = array_before.amount-1;
            for(auto i = 0; i<array_before.amount; i++)
                if(array_before.array[i]<pivot)
                {
                    array_after.array[j]=array_before.array[i];
                    j++;
                }
                else
                {
                    array_after.array[k]=array_before.array[i];
                    k--;
                }
            array_after.amount=array_before.amount;
            SmartPtrArray<T> tmp_left;
            SmartPtrArray<T> tmp_right;
            SmartPtrArrayIterrator<T> left(array_after, 0, j-1);
            SmartPtrArrayIterrator<T> right(array_after, j-1, array_after.amount);
            quickSort(left, tmp_left);
            quickSort(right, tmp_right);
            merge(tmp_left, tmp_right, array_after);
            if(array_before.array!=nullptr)
                array_before.array.reset();
            array_before=array_after;
        }
    }

}
#endif // SORTINGALGORITMS_H
