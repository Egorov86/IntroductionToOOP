//Matrix
#include <iostream>
using namespace std;

class Matrix
{
    int rows;
    int cols;
    int** arr;
public:
    int get_rows() const
    {
        return rows;
    }
    int get_cols() const
    { 
        return cols;
    }
    int get_arr(int rows, int cols) const 
    { 
        return arr[rows][cols]; 
    }
    void set_arr(int rows, int cols, int data) 
    { 
        arr[rows][cols] = data; 
    }
    Matrix()
    {
        this->rows = 0;
        this->cols = 0;
        this->arr = 0;
        cout << " Конcтруктор по умолчанию: " << this << "\n";
    }
    Matrix(int rows, int cols):rows(rows), cols(cols), arr(new int* [rows])
    {
        //this->rows = rows;
        //this->cols = cols;
        //this->arr = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols] {};
        }
        cout << "Конcтруктор с параметрами: " << this << "\n";
    }
    Matrix(const Matrix& obj) :Matrix(obj.rows, obj.cols)
    {
        //this->rows = obj.rows;
        //this->cols = obj.cols;
        //this->arr = new int* [rows];
        /*for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols] {};
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = obj.arr[i][j];
            }
        }*/
        cout << "Конcтруктор копирования: " << this << "\n";
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++)
        {
            delete[]arr[i];
        }
        delete[]arr;
        cout << "Деструктор: " << this << "\n";
    };

                                // Операторы
    Matrix& operator =(const Matrix& obj)
    {
        if (this == &obj) return *this;
        for (int i = 0; i < rows; i++)
        {
            for (int i = 0; i < this->rows; i++)delete[]arr[i]; 
               delete[]arr;
        }
        this->rows = obj.rows;
        this->cols = obj.cols;
        arr = new int* [rows];
        for (int i = 0; i < rows; i++)arr[i] = new int[cols];
        for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)arr[i][j] = obj.arr[i][j];
    return *this;
    }
      
                                   // Методы
    void print()
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << this->arr[i][j] << " \t "; 
            }
            cout << endl;
        }
        cout << endl;
    }
                                   // Заполнение completion
    void completion()
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                arr[i][j] = rand() % 50;
            }
        }
        cout << "Заполнение случайными числами: " << this << "\n";
    }
};

Matrix operator+ (const Matrix& left, const Matrix& right)
{
    Matrix temp(left.get_rows(), left.get_cols());
    if (left.get_rows() != right.get_rows() && left.get_cols() != right.get_cols())
    {
        cout << "Это разные матрицы  и их нельзя сложить \n";
    }
    else
    {
        for (int i = 0; i < temp.get_rows(); i++) {
            for (int j = 0; j < temp.get_cols(); j++)
            {
                temp.set_arr(i, j, left.get_arr(i, j) + right.get_arr(i, j));
            }
        }
    }
    return temp;
}
Matrix operator- (const Matrix& left, const Matrix& right)
{
    Matrix temp(left.get_rows(), left.get_cols());
    if (left.get_rows() != right.get_rows() && left.get_cols() != right.get_cols())
    {
        cout << "Это разные матрицы  и их нельзя вычетать \n";
    }
    else
    {
        for (int i = 0; i < temp.get_rows(); i++) {
            for (int j = 0; j < temp.get_cols(); j++)
            {
                temp.set_arr(i, j, left.get_arr(i, j) - right.get_arr(i, j));
            }
        }
    }
    return temp;
}
Matrix operator* (const Matrix& left, const Matrix& right)
{
    Matrix temp(left.get_rows(), right.get_cols());
    if (left.get_rows() != right.get_cols() && left.get_cols() != right.get_rows())
    {
        cout << "Эти матрицы несовпадают: \n";
    }
    else
    {
        for (int i = 0; i < temp.get_rows(); i++)
        {
            for (int j = 0; j < right.get_rows(); j++)
            {
                for (int l = 0; l < temp.get_cols(); l++)
                {
                    temp.set_arr(i, j, temp.get_arr(i, j) + left.get_arr(i, l) * right.get_arr(l, j));
                }
            }
        }
    }
    return temp;
}


void main()
{
    setlocale(LC_ALL, "Rus");

    Matrix matrix1(3, 3);               // создание matrix1
    matrix1.print();                    // вывод matrix1
    matrix1.completion();               // заполнение 
    matrix1.print();                    // вывод matrix1
    Matrix matrix2(3, 3);               // создание matrix2
    matrix2.completion();               // заполнение
    matrix2.print();                    // вывод matrix2
    Matrix matrix3 = matrix1 + matrix2; // сложение
    matrix3.print();
    Matrix matrix4 = matrix1 - matrix2; // вычитание
    matrix4.print();
    Matrix matrix5 = matrix1 * matrix2; // умножение
    matrix5.print();
}