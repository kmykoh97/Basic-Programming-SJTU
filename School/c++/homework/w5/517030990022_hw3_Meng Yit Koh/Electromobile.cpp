#include"Electromobile.h"

using namespace std;

// constructor:

Electromobile::Electromobile(string x, Campus y)
{
    if (x.length() != 10) {
        cout << "Id is too short!" << endl;
        throw invalid{};
    }
    
    if (!isalpha(x[0]) && !isalpha(x[1]) && (x[2] != '-')) {
        cout << "wrong format of Id!" << endl;
        throw invalid{};
    } else {
        for (int i = 3; i < x.length(); i++) {
            if (!isdigit(x[i])) {
                cout << "wrong format of Id!" << endl;
                throw invalid{};
            }
        }
    }

    // initialisation
    id = x;
    battery = 97;
    rented = false;
    needFix = false;
    location = y;
}

// class methods:

// get vehicle identification
string Electromobile::getId()
{
    return id;
}

// get battery percentage in string format
string Electromobile::getBattery()
{
    string temp = to_string(battery); // convert battery level to string to prevent misuse

    return temp;
}

// get previous fix date
string Electromobile::getPreFix()
{
    return preFix;
}

// see if vehicle rented
bool Electromobile::isRented()
{
    return rented;
}

// see if vehicle needs fixing
bool Electromobile::isNeedFix()
{
    return needFix;
}

// return vehicle location
string Electromobile::getLocation()
{
    Campus c = location;

    switch(c) {
        case Campus::sjtu: return "Shanghai Jiao Tong University";
        case Campus::fudan: return "Fudan University";
        case Campus::tongji: return "Tongji University";
        case Campus::easttech: return "East Technology University";
        case Campus::eastnormal: return "East Normal University";
    }
}

// rent vehicle
void Electromobile::rent()
{
    // checks for several rent conditions
    if (rented) {
        cout << "already rented!" << endl;
        return;
    }

    if (needFix) {
        cout << "this vehicle is not functioning well!" << endl;
        return;
    }

    rented = true; // perform rent
}

// return vehicle
void Electromobile::returnBack()
{
    // checks if vehicle is rented
    if (!rented) {
        cout << "the vehicle is not rented!" << endl;
        return;
    }

    rented = false;
    needFix = true; // assume after return need fixing
    battery = battery - 5; // assume previous user only use 5 percent battery
}

// fix vehicle
void Electromobile::fix()
{
    if (!needFix) {
        cout << "this vehicle still in good condition!" << endl;
        return;
    }

    cout << "this vehicle is fixed!" << endl;
    battery = 100;
    needFix = false;
}

// operator overloading:

bool Electromobile::operator== (Electromobile &obj)
{
    if (this->id == obj.id) {
        return true;
    } else {
        return false;
    }
}

bool Electromobile::operator!= (Electromobile &obj)
{
    if (this->id != obj.id) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<< (ostream& out, Electromobile &m)
{
    out << "identity: " << m.getId() << endl;
    out << "battery level: " << m.getBattery() << endl;
    out << "rent status: " << m.isRented() << endl;
    out << "need fix: " << m.isNeedFix() << endl;
    out << "location near campus: " << m.getLocation() << endl;

    return out;
}