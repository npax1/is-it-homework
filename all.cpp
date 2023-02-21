#include <iostream>
#include <ctime>

using namespace std;

void del_col(int**& array, int row, int& col, int col_pos)
{
    int** new_array = new int* [row];
    for (size_t i = 0; i < row; i++)
    {
        new_array[i] = new int[col - 1];
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col_pos - 1; j++)
        {
            new_array[i][j] = array[i][j];
        }
        for (size_t j = col_pos; j < col; j++)
        {
            new_array[i][j - 1] = array[i][j];
        }
    }
    col--;
    delete[] array;
    array = new_array;

    cout << "\n\nRemastered\n";
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << "\n\n\n";
    }
}

int main()
{
    srand(time(0));
    int row, col, col_pos;
    cout << "Enter row -> ";
    cin >> row;
    cout << "Enter col ->";
    cin >> col;

    int** array = new int* [row];
    for (size_t i = 0; i < row; i++)
    {
        array[i] = new int[col];
        for (size_t j = 0; j < col; j++)
        {
            array[i][j] = 1 + rand() % 9;
            cout << array[i][j] << "\t";
        }
        cout << "\n\n\n";
    }

    cout << "Enter pos ->";
    cin >> col_pos;

    del_col(array, row, col, col_pos);
    for (size_t i = 0; i < row; i++)
    {
        delete[i] array;
    }
    delete[] array;
}