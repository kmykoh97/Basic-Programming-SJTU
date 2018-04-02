#include<iostream>
#include<string>
#include<cctype> // use isalpha() and isdigit() for constructor

using namespace std;

class invalid{}; // exception

// enumeration for location
enum class Campus
{
    sjtu, fudan, tongji, easttech, eastnormal
};

class Electromobile
{
    public:
        // constructor
        Electromobile(string x, Campus y);

        // member methods
        string getId();
        string getBattery();
        string getPreFix();
        bool isRented(); // 0 is true, 1 is false
        bool isNeedFix(); // 0 is true, 1 is false
        string getLocation();
        void rent();
        void returnBack();
        void fix();

        // operators overloading
        bool operator== (Electromobile &obj);
        bool operator!= (Electromobile &obj);

    private:
        string id;
        int battery;
        string preFix;
        bool rented; // 0 is true, 1 is false
        bool needFix; // 0 is true, 1 is false
        Campus location;
};

// << overloading
ostream& operator<< (ostream& out, Electromobile &m);