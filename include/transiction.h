#pragma once

#include <string>

using namespace std;

struct Transaction {
private:
    long sender;
    long receiver;
    bool type;
    float balance;
};