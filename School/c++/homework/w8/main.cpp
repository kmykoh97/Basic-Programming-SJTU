#include "header.h"

int main()
{
    int arr[6] = {1,2,3,4,5,6};

    List list(arr, 6);
    cout << list.length() << endl;
    list.print();
    cout << "------------------------" << endl;
    cout << list.insert(4,8) << endl;
    cout << list.insert(2,8) << endl;
    cout << list.length() << endl;
    list.print();
    cout << "------------------------" << endl;
    cout << list.find(2,8) << endl;
    cout << list.find(3,8) << endl;
    cout << list.find(6,8) << endl;
    cout << "------------------------" << endl;
    cout << list.remove(8) << endl;
    cout << list.length() << endl;
    list.print();
    cout << "------------------------" << endl;
    List list2;
    cout << list.split(1, list2) << endl;
    cout << list.length() << endl;
    list.print();
    cout << list2.length() << endl;
    list2.print();
    cout << "------------------------" << endl;
    list.combine(list2);
    cout << list2.length() << endl;
    list2.print();
    cout << list.length() << endl;
    list.print();

    system("pause");
    return 0;
}