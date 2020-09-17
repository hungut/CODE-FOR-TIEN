#include "Human.h"

class Student : public Human
{
private:
   float grades;
   string id;
public:
    void setInfo();
    void getInfo();
    float getGrades();
    void setGrades(float grades);
    string getId();
    void setId(string id);
    Student();
    ~Student();
};

