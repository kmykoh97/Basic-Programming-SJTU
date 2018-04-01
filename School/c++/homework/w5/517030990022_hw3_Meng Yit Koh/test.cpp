# include "Electromobile.h"

int main()
{
    try {
    // car1 cout testing
    Electromobile car1{"aa-1234567", Campus::sjtu};
    cout << car1.getId() << endl;
    cout << car1.getBattery() << endl;
    cout << car1.isRented() << endl;
    cout << car1.isNeedFix() << endl;
    cout << car1.getLocation() << endl;
    car1.rent();
    car1.rent();
    car1.returnBack();
    car1.returnBack();
    car1.rent();
    cout << car1.isRented() << endl;
    cout << car1.isNeedFix() << endl;
    cout <<car1.getBattery() << "\n" << endl;
    car1.fix();
    car1.fix();

    // car2 display using << operator
    Electromobile car2{"ab-3232133", Campus::eastnormal};
    cout << car2 << endl;
    car2.rent();
    cout << car2 << endl;
    car2.returnBack();
    cout << car2 << endl;
    car2.fix();
    cout << car2 << endl;

    // operator overloading of != and ==
    Electromobile car5{"aa-1234567", Campus::fudan};
    if (car5 == car1) {
        cout << "same car!" << endl;
    } else {
        cout << "different car!" << endl;
    }

    if (car5 != car2) {
        cout << "different car!" << endl;
    } else {
        cout << "same car!" << endl;
    }

    // error display    
    Electromobile car3{"saasx", Campus::easttech};
    Electromobile car4{"1234567890", Campus::tongji};
    }

    // catching exception
    catch(invalid) {
        cout << "invalid id given!" << endl;
    }

    system("pause");
    return 0;
}