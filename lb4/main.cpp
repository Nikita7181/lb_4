#include <iostream>
#include <vector>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

void swap(std::vector<int>& v, int x, int y)
{
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
    
}

void quicksort(std::vector<int> &vec, int L, int R)
{
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];
    
    while (i<R || j>L)
    {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;
        
        if (i <= j)
        {
            swap(vec, i, j);
            i++;
            j--;
        }
        else
            {
            if (i < R)
                quicksort(vec, i, R);
            if (j > L)
                quicksort(vec, L, j);
            return;
        }
    }
}

std::vector<int> insert_sort(std::vector<int> vector)
{
    for( int i=1; i<vector.size();++i)
    {
        for (int j=i; j>0 && vector[j-1]>vector[j];--j)
        {
            std::swap(vector[j - i], vector[j]);
        }
    }
    return vector;
}

std::vector<int> Fillarray(int size)
{
    std::vector<int> arr;
    std::srand(std::time(nullptr));
    for (int i = 0; i <= size; i++)
    {
        arr.push_back(std::rand() % 201 - 100);
    }
    return arr;
}

std::vector<int> SortMass(std::vector<int> vector)
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

int main ()
{
    int size;
    cout << "Task 1" << endl;
    cout << "size= " ;
    cin >> size;
    std::vector<int>b=Fillarray(size);
    for(int i : b)
    {
        cout << i << endl;
    }
    cout << "filter" << endl;
    std::vector<int >output = SortMass(b);
    for(int i : output)
    {
        cout << i << endl;
    }
    cout << "Task 2" << endl;
    cout << "size= ";
    cin >> size;
    std::vector<int> a = Fillarray(size);
    for(int i : a)
    {
        cout << i << endl;
    }
    cout << "filter" << endl;
    std::vector<int> output2 = insert_sort(a);
    for(int i : output2)
    {
        cout << i << endl;
    }
    cout << "Task 3" << endl;
    cout << "size= ";
    cin >> size;
    std::vector<int> vec1 = Fillarray(size);
    for(int i : vec1)
    {
        cout << i << endl;
    }
    cout << "filter" << endl;
    quicksort(vec1, 0, size - 1);
    for(int i : vec1)
    {
        cout << i << endl;
    }
    return 0;
}
