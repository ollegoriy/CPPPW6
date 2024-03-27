#include <iostream>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initBalance, double interestRate) {
        accountNumber = accNumber;
        balance = initBalance;
        interestRate = 2.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесение средств успешно. Новый баланс: " << balance << endl;
        }
        else {
            cout << "Внесение средств не успешно." << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие средств успешно. Новый баланс: " << balance << endl;
            return true;
        }
        else {
            cout << "Снятие средств не успешно. Недостаточно средств." << endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    double getInterest() const {
        return balance * interestRate * (1.0 / 12);
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Перевод успешен. Новый баланс отправителя: " << from.balance << ", новый баланс получателя: " << to.balance << endl;
        return true;
    }
    else {
        cout << "Перевод не успешен. Недостаточно средств." << endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    double bal, bal1, iRate, iRate1;
    cout << "Введите баланс первого счета: ";
    cin >> bal;
    cout << "Введите введите процентную ставку первого счета: ";
    cin >> iRate;
    cout << "Введите баланс второго счета: ";
    cin >> bal1;
    cout << "Введите введите процентную ставку первого счета: ";
    cin >> iRate1;
    BankAccount account1(777, bal, iRate);
    BankAccount account2(666, bal1, iRate);
    int choice;
    double amount;
    double rate;
    bool runs = true;
    int chet;
    while (runs) {
        cout << "Выберите операцию:" << endl;
        cout << "1. Узнать информацию о счете:" << endl;
        cout << "2. Пополнить баланс:" << endl;
        cout << "3. Снять деньги:" << endl;
        cout << "4. Перевод:" << endl;
        cout << "5. Изменить процентную ставку:" << endl;
        cout << "0. Выход:" << endl;
        cin >> choice;

        cout << "С каким счетом произвести операцию? (1 или 2) " << endl;
        cin >> chet;
        if (chet == 1) {
            switch (choice) {
            case 1:
                cout << "Номер вашего счета: " << account1.getAccountNumber() << endl;
                cout << "Ваш баланс: " << account1.getBalance() << endl;
                cout << "Ваша текущая процентная ставка: " << iRate << "%" << endl;
                break;
            case 2:
                cout << "На какую сумму вы хотите пополнить баланс?" << endl;
                cin >> amount;
                account1.deposit(amount);
                break;
            case 3:
                cout << "Какую сумму вы хотите снять?" << endl;
                cin >> amount;
                account1.withdraw(amount);
                break;
            case 4:
                cout << "Какую сумму вы хотите перевести?" << endl;
                cin >> amount;
                transfer(account1, account2, amount);
                break;
            case 5:
                cout << "Какую процентную ставку вы хотите иметь на своем счете?" << endl;
                cin >> rate;
                account1.setInterestRate(rate);
                cout << "Полученные проценты: " << account1.getInterest() << endl;
                break;
            case 0:
                runs = false;
                break;
            default:
                cout << "Введена неверная цифра!" << endl;
                break;
            }
            
        }
        else if(chet == 2) {
            switch (choice) {
            case 1:
                cout << "Номер вашего счета: " << account2.getAccountNumber() << endl;
                cout << "Ваш баланс: " << account2.getBalance() << endl;
                cout << "Ваша текущая процентная ставка: " << iRate1 << "%" << endl;
                break;
            case 2:
                cout << "На какую сумму вы хотите пополнить баланс?" << endl;
                cin >> amount;
                account2.deposit(amount);
                break;
            case 3:
                cout << "Какую сумму вы хотите снять?" << endl;
                cin >> amount;
                account2.withdraw(amount);
                break;
            case 4:
                cout << "Какую сумму вы хотите перевести?" << endl;
                cin >> amount;
                transfer(account2, account1, amount);
                break;
            case 5:
                cout << "Какую процентную ставку вы хотите иметь на своем счете?" << endl;
                cin >> rate;
                account2.setInterestRate(rate);
                cout << "Полученные проценты: " << account2.getInterest() << endl;
            case 0:
                runs = false;
                break;
            default:
                cout << "Введена неверная цифра!" << endl;
                break;
            }
        }

    }
    return 0;
}