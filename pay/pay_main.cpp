/*
 * This GOING DUTCH programm calculates average cost and give a solution
 * to giving and receiving money.
 * To compile it, run commandline: g++ -o pay pay_main.cpp -std=c++14 -Wall
 * To run the executable file, you can use commandline argument like ./pay 5
 * in which 5 represents the number of persons who share the cost.
 * Alternatve you can run it without commandline like ./pay
 * then you will be required to enter the number of persons later through std::cin
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include "pay.h"

static int num = 0;
static double sum = 0.0;
static double average = 0.0;
static bool paidGreater(Member m1, Member m2);

int main(int argc, char const *argv[]) {
    using namespace std;
    if (argc == 2) {
        num = atoi(argv[1]);
    }else{
        cout << "num = ";
        cin >> num;
    }
    vector<Member> payers(num);
    vector <Member>::iterator payerIter;

    string name = "SET_NAME";
    double bill = 0.0;

    // set names and paid bills to each member in vector
    int i = 0;
    for (payerIter = payers.begin(), i=0; payerIter != payers.end(); payerIter++,i++) {
        while (cin.get()!='\n');
        cout << "enter name " << i << ": ";
        getline(cin, name);
        payerIter->set_name(name);

        cout << payerIter->get_name() << " has paid: ";
        cin >> bill;
        if (cin.fail()) {
            cout << "INVALID INPUT! PROGRAMM TERMINNATED." << endl;
            exit(1);
        }
        payerIter->set_paid(bill);
        sum += bill;
    }
    average = sum/payers.size();

    // sort data: who paid more comes fronter
    sort(payers.begin(), payers.end(), paidGreater);

    cout << endl << fixed << setprecision(2)
         << "average cost: " << average << endl << endl;
    // calculate the bill to pay
    for (payerIter = payers.begin(); payerIter != payers.end(); payerIter++) {
        payerIter->set_toPay(average-payerIter->get_paid());
        payerIter->show_info();
    }

    cout << "solution: " << '\n';
    vector <Member>::iterator receiveFlag = payers.begin();
    vector <Member>::iterator payFlag = payers.end()-1;

    while (receiveFlag < payFlag) {
        while (receiveFlag->get_toPay()<0) {
            if (receiveFlag->get_toPay()+payFlag->get_toPay() <= 0) {
                double restToReceive = receiveFlag->get_toPay()+payFlag->get_toPay();
                cout << payFlag->get_name() << " pays " << payFlag->get_toPay()
                << "€ to " << receiveFlag->get_name() <<'\n';
                receiveFlag->set_toPay(restToReceive);
                payFlag->set_toPay(0.0);
                payFlag--;
            } else {
                if (payFlag==receiveFlag) break;
                double restToPay = payFlag->get_toPay()+receiveFlag->get_toPay();
                cout << payFlag->get_name() << " pays "<< -receiveFlag->get_toPay()
                << "€ to " << receiveFlag->get_name() <<'\n';
                receiveFlag->set_toPay(0.0);
                payFlag->set_toPay(restToPay);
                break;
            }
        }
        receiveFlag++;
    }

    return 0;
}

static bool paidGreater(Member m1, Member m2) {
    return m1.get_paid() > m2.get_paid();
}
