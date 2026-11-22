#include <iostream>
#include <cstdlib>
#include <Windows.h>

// функции
void create_array(int*& ptr, int size);
void fill_array(int* ptr, int size);
void print_array(int* ptr, int size);
void delete_array(int*& ptr);
void add_element(int*& ptr, int& size, int element);
void insert_element(int*& ptr, int& size, int element, int index);
void delete_element(int*& ptr, int& size, int index);

int main()
{
    // для рус текста
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int size = 5;
    int* ptr = nullptr;

    create_array(ptr, size);
    fill_array(ptr, size);

    std::cout << "Исходный массив: ";
    print_array(ptr, size);

    add_element(ptr, size, 50);
    std::cout << "После добавл-ия: ";
    print_array(ptr, size);

    insert_element(ptr, size, 99, 2);
    std::cout << "После вставки: ";
    print_array(ptr, size);

    delete_element(ptr, size, 3);
    std::cout << "После удаления: ";
    print_array(ptr, size);

    delete_array(ptr);

    return 0;
}

// память под массив
void create_array(int*& ptr, int size)
{
    ptr = new int[size];
}

// случайные числа
void fill_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 100;
    }
}

// вывод элементов массива
void print_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << "\n";
}

// чистка памяти
void delete_array(int*& ptr)
{
    delete[] ptr;
    ptr = nullptr;
}

void add_element(int*& ptr, int& size, int element)
{
    int* temp = new int[size + 1];

    // копирую старые элементы
    for (int i = 0; i < size; i++)
    {
        temp[i] = ptr[i];
    }

    temp[size] = element;

    delete[] ptr;
    ptr = temp;
    size++;
}

void insert_element(int*& ptr, int& size, int element, int index)
{
    if (index < 0 || index > size)
    {
        std::cout << "Неверный индекс\n";
        return;
    }

    int* temp = new int[size + 1];

    for (int i = 0; i < index; i++)
    {
        temp[i] = ptr[i];
    }

    temp[index] = element;

    for (int i = index; i < size; i++)
    {
        temp[i + 1] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
    size++;
}

void delete_element(int*& ptr, int& size, int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Неверный индекс\n";
        return;
    }

    if (size == 1)
    {
        delete[] ptr;
        ptr = nullptr;
        size = 0;
        return;
    }

    int* temp = new int[size - 1];

    for (int i = 0; i < index; i++)
    {
        temp[i] = ptr[i];
    }

    for (int i = index + 1; i < size; i++)
    {
        temp[i - 1] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
    size--;
}
