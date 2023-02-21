#include <iostream>
#include <ctime>

using namespace std;

int** create_matrix(int row, int col);
void delete_matrix(int** matrix, int row);
void shift_matrix(int** matrix, int row, int col, int shift_move, int shift);

int main() {
	srand(time(0));
	int row, col, shift, shift_move;
	cout << "Enter row -->";
	cin >> row;
	cout << "Enter col -->";
	cin >> col;
	int** matrix{};
	matrix = create_matrix(row, col);
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "\n\n\n";
	}
	cout << "\nEnter shift -->";
	cin >> shift;
	cout << "\nEnter a side to shift[ 1 - up | 2 - down | 3 - left | 4 - right ] --> ";
	cin >> shift_move;
	cout << "\n\nRemastered\n";
	shift_matrix(matrix, row, col, shift_move, shift);
	delete_matrix(matrix, row);
}

/// <summary>
/// 
/// </summary>
/// <param name="row"></param>
/// <param name="col"></param>
/// <returns></returns>

int** create_matrix(int row, int col) {
	int** matrix = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
		for (size_t j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
	return matrix;
}

void delete_matrix(int** matrix, int row) {
	for (size_t i = 0; i < row; i++)
	{
		delete[i] matrix;
	}
	delete[] matrix;
}

void shift_matrix(int** matrix, int row, int col, int shift_move, int shift)
{
	int** new_matrix = create_matrix(row, col);
	switch (shift_move)
	{
	case 1: {
		for (int j = 0; j < row; j++)
		{
			for (int i = 0; i < col; i++)
			{
				if (shift + i - row < 0)
				{
					new_matrix[i][j] = matrix[i + shift][j];
				}
				else
				{
					new_matrix[i][j] = matrix[shift + i - row][j];
				}
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = new_matrix[i][j];
			}
		}
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << "\n\n\n";
		}
		delete_matrix(new_matrix, row);
	}break;
	case 2: {
		for (int j = 0; j < row; j++)
		{
			for (int i = 0; i < col; i++)
			{
				if (row - shift + i > row - 1)
				{
					new_matrix[i][j] = matrix[i - shift][j];
				}
				else
				{
					new_matrix[i][j] = matrix[row - shift + i][j];
				}
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = new_matrix[i][j];
			}
		}
		cout << "\n\nRemastered\n";
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << "\n\n\n";
		}
		delete_matrix(new_matrix, row);
	}break;
	case 3: {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if ((shift + j - col) < 0)
				{
					new_matrix[i][j] = matrix[i][j + shift];
				}
				else
				{
					new_matrix[i][j] = matrix[i][j + shift - col];
				}
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = new_matrix[i][j];
			}
		}
		cout << "\n\nRemastered\n";
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << "\n\n\n";
		}
		delete_matrix(matrix, row);
	}break;
	case 4: {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (col - shift + j > col - 1)
				{
					new_matrix[i][j] = matrix[i][j - shift];
				}
				else
				{
					new_matrix[i][j] = matrix[i][col - shift + j];
				}
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = new_matrix[i][j];
			}
		}
		cout << "\n\nRemastered\n";
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << "\n\n\n";
		}
		delete_matrix(matrix, row);
	}break;
	default:
		break;
	}
}