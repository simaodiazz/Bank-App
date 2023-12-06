#pragma once

#include "list.h"
#include "transiction.h"
#include <string>
#include <chrono>

using namespace std;

class Account {
private:
    long id;
    string owner;
    string email;
    string phone;
    string location;
    string password;
    float balance;
    List<Transaction> transactions;
    long createdAt;
    long updatedAt;
public:

    Account(string owner, string email, string phone, string location, string password) {
        this->id = rand() + 100000 % 1000000000000;
        this->owner = owner;
        this->email = email;
        this->phone = phone;
        this->location = location;
        this->password = password;
        this->balance = 0.0;
        this->transactions = List<Transaction>();
        this->createdAt = chrono::system_clock::now().time_since_epoch().count();
        this->updatedAt = this->createdAt;
    }

    long getId() {
        return this->id;
    }

    string getOwner() {
        return this->owner;
    }

    string getEmail() {
        return this->email;
    }

    string getPhone() {
        return this->phone;
    }

    string getLocation() {
        return this->location;
    }

    string getPassword() {
        return this->password;
    }

    double getBalance() {
        return this->balance;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    List<Transaction> getTransictions() {
        return this->transactions;
    }

    long getCreatedAt() {
        return this->createdAt;
    }

    long getUpdatedAt() {
        return this->updatedAt;
    }
};
