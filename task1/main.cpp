/*
    Условие:
    На вход подаётся имя файла, в котором построчно записаны три значения и двумерный массив
    p1 - порог площади для первого типа цели
    p2 - порог площади для второго типа цели
    n - размер массива
    a[nxn] - массив из 0 и 1
*/
#include <iostream> // For debugging
#include <fstream> // For FIO
#include <string.h> // For memcpy

using namespace std;

struct field
{
    int p1;
    int p2;
    int n;
    bool** array;

    void print()
    {
        cout << "p1" << this->p1 << endl
            << "p2" << this->p2 << endl
            << "n" << this->n << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << this->array[i][j];
            }
            cout << endl;
        }
    }

    void free()
    {
        for (int i = 0; i < this->n; i++) {
            delete [] this->array[i];
        }
        delete [] this->array;

        this->p1 = 0;
        this->p2 = 0;
        this->n = 0;
    }
};


int main(int args, char* argv[])
{
    if(args < 2)
    {
        cerr << "Bad arguments count" << endl;
        return 1;
    }

    ifstream input_file(argv[1]);
    if(!input_file.good())
    {
        cerr << "Bad input file" << endl;
        return 1;
    }

    field main_field;

    if (input_file.is_open())
    {
        string line;
        int number_line = 0;
        int n = 0;
        while ( getline (input_file, line) )
        {
            if(number_line == 0)
            {
                main_field.p1 = stoi(line.data());
                // cout << number_line << " : " << main_field.p1;
            } 
            else if (number_line == 1)
            {
                main_field.p2 = stoi(line.data());
                // cout << number_line << " : " << main_field.p2;
            }
            else if( number_line == 2)
            {
                main_field.n = stoi(line.data());
                n = main_field.n;
                // cout << number_line << " : " << main_field.n;
                main_field.array = new bool*[main_field.n];
                for(int i = 0; i < main_field.n; i++)
                {
                    main_field.array[i] = new bool[main_field.n];
                }
            }
            else if( number_line > 2 && number_line <= (main_field.n + 3))
            {
                // cout << n-- << endl;
                memcpy(main_field.array[number_line - 3], line.data(), main_field.n);
            }
            else
            {
                main_field.print();
                main_field.free();
                cerr << "Bad file construction" << endl;
                return 1;
            }
            
            number_line++;
            // cout << line << '\n';
        }
            input_file.close();
    }

    main_field.print();

    cin.get();

    main_field.free();

    return 0;
}
 