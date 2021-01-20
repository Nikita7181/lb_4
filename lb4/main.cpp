#include <iostream>
#include <vector>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

int Partition (std::vector <int> &vec, int start, int end) //принимает часть массива и относительно опорной функции переноси меньгие влево а большие вправо
{
    int value = vec[end];
    int position = start;
    
    for(int i = start; i < end; i++)
    {
        if (vec[i] <= value)
        {
            int temp = vec[i];
            vec[i] = vec[position];
            vec[position] = temp;
            position++;
        }
    }
    vec[end] = vec[position];
    vec[position] = value;
    return position;
}

void quicksort(std::vector<int> &vec, int start, int end)
{
    if(start > end)
    {
        return;
    }
    int pivot = Partition(vec, start, end);
    quicksort(vec, start, pivot-1);
    quicksort(vec, pivot + 1, end);
}

std::vector<int> Insertion_Sort(std::vector<int> vector)
{
    for( int i=1; i<vector.size();++i)
    {
        for (int j=i; j>0 && vector[j-1]>vector[j];--j)
        {
            std::swap(vector[j-1],vector[j]);
        }
    }
    return vector;
}

std::vector<int> Fillarray(int size)
{
    std::vector<int> arr;
    std::srand(std::time(nullptr));
    for (int i = 1; i <= size; i++)
    {
        arr.push_back(std::rand() % 201 - 100);
    }
    return arr;
}

std::vector<int> Bubble_Sort(std::vector<int> vector)
{
    bool h = true;
    while (h)
    {
        h = false;
        for (int i = 0; i < vector.size() - 1; ++i)
        {
            if (vector[i] > vector[i + 1])
            {
                h = true;
                std::swap(vector[i], vector[i + 1]);
            }
        }
    }
    return vector;
}

void Print(std::vector<int> vector)
{
    for (int i : vector)
    {
        cout << i << endl;
    }
}

int main ()
{
    int size;
    cout << "Task 1" << endl;
    cout << "size= ";
    cin >> size;
    std::vector<int>vec1=Fillarray(size);
    Print(vec1);
    cout << "filter" << endl;
    vec1 = Bubble_Sort (vec1);
    Print (vec1);
    cout << "Task 2" << endl;
    cout << "size= ";
    cin >> size;
    std::vector<int> vec2 =Fillarray(size);
    Print (vec2);
    cout << "filter" << endl;
    vec2 = Insertion_Sort(vec2);
    Print (vec2);
    cout << "Task 3" << endl;
    cout << "size= ";
    cin >> size;
    std::vector<int> vec3 = Fillarray(size);
    Print (vec3);
    cout << "filter" << endl;
    quicksort(vec3, 0, size-1);
    Print (vec3);
    return 0;
}
