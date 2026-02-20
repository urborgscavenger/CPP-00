#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// --- C# Style Helpers ---
#define Write(x) std::cout << x
#define WriteLine(x) std::cout << x << std::endl

// Hilfsmakros für das spezifische Log-Format
#define Log(key, val) Write(key << ":" << val << ";")
#define LogLast(key, val) Write(key << ":" << val << std::endl)

// Statische Member Initialisierung
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// --- Statische Funktionen ---

int Account::getNbAccounts(void)    { return _nbAccounts; }
int Account::getTotalAmount(void)   { return _totalAmount; }
int Account::getNbDeposits(void)    { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    Log("accounts", _nbAccounts);
    Log("total", _totalAmount);
    Log("deposits", _totalNbDeposits);
    LogLast("withdrawals", _totalNbWithdrawals);
}

// --- Konstruktor & Destruktor ---

Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    Log("index", _accountIndex);
    Log("amount", _amount);
    WriteLine("created");
}

Account::~Account(void) {
    _displayTimestamp();
    Log("index", _accountIndex);
    Log("amount", _amount);
    WriteLine("closed");
}

// --- Instanz-Methoden ---

void Account::makeDeposit(int deposit) {
    int p_amount = _amount;
    
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    Log("index", _accountIndex);
    Log("p_amount", p_amount);
    Log("deposit", deposit);
    Log("amount", _amount);
    LogLast("nb_deposits", _nbDeposits);
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    Log("index", _accountIndex);
    int p_amount = _amount;
    Log("p_amount", p_amount);

    if (withdrawal > _amount) {
        WriteLine("withdrawal:refused");
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    Log("withdrawal", withdrawal);
    Log("amount", _amount);
    LogLast("nb_withdrawals", _nbWithdrawals);
    return true;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    Log("index", _accountIndex);
    Log("amount", _amount);
    Log("deposits", _nbDeposits);
    LogLast("withdrawals", _nbWithdrawals);
}

// --- Private Zeitstempel-Funktion ---

void Account::_displayTimestamp(void) {
    time_t now = std::time(NULL);
    struct tm *t = std::localtime(&now);
    char buf[32];
    if (t && std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", t)) {
        std::cout << buf;
    }
}
