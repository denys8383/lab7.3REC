#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        cout << setw(4) << a[rowNo][colNo];
        PrintRow(a, rowNo, colCount, colNo + 1);
    }
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo < rowCount)
    {
        PrintRow(a, rowNo, colCount, 0);
        PrintRows(a, rowCount, colCount, rowNo + 1);
    }
    else
        cout << endl;
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        cout << "a[" << rowNo << "][" << colNo << "] = ";
        cin >> a[rowNo][colNo];
        InputRow(a, rowNo, colCount, colNo + 1);
    }
    else
        cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo < rowCount)
    {
        InputRow(a, rowNo, colCount, 0);
        InputRows(a, rowCount, colCount, rowNo + 1);
    }
    else
        cout << endl;
}

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
    if (colNo < colCount)
    {
        a[rowNo][colNo] = Low + rand() % (High - Low + 1);
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
    }
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
    if (rowNo < rowCount)
    {
        CreateRow(a, rowNo, colCount, Low, High, 0);
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
    }
}

int Zero(int** a, const int rowCount, const int colCount, int colNo, int rowNo)
{
    if (colNo < colCount)
    {
        if (rowNo < rowCount)
        {
            if (a[rowNo][colNo] == 0)
                return Zero(a, rowCount, colCount, colNo, rowNo + 1);
            else
                return Zero(a, rowCount, colCount, colNo, rowNo + 1);
        }
        return Zero(a, rowCount, colCount, colNo + 1, 0);
    }
    return colNo;
}

int Zero(int** a, const int rowCount, const int colCount)
{
    return Zero(a, rowCount, colCount, 0, 0);
}

int SumPositiveElements(int* row, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        int sum = 0;
        if (row[colNo] > 0 && row[colNo] % 2 == 0)
        {
            sum = row[colNo];
        }
        return sum + SumPositiveElements(row, colCount, colNo + 1);
    }
    return 0;
}

int SumPositiveElements(int* row, const int colCount)
{
    return SumPositiveElements(row, colCount, 0);
}

void SortSum(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i < rowCount - 1)
    {
        if (j < rowCount - i - 1)
        {
            if (SumPositiveElements(a[j], colCount) < SumPositiveElements(a[j + 1], colCount))
            {
                int* tempRow = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tempRow;
            }
            SortSum(a, rowCount, colCount, i, j + 1);
        }
        else
            SortSum(a, rowCount, colCount, i + 1, 0);
    }
}

void SortSum(int** a, const int rowCount, const int colCount)
{
    SortSum(a, rowCount, colCount, 0, 0);
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    int Low = -5;
    int High = 55;
    int rowCount, colCount;
    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // CreateRows(a, rowCount, colCount, Low, High, 0);
    InputRows(a, rowCount, colCount, 0);
    PrintRows(a, rowCount, colCount, 0);
    int CountWithoutZero = Zero(a, rowCount, colCount);
    cout << "Stovpchi bez jodnogo 0 elementy: " << CountWithoutZero << endl;

    cout << endl;
    SortSum(a, rowCount, colCount);
    PrintRows(a, rowCount, colCount, 0);

    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        int sum = SumPositiveElements(a[i], colCount);
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << " Suma dodatnih parnih elementiv: " << sum << endl;
    }

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
