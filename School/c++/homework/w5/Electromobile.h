#include<iostream>
#include<string>

using namespace std;

class Date
{
    public:
        Date(int d, int m, int y);


    private:
        int d;
        int m;
        int y;

}


class Electromobile
{
    public:
        int getId();
        double getBat();
        Date getPreFix();
        string getLocation();

    private:
        int id;
        double bat;
        Date preFix;
        bool rented;
        bool needFix;
        string location;
}