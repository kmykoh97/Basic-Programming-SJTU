#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<time.h>
#include<math.h>
#include <stdlib.h> 
#include <sstream>

using namespace std;

void getTotalAmount(vector <string>& result)
{
    string temp1 = result[5];
    string temp2 = result[2];
    double x;
    stringstream sval(temp1);
    sval >> x;
    double y;
    stringstream fval(temp2);
    fval >> y;

    double total = x * y;
    result[6] = to_string(total);
}

void arrangeGood(string temp, vector <string>& result)
{
    size_t index_holder = temp.find("good_name:");
    for (size_t i = temp.find("good_name:"); i < temp.size(); ++i) {
        if (temp[i] == '\t') {
            result[4] = temp.substr(index_holder + 10, i - index_holder - 10); // good_name
            break;
        }
    }

    index_holder = temp.find("price:");
    for (size_t i = temp.find("price:"); i < temp.size(); ++i) {
        if (temp[i] == '\t') {
            result[5] = temp.substr(index_holder + 6, i - index_holder - 6); // price
            break;
        }
    }
}

void goodDetail(string temp, vector<string>& result, ifstream& good1, ifstream& good2, ifstream& good3)
{
    while (getline(good1, temp)) {
        if (temp.substr(8, 20) == result[1]) {
            arrangeGood(temp, result);
            return;
        }
    }

    while (getline(good2, temp)) {
        if (temp.substr(8, 20) == result[1]) {
            arrangeGood(temp, result);
            return;
        }
    }

    while (getline(good3, temp)) {
        if (temp.substr(8, 20) == result[1]) {
            arrangeGood(temp, result);
            return;
        }
    }
}

void getBuyerName(string temp, vector<string>& result)
{
    size_t index_holder = temp.find("buyername:");
    for (size_t i = temp.find("buyername:"); i < temp.size(); ++i) {
        if (temp[i] == '\t') {
            result[3] = temp.substr(index_holder + 10, i - index_holder - 10); // buyername
            break;
        }
    }
}

void buyerDetail(string temp, vector<string>& result, ifstream& buyer1, ifstream& buyer2)
{
    while (getline(buyer1, temp)) {
        if (temp.substr(8, 20) == result[0]) {
            getBuyerName(temp, result);
            return;
        }
    }

    while (getline(buyer2, temp)) {
        if (temp.substr(8, 20) == result[0]) {
            getBuyerName(temp, result);
            return;
        }
    }
}

void arrangeOrder(string temp, vector <string>& result)
{
    size_t index_holder = temp.find("buyerid:");
    for (size_t i = temp.find("buyerid:"); i < temp.size(); ++i) {
        if (temp[i] == '\t') {
            result[0] = temp.substr(index_holder + 8, i - index_holder - 8); // buyerid
            break;
        }
    }

    index_holder = temp.find("goodid:");
    for (size_t i = temp.find("goodid:"); i < temp.size(); ++i) {
        if (temp[i] == '\t') {
            result[1] = temp.substr(index_holder + 7, i - index_holder - 7); // goodid
            break;
        }
    }

    index_holder = temp.find("amount:");
    for (size_t i = temp.find("amount:"); i < temp.size(); ++i) {
        if (temp[i] == '\t') {
            result[2] = temp.substr(index_holder + 7, i - index_holder - 7); // amount
            break;
        }
    }
}

void orderDetail(string orderIdPrompt, string temp, vector<string>& result, ifstream& order1, ifstream& order2, ifstream& order3, ifstream& order4)
{
    while (getline(order1, temp)) {
        if (temp.substr(8, 9) == orderIdPrompt) {
            arrangeOrder(temp, result);
            return;
        }
    }

    while (getline(order2, temp)) {
        if (temp.substr(8, 9) == orderIdPrompt) {
            arrangeOrder(temp, result);
            return;
        }
    }

    while (getline(order3, temp)) {
        if (temp.substr(8, 9) == orderIdPrompt) {
            arrangeOrder(temp, result);
            return;
        }
    }

    while (getline(order4, temp)) {
        if (temp.substr(8, 9) == orderIdPrompt) {
            arrangeOrder(temp, result);
            return;
        }
    }
}

void orderNumber()
{
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    ifstream readFile1, readFile2, readFile3, readFile4;
    string line;
    int noOfLines = 0;

    readFile1.open("C:\\Users\\kmyko\\Desktop\\data\\order.0.0");
    readFile2.open("C:\\Users\\kmyko\\Desktop\\data\\order.0.3");
    readFile3.open("C:\\Users\\kmyko\\Desktop\\data\\order.1.1");
    readFile4.open("C:\\Users\\kmyko\\Desktop\\data\\order.2.2");

    while (getline(readFile1, line)) {
        ++noOfLines;
    }

    while (getline(readFile2, line)) {
        ++noOfLines;
    }

    while (getline(readFile3, line)) {
        ++noOfLines;
    }

    while (getline(readFile4, line)) {
        ++noOfLines;
    }

    cout << noOfLines << endl;
    

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << time_spent << endl;
}

int main()
{
    orderNumber();

    string orderIdPrompt;
    cout << "please enter order id: ";
    cin >> orderIdPrompt;
    cout << endl;

    vector <string> result(7);
    string temp;
    ifstream order1; ifstream order2; ifstream order3; ifstream order4; ifstream buyer1; ifstream buyer2; ifstream good1; ifstream good2; ifstream good3;

    order1.open("C:\\Users\\kmyko\\Desktop\\data\\order.0.0");
    order2.open("C:\\Users\\kmyko\\Desktop\\data\\order.0.3");
    order3.open("C:\\Users\\kmyko\\Desktop\\data\\order.1.1");
    order4.open("C:\\Users\\kmyko\\Desktop\\data\\order.2.2");

    buyer1.open("C:\\Users\\kmyko\\Desktop\\data\\buyer.0.0");
    buyer2.open("C:\\Users\\kmyko\\Desktop\\data\\buyer.1.1");

    good1.open("C:\\Users\\kmyko\\Desktop\\data\\good.0.0");
    good2.open("C:\\Users\\kmyko\\Desktop\\data\\good.1.1");
    good3.open("C:\\Users\\kmyko\\Desktop\\data\\good.2.2");

    orderDetail(orderIdPrompt, temp, result, order1, order2, order3, order4);
    buyerDetail(temp, result, buyer1, buyer2);
    goodDetail(temp, result, good1, good2, good3);
    getTotalAmount(result);

    cout << result[0] << endl;
    cout << result[1] << endl;
    cout << result[2] << endl;
    cout << result[3] << endl;
    cout << result[4] << endl;
    cout << result[5] << endl;
    cout << result[6] << endl;

    order1.close(); order2.close(); order3.close(); order4.close(); buyer1.close(); buyer2.close(); good1.close(); good2.close(); good3.close();

    system("pause");
    return 0;
}