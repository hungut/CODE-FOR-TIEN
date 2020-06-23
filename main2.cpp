#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;
class Integer
{
    int value;

public:
    Integer() {}
    Integer(int giatri);
    operator int() const;
    Integer &operator=(int giatri);
    bool operator==(int giatri);
    Integer operator+(int giatri);
    bool operator<(Integer numberOfElements);
    bool operator>(Integer numberOfElements);
    friend ostream &operator<<(ostream &output, Integer &D);
};
Integer::Integer(int giatri)
{
    this->value = giatri;
}
Integer::operator int() const
{
    return value;
}
Integer &Integer::operator=(int giatri)
{
    this->value = giatri;
    return *this;
}
bool Integer::operator==(int giatri)
{
    if (value == giatri)
        return true;
    else
        return false;
}
Integer Integer::operator+(int giatri)
{
    this->value = this->value + giatri;
    return *this;
}
bool Integer::operator<(Integer numberOfElements)
{
    if (value < numberOfElements.value)
        return true;
    else
        return false;
}
bool Integer::operator>(Integer numberOfElements)
{
    if (value > numberOfElements.value)
        return true;
    else
        return false;
}
ostream &operator<<(ostream &output, Integer &D)
{
    output << D.value;
    return output;
}
Integer max(Integer *arr, Integer numberOfElements)
{
    if (arr == NULL || numberOfElements == 0)
        return Integer(-1);
    Integer max = arr[0];
    for (Integer i = 0; i < numberOfElements; i = i + 1)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main(int argc, char *argv[])
{
    // Section: read testcase
    ///Student may comment out this section for local testing
    if (argc < 2)
        return 0;
    ifstream fileIn;
    try
    {
        fileIn.open(argv[1]);
        if (fileIn.fail())
            throw "Failed to open file.";
        int numberOfElements;
        fileIn >> numberOfElements;
        Integer *arr = new Integer[numberOfElements];
        int temp;
        for (int i = 0; i < numberOfElements; i++)
        {
            fileIn >> temp;
            arr[i] = temp;
        }
        cout << max(arr, numberOfElements);
        delete[] arr;
        fileIn.close();
    }
    catch (const char *errMsg)
    {
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}