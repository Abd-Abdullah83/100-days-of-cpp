#include <iostream>
using namespace std;
bool checkPalindrome(int* p, int n)
{
    for (int i = 0; i < n / 2; i++)
        if (p[i] != p[n - i - 1])
            return false;
    return true;
}

bool checkPalindrome(char* p, int n)
{
    for (int i = 0; i < n / 2; i++)
        if (p[i] != p[n - i - 1])
            return false;
    return true;
}

bool checkPalindrome(char** p, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
        {
            if (p[i][j] != p[i][n - j - 1]) return false;
            if (p[j][i] != p[n - j - 1][i]) return false;
        }
    for (int i = 0; i < n / 2; i++)
    {
        if (p[i][i] != p[n - i - 1][n - i - 1]) return false;
        if (p[i][n - i - 1] != p[n - i - 1][i]) return false;
    }
    return true;
}

bool checkPalindrome(int** p, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
        {
            if (p[i][j] != p[i][n - j - 1]) return false;
            if (p[j][i] != p[n - j - 1][i]) return false;
        }
    for (int i = 0; i < n / 2; i++)
    {
        if (p[i][i] != p[n - i - 1][n - i - 1]) return false;
        if (p[i][n - i - 1] != p[n - i - 1][i]) return false;
    }
    return true;
}


void print1D(int* p, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << p[i] << (i < n - 1 ? ", " : " ");
    cout << "]" << endl;
}

void print1D(char* p, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << p[i] << (i < n - 1 ? ", " : " ");
    cout << "]" << endl;
}


void print2D(int** p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[ ";
        for (int j = 0; j < n; j++)
            cout << p[i][j] << (j < n - 1 ? ", " : " ");
        cout << "]" << endl;
    }
}

void print2D(char** p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[ ";
        for (int j = 0; j < n; j++)
            cout << p[i][j] << (j < n - 1 ? ", " : " ");
        cout << "]" << endl;
    }
}


int** allocate2D(int n)
{
    int** p = new int* [n];
    for (int i = 0; i < n; i++)
        p[i] = new int[n];
    return p;
}

char** allocate2DChar(int n)
{
    char** p = new char* [n];
    for (int i = 0; i < n; i++)
        p[i] = new char[n];
    return p;
}

void free2D(int** p, int n)
{
    for (int i = 0; i < n; i++)
        delete[] p[i];
    delete[] p;
}

void free2DChar(char** p, int n)
{
    for (int i = 0; i < n; i++)
        delete[] p[i];
    delete[] p;
}


int main()
{
    cout << "=============================" << endl;
    cout << "  1D Integer Array Tests" << endl;
    cout << "=============================" << endl;
    int arr1[] = { 1, 2, 3, 2, 1 }; 
    int arr2[] = { 1, 2, 3, 4, 5 };  
    cout << "Array: "; print1D(arr1, 5);
    cout << "Palindrome: " << (checkPalindrome(arr1, 5) ? "YES" : "NO") << endl;
    cout << "Array: "; print1D(arr2, 5);
    cout << "Palindrome: " << (checkPalindrome(arr2, 5) ? "YES" : "NO") << endl;
    cout << endl;
    cout << "=============================" << endl;
    cout << "  1D Character Array Tests" << endl;
    cout << "=============================" << endl;
    char ch1[] = { 'r', 'a', 'c', 'e', 'c', 'a', 'r' };  
    char ch2[] = { 'h', 'e', 'l', 'l', 'o' };              
    cout << "Array: "; print1D(ch1, 7);
    cout << "Palindrome: " << (checkPalindrome(ch1, 7) ? "YES" : "NO") << endl;
    cout << "Array: "; print1D(ch2, 5);
    cout << "Palindrome: " << (checkPalindrome(ch2, 5) ? "YES" : "NO") << endl;

    cout << endl;
    cout << "=============================" << endl;
    cout << "  2D Integer Matrix Tests" << endl;
    cout << "=============================" << endl;

    int** mat1 = allocate2D(3);
    int v1[3][3] = { {1, 2, 1},
                     {2, 5, 2},
                     {1, 2, 1} };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat1[i][j] = v1[i][j];

    int** mat2 = allocate2D(3);
    int v2[3][3] = { {1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9} };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat2[i][j] = v2[i][j];

    cout << "Matrix 1:" << endl; print2D(mat1, 3);
    cout << "Palindrome: " << (checkPalindrome(mat1, 3) ? "YES" : "NO") << endl;

    cout << "Matrix 2:" << endl; print2D(mat2, 3);
    cout << "Palindrome: " << (checkPalindrome(mat2, 3) ? "YES" : "NO") << endl;

    free2D(mat1, 3);
    free2D(mat2, 3);

    cout << endl;
    cout << "=============================" << endl;
    cout << "  2D Character Matrix Tests" << endl;
    cout << "=============================" << endl;

    char** cmat1 = allocate2DChar(3);
    char cv1[3][3] = { {'a', 'b', 'a'},
                       {'b', 'z', 'b'},
                       {'a', 'b', 'a'} };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cmat1[i][j] = cv1[i][j];


    char** cmat2 = allocate2DChar(3);
    char cv2[3][3] = { {'a', 'b', 'c'},
                       {'d', 'e', 'f'},
                       {'g', 'h', 'i'} };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cmat2[i][j] = cv2[i][j];

    cout << "Matrix 1:" << endl; print2D(cmat1, 3);
    cout << "Palindrome: " << (checkPalindrome(cmat1, 3) ? "YES" : "NO") << endl;

    cout << "Matrix 2:" << endl; print2D(cmat2, 3);
    cout << "Palindrome: " << (checkPalindrome(cmat2, 3) ? "YES" : "NO") << endl;

    free2DChar(cmat1, 3);
    free2DChar(cmat2, 3);

    return 0;
}
