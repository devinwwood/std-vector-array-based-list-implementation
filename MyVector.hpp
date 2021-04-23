// Programmer: Devin Wood
// Date: 04/04/2021
// File: MyVector.hpp
// Purpose: This file contains the function definitions for MyVector.h.


void get_identity(string &my_id)
{
    my_id = "dwwdtv";
}


template<typename T>
MyVector<T>::MyVector()
{
    reserved_size = 0;
    data_size = 0;
    m_data = new T[reserved_size];
}


template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}


template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &source)
{
   reserved_size = source.reserved_size;
   data_size = source.data_size;

   delete[] m_data;

   if(data_size)
   {
       m_data = new T[reserved_size];

       for(int i = 0; i < data_size; i++)
           m_data[i] = source.m_data[i];
   }

   return *this;
}


template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
   reserved_size = source.reserved_size;
   data_size = source.data_size;

   m_data = new T[reserved_size];
   
   if(data_size)
   {
       for(int i = 0; i < data_size; i++)
           m_data[i] = source.m_data[i];
   }
}


template <typename T>
T& MyVector<T>::operator[](int i)
{
   return m_data[i]; 
}


template <typename T>
T & MyVector<T>::at(int index)
{
    if(index >= data_size || index < 0)
        throw std::out_of_range("blah");      
   
    else
        return m_data[index];

}

template <typename T>
T& MyVector<T>::front()
{
    return m_data[0];
}

template <typename T>
T& MyVector<T>::back()
{
    return m_data[data_size - 1];
}


template <typename T>
int MyVector<T>::capacity()
{
    return reserved_size;
}


template <typename T>
int MyVector<T>::size()
{
    return data_size;
}


template <typename T>
void MyVector<T>::reserve(int new_cap)
{
    if(new_cap == 0)
    {
        reserved_size = 1;

        T* new_data = new T[reserved_size];

        delete[] m_data;
        m_data = new_data;

    }     

    else if(new_cap > reserved_size)
    {
        reserved_size = new_cap;
        T* new_data = new T[reserved_size];

        for(int i = 0; i < data_size; i++)
            new_data[i] = m_data[i];
       
        delete[] m_data; 
        m_data = new_data;
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    reserved_size = 2 * data_size;
    T* new_data = new T[reserved_size];

    for(int i = 0; i < data_size; i++)
        new_data[i] = m_data[i];

    delete[] m_data;
    m_data = new_data;
}

template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
    data_size = count;
    reserved_size = count;

    delete[] m_data;
    m_data = new T[reserved_size];

    for(int i = 0; i < reserved_size; i++)
        m_data[i] = value;    
}

template <typename T>
void MyVector<T>::clear()
{
    data_size = 0;
    reserved_size = 0;
    delete[] m_data;
    m_data = new T[reserved_size];
}


template <typename T>
void MyVector<T>::push_back(const T &x)
{
    if(data_size == reserved_size)
        reserve(reserved_size * 2);
    
    m_data[data_size] = x;
    data_size++;

    if((data_size * 4) < reserved_size)
        shrink_to_fit();
}


template <typename T>
void MyVector<T>::pop_back()
{
    if(data_size > 0)
        data_size--;

    else
        data_size = 0;

    if((data_size * 4) < reserved_size)
        shrink_to_fit();
}
   

template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
    if(data_size >= reserved_size)
        reserve(reserved_size * 2);
    
    if((i != 0 && data_size == 0) || (i > data_size && data_size != 0) || i < 0)
        throw std::out_of_range(0);

    for(int j = data_size; j > i; j--)
        m_data[j] = m_data[j - 1];   

    data_size++;
    m_data[i] = x;
} 


template <typename T>
void MyVector<T>::erase(int i)
{
    if(i >= data_size || i < 0)
        throw std::out_of_range(0);

    for(int j = i; j < data_size - 1; j++)
        m_data[j] = m_data[j + 1];

    data_size--;

    if((data_size * 4) < reserved_size)
        shrink_to_fit();
}


template <typename T>
void swap(T& a, T& b)
{
    T c = b;
    b = a;
    a = c;
}
