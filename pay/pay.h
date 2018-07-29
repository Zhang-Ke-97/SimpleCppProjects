#include <iostream>
#include <string>

#ifndef PAY_H
#define PAY_H 0

class Member {
private:
    std::string memName;
    double paid;
    double toPay;
public:
    Member() {
        memName = "SET_NAME";
        paid = 0;
        toPay = 0;
    }

    void set_name(std::string name) {
        this->memName = name;
    }
    std::string get_name() {
        return memName;
    }
    void set_paid(double bill) {
        paid = bill;
    }
    double get_paid() {
        return paid;
    }
    void set_toPay(double bill) {
        toPay = bill;
    }
    double get_toPay(){
        return toPay;
    }
    void show_info() {
        std::cout << memName << " paid: " << paid;
        if (toPay>=0) {
            std::cout << ", to pay: " << toPay << '\n';
        }else{
            std::cout << ", to receive: " << -toPay << '\n';
        }

    }

};

#endif
