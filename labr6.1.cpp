#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

//рандом
void Mas(int c[], int i, int size, int Law, int High)
{ 
    if (i >= size)
    {
        return;
    }
    c[i] = rand() % (High - Law + 1) + Law;
    Mas(c, i + 1, size, Law, High);
}

//масив
void Print(int c[], int i, int size)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << c[i] << " ";
    Print(c, i + 1, size);
}


int Count(int c[], int i, int size)
{
    if (i >= size)
    {
        return 0;
    }
    if (!(c[i] % 2 == 0 || i % 13 == 0))
    {
        return 1 + Count(c, i + 1, size);
    }
    return Count(c, i + 1, size);
}

int Summ(int c[], int i, int size)
{
    if (i >= size)
    {
        return 0;
    }
    if (!(c[i] % 2 == 0 || i % 13 == 0))
    {
        return c[i] + Summ(c, i + 1, size);
    }
    return Summ(c, i + 1, size);
}

void Zero(int c[], int i, int size)
{
    if (i >= size)
    {
        return;
    }
    if (!(c[i] % 2 == 0 || i % 13 == 0))
    {
        c[i] = 0;
    }
    Zero(c, i + 1, size);
}

int main() {
    const int size = 21;
    const int High = 15;
    const int Law = 85;
    int c[size];

    srand(static_cast<unsigned>(time(0)));

    Mas(c, 0, size, High, Law);
    cout << "Origin Mas: ";
    Print(c, 0, size);

    int count = Count(c, 0, size);
    cout << "Count: " << count << endl;

    int sum = Summ(c, 0, size);
    cout << "Summ: " << sum << endl;

    Zero(c, 0, size);

    cout << "Modified Mas:  ";
    Print(c, 0, size);

    return 0;
}
