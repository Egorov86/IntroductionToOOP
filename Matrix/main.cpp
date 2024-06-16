//Matrix
#include <iostream>
using namespace std;

#define delimitr "\t-------------------------\t"

class Matrix
{
	int rows;  // количество строк
	int cols;  // количество столбцов
	int** data;  // двум. массив для хранения данных матрицы
public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	const int** get_data()const
	{
		return data;
	}
	int** get_data()
	{
		return data;
	}
	void set_rows(int rows)
	{
		this->rows = rows;
	}
	void set_cols(int cols)
	{
		this->cols = cols;
	}
	            // Constructor
	Matrix(int rows = 2, int cols = 2)    // Конструктор с параметрами
	{
		data = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				data[i] = new int[cols];
			}
			cout << "Constructor: " << this << endl;
	}

	/*Matrix(const Matrix& other) // Конструктор копирования
	{
		data = new int*[rows]
			for (int i = 0; i < rows; i++)
			{
				data[i] = new int[cols];
				for (int j = 0; j < cols; j++)
				{
					data[i][j] = other.data[i][j];
				}
			}
	}*/


};

std::ostream& operator<<(std::ostream& os, const Matrix& obj)
{
    int rows = obj.get_rows();
	int cols = obj.get_cols();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			{
				os << obj.data[i][j] << "\t";
			}
			os << "\n";
		}
	}
	return os;
}

void main()
{
	setlocale(LC_ALL, "rus");

	Matrix matrix1(2, 3);

	cout << matrix1 << endl;


}