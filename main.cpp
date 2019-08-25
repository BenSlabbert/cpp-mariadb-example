#include <iostream>
#include <mysql_connection.h> // reports to be unused, but keeping it
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>

using namespace sql;
using std::cout;
using std::endl;

int main() {
    cout << "Starting app" << endl;

    char *string = getenv("");

    sql::Driver *driver = nullptr;
    sql::Connection *con = nullptr;
    sql::Statement *stmt = nullptr;
    sql::ResultSet *res = nullptr;

    try {
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        con->setSchema("cpp");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from test");
        int count = 0;

        while (res->next()) {
            count++;
            const SQLString &name = res->getString("name");
            cout << "Got name: " << name << " from db!" << endl;
        }

        cout << "Results found: " << count << endl;
        con->close();
    } catch (sql::SQLException &e) {
        cout << "Exception while running app: " << e.what() << " err code: " << e.getErrorCode() << endl;
    }

    delete res;
    delete stmt;
    delete con;

    return 0;
}
