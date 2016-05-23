#ifndef SMARTPTRARRAY_H
#define SMARTPTRARRAY_H
#include<memory>

template <typename T>
struct SmartPtrArray
{
    int amount;
    std::unique_ptr<T[]> array;
    SmartPtrArray(){}
    SmartPtrArray(int i): array(new T[i]), amount(i){}
    void init(int i)
    {
        if(array==nullptr)
        {
            array=move(std::unique_ptr<T[]>(new T[i]));
            amount = i;
        }else
            std::cerr<<"Pamiec juz zaalokowana,  wystapil blad"<<std::endl;
    }
    SmartPtrArray operator = (SmartPtrArray& compared)
    {
        if(compared.array!=nullptr)
        {
            if(array)
                array.reset();
            array=move(std::unique_ptr<T[]>(new T[compared.amount]));
            amount = compared.amount;
            for(auto i=0; i<amount; i++)
                array[i]=compared.array[i];
        }else
        {
            if(array)
                array.reset();
            amount=0;
        }
    }

};
template <typename T>
struct SmartPtrArrayIterrator
{
    SmartPtrArrayIterrator(SmartPtrArray<T>& smart_array, int start, int end):
        array(&(smart_array.array[start])),
        amount(end-start){}
    SmartPtrArrayIterrator(SmartPtrArrayIterrator<T> array_in, int start, int end):
        array(&(array_in.array[start])),
        amount(end-start){}
    int amount;
    T* array;
};

#endif // SMARTPTRARRAY_H
