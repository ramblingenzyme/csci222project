#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <pqxx/pqxx> 

void postgres_transaction(char*);
result& postgres_non_transaction(char*);


#endif 


