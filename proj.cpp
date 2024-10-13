#include <iostream>
#include <sql.h>
#include <sqlext.h>
void connectToDatabase() {
    SQLHENV hEnv;
    SQLHDBC hConn;
    SQLRETURN ret;

    // Allocate environment handle
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    SQLSetEnvAttr(hEnv, SQL_ATTR_ENV_VAR, SQL_DRIVER_PROMPT, SQL_IS_INTEGER);

    // Allocate connection handle
    ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hConn);

    // Connect to the database
    const char* connStr = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=your_server;DATABASE=your_db;UID=your_username;PWD=your_password;";
    ret = SQLDriverConnect(hConn, NULL, (SQLCHAR*)connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
    
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        std::cout << "Connected to the database successfully!" << std::endl;
    } else {
        std::cerr << "Failed to connect to the database." << std::endl;
        // Handle errors
    }

    // Clean up
    SQLDisconnect(hConn);
    SQLFreeHandle(SQL_HANDLE_DBC, hConn);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
}
int main() {
    connectToDatabase();
    // Additional data processing or AI model invocation can be done here
    return 0;
}
