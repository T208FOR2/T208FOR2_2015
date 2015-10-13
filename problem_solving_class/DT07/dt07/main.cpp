#include <iostream>
#include <string>

using namespace std;

char** returnTable(int row, int col);
void printTable(char** Table, int row, int col);
void deleteTable(char** Table, int row, int col);
void makeMap(char** Table, int row, int col);

int main()
{
    int col, row;
    cin >> row;
    cin >> col;
    char** Table = returnTable(row, col);
    makeMap(Table, row, col);
    printTable(Table, row, col);
    deleteTable(Table, row, col);
    return 0;
}

void makeMap(char** Table, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            Table[i][j] = '.';
        }
    }
}


char** returnTable(int row, int col)
{
    char **Table;
    Table = new char*[row];

    for(int i = 0; i < row; i++)
    {
        Table[i] = new char[col];
    }
    return Table;
}



void printTable(char** Table, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << Table[i][j];
        }
        cout << endl;
    }
}
void deleteTable(char** Table, int row, int col)
{

    for(int i = 0; i < row; i++)
    {
        delete [] Table[i];
    }
    delete [] Table;
}
