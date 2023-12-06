#pragma once

#include <optional>
#include <string>
#include "list.h"
#include "account.h"

using namespace std;

class Manager {
private:

public:

    static List<Account> accounts;

    static optional<Account> exists(string identifier, string password) {
        for (int i = 0; i < accounts.getSize(); i++) {
            if (identifier == accounts.get(i, 1)->data.getEmail() || identifier == accounts.get(i, 1)->data.getPhone() && password == accounts.get(i, 1)->data.getPassword()) {
                return accounts.get(i, 1)->data;
            }
        }
        return optional<Account>();
    }

    static optional<Account> get(long id) {
        for (int i = 0; i < accounts.getSize(); i++) {
            if (accounts.get(i, 1)->data.getId() == id) {
                return accounts.get(i, 1)->data;
            }
        }
        return optional<Account>();
    }
};