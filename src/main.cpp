#include "../include/list.h"
#include "../include/node.h"
#include "../include/account.h"
#include "../include/transiction.h"
#include "../include/manager.h"
#include <optional>
#include <iostream>

using namespace std;

List<Account> Manager::accounts = List<Account>(
    1, 
    new Account("Simão", "simaopks009@gmail.com", "962345438", "Cova da Serpe", "123456")
);

optional<Account> current = optional<Account>();

void menu() {
    cout << endl;
    cout << " 1. Informações da Conta" << endl;
    cout << " 2. Transferir dinheiro" << endl;
    cout << " 3. Listar todas as contas (admin)" << endl;
    cout << endl;

    int option;
    cin >> option;

    optional<Account> value;

    switch (option) {
        case 1:
            cout << endl;
            cout << " Id da conta: " << current.value().getId() << endl;
            cout << " Dono da conta: " << current.value().getOwner() << endl;
            cout << " Email da conta: " << current.value().getEmail() << endl;
            cout << " Fone da conta: " << current.value().getPhone() << endl;
            cout << " Localização da conta: " << current.value().getLocation() << endl;
            cout << " Saldo da conta: " << current.value().getBalance() << endl;
            cout << " Data de criação da conta " << current.value().getCreatedAt() << endl;
            cout << endl;
            break;
        case 2:
            cout << "1. Numero da conta do destinatário: ";
            long id;
            cin >> id;

            cout << "2. Quantidade de dinheiro a ser transferido: ";
            float amount;
            cin >> amount;

            value = Manager::get(id);
            if (value.has_value()) {

                if (amount > value.value().getBalance()) {
                    cout << endl;
                    cout << " Sem saldo suficiente." << endl;
                    cout << endl;
                    return;
                }

                if (current.value().getId() == value.value().getId()) {
                    cout << endl;
                    cout << " Não podes enviar dinheiro para ti mesmo." << endl;
                    cout << endl;
                }

                value.value().setBalance(value.value().getBalance() + amount);
                current.value().setBalance(current.value().getBalance() - amount);

                cout << endl;
                cout << " Transição efetuada com sucesso!" << endl;
                cout << endl;

                break;
            } else {
                cout << endl;
                cout << " Conta inexistente!" << endl;
                cout << endl;
            }

            break;
        case 3:
            for (int i = 0; i < Manager::accounts.getSize(); i++) {
                cout << " " << i + 1 << "º " << Manager::accounts.get(i, 1)->data.getOwner() << " " << Manager::accounts.get(i, 1)->data.getBalance() << endl;
            }
            break;
    }
    
    menu();
}

void sign(bool mode) {
    if (mode == 0) {
        cout << "1. Qual é o nome da conta: ";
        string name;
        cin >> name;

        cout << "2. Qual é o email da conta: ";
        string email;
        cin >> email;

        cout << "3. Qual é o número de telefone da conta: ";
        string number;
        cin >> number;

        cout << "4. Qual é a localidade do dono da conta: ";
        string location;
        cin >> location;

        cout << "5. Qual é a senha da conta: ";
        string password;
        cin >> password;

        Account account(name, email, number, location, password);

        current = account;
        Manager::accounts.add(account);

        cout << endl;
        cout << " Conta criada com sucesso!" << endl;
        cout << endl;

        menu();
    } else {
        cout << "1. Qual é o email ou numero de telefone da conta: ";
        string identifier;
        cin >> identifier;

        cout << "2. Qual é o código de segurança da conta: ";
        string password;
        cin >> password;

        optional<Account> account = Manager::exists(identifier, password);
        if (account.has_value()) {
            current = account;
            cout << "Login efetuado com sucesso!" << endl;
            cout << endl;
            menu();
        } else {
            cout << "Conta não encontrada!" << endl;
            cout << endl;
            sign(mode);
        }
    }
}

void welcome() {
    cout << endl;
    cout << " Bem vindo ao sistema de contas bancárias" << endl;
    cout << endl;
    cout << " 0. Criar uma conta." << endl;
    cout << " 1. Iniciar sessão em uma conta." << endl;
    cout << endl;
    cout << "Escolha uma opção: ";

    bool response;
    try {
        cin >> response;
    } catch (exception ignored) {
        response = 0;
    }

    sign(response);
}

int main() {
    welcome();
}
