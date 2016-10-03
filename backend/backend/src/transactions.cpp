#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
using namespace pqxx;

void postgres_transaction(char *query) {

    try{
        connection C("dbname=bugtracker user=postgres password=csci222password hostaddr=csci222-ass2.cy0af74vuu5h.ap-southeast-2.rds.amazonaws.com port=5432" );
        if (C.is_open()) {
            cout << "Opened database successfully: "<< C.dbname() << endl;
        } else {
            cout << "Failed to open database succesfully" << endl;
            return 1;
        }

        //create a transactional object

        work W(C);

        W.exec (query);
        W.commit();
        cout << "Success" << endl;
        C.disconnect();
    } catch (const exception &e){
        cout << e.what() << endl;
        return 1;
    } catch (...){
        return 1;
    }

    return 0;
}

result& postgres_non_transaction(char *query) {

    try{
        connection C("dbname=bugtracker user=postgres password=csci222password hostaddr=csci222-ass2.cy0af74vuu5h.ap-southeast-2.rds.amazonaws.com port=5432" );
        if (C.is_open()) {
            cout << "Opened database successfully: "<< C.dbname()<< endl;
        } else {
            cout << "Failed to open database succesfully" << endl;
            return 1;
        }

        //create a transactional object

        nontrasaction N(C);

        result R(N.exec (query));
        C.disconnect();
    } catch (const exception &e){
        cout << e.what() << endl;
        return 1;
    } catch (...){
        return 1;
    }

    return R;
}

