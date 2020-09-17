#include "Human.h"

class Doctor : public Human
{
private:
    string specialty;
    int exp_years;
public:
    void setInfo();
    void getInfo();
    string getSpecialty();
    void setSpecialty(string specialty);
    int getExp_years();
    void setExp_years(int exp_years);
    Doctor();
    ~Doctor();
};
