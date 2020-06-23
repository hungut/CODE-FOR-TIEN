#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <vector>
using namespace std;
class Integer
{
private:
  int value;

public:
  //Integer(){};
  Integer(int _value);
  //
  int getValue(void);
  //
  void setValue(int _value);
};
Integer::Integer(int _value)
{
  this->value = _value;
}
int Integer::getValue(void)
{
  return value;
}
void Integer::setValue(int _value)
{
  value = _value;
}
void process(vector<Integer> integerVector)
{
  int numberOfElements = integerVector.size();
  int temp;
  int count = 1;
  while (count != 0)
  {
    count = 0;
    for (int i = 0; i < numberOfElements - 1; i++)
    {
      if (integerVector[i].getValue() > integerVector[i + 1].getValue())
      {
        count++;
        temp = integerVector[i].getValue();
        integerVector[i].setValue(integerVector[i + 1].getValue());
        integerVector[i + 1] = temp;
      }
    }
  }
  for (int i = 0; i < numberOfElements; i++)
  {
    cout << integerVector[i].getValue();
    if (i < numberOfElements - 1)
      cout << "; ";
  }
}
int main(int argc, char *argv[])
{
  //char* a={"abbc"};
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
    vector<Integer> integerVector;
    int temp;
    while (!fileIn.eof())
    {
      fileIn >> temp;
      integerVector.push_back(Integer(temp));
    }
    process(integerVector);
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
