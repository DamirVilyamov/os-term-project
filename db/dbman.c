#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

//c99 version.c -o version  `mysql_config --cflags --libs`

void finish_with_error(MYSQL *con, int position)
{
    fprintf(stderr, "%s\n position:%d", mysql_error(con), position);
    mysql_close(con);
    exit(1);
}

struct st_mysql *connectDB()
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "password", "testdbProd", 0, NULL, 0) == NULL)
    {
        finish_with_error(con, 20);
    }

    return con;
}

void disconnectDB(MYSQL *con)
{
    mysql_close(con);
}

void runQuery(char *query, MYSQL *con)
{
    if (mysql_query(con, query))
    {
        finish_with_error(con, 44);
    }
}

int createDB()
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "password", NULL, 0, NULL, 0) == NULL)
    {
        finish_with_error(con, 0);
    }

    if (mysql_query(con, "DROP DATABASE IF EXISTS testdbProd"))
    {
        finish_with_error(con, 1);
    }

    if (mysql_query(con, "CREATE DATABASE testdbProd"))
    {
        finish_with_error(con, 1);
    }

    mysql_close(con);
}

void addUser(char *login, char *name, char *password, char *passportNumber)
{
    MYSQL *con = connectDB();
    char query[100];
    sprintf(query, "INSERT INTO users VALUES('%s','%s', '%s', '%s')", login, name, password, passportNumber);

    runQuery(query, con);

    disconnectDB(con);
}

void addAccount(char *accountNumber, int accountBalance, char *accountName, char *cardPassword, char *currency, char *login)
{
    MYSQL *con = connectDB();

    char query[100];
    sprintf(query, "INSERT INTO accounts VALUES('%s','%d', '%s', '%s', '%s', '%s')", accountNumber, accountBalance, accountName, cardPassword, currency, login);

    runQuery(query, con);

    disconnectDB(con);
}

void addTransfer(char *fromAccountNumber, char *toAccountNumber, char *transferDate, int amount)
{
    MYSQL *con = connectDB();

    char query[100];
    sprintf(query, "INSERT INTO transfers VALUES('%s','%s', '%s', '%d')", fromAccountNumber, toAccountNumber, transferDate, amount);

    runQuery(query, con);

    disconnectDB(con);
}

int isUserAuthorized(char *login, char *password)
{
    MYSQL *con = connectDB();

    char query[100];
    sprintf(query, "SELECT * FROM users WHERE users.login = '%s' AND users.password = '%s'", login, password);

    runQuery(query, con);

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con, 51);
    }

    int num_fields = mysql_num_fields(result);
    printf("%d\n", num_fields);
    MYSQL_ROW row = mysql_fetch_row(result);
    if (!row)
    {

        return 0;
    }
    else
    {
        printf("while:\n");

        for (int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
            printf("\n%d ", i);
            // if (row[i] == "NULL")
            // {
            //     return 0;
            // }
        }

        printf("\n");
    }

    mysql_free_result(result);
    disconnectDB(con);
    return 1;
}

void getUser(char *login)
{
    MYSQL *con = connectDB();

    char query[100];
    sprintf(query, "SELECT * FROM users WHERE users.login = '%s'", login);

    runQuery(query, con);

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con, 51);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
    disconnectDB(con);
}

void getAccountsForUser(char *login)
{
    MYSQL *con = connectDB();

    char query[100];
    sprintf(query, "SELECT * FROM accounts WHERE accounts.login = '%s'", login);

    runQuery(query, con);

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con, 51);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
    disconnectDB(con);
}

void getTransfersForAccount(char *accountNumber)
{
    MYSQL *con = connectDB();

    char query[150];
    sprintf(query, "SELECT * FROM transfers WHERE transfers.fromAccountNumber = '%s' OR transfers.toAccountNumber = '%s'", accountNumber, accountNumber);

    runQuery(query, con);

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con, 51);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {

            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }
    printf("\nfree transfers result\n");
    mysql_free_result(result);
    disconnectDB(con);
}

int createTables()
{
    MYSQL *con = connectDB();

    if (mysql_query(con, "USE testdbProd"))
    {
        finish_with_error(con, 2);
    }

    if (mysql_query(con, "DROP TABLE IF EXISTS users"))
    {
        finish_with_error(con, 2);
    }

    if (mysql_query(con, "CREATE TABLE users(login VARCHAR(255) PRIMARY KEY, name VARCHAR(255), password VARCHAR(255), passportNumber VARCHAR(255))"))
    {
        finish_with_error(con, 3);
    }

    if (mysql_query(con, "DROP TABLE IF EXISTS accounts"))
    {
        finish_with_error(con, 4);
    }

    if (mysql_query(con, "CREATE TABLE accounts(accountNumber VARCHAR(255) PRIMARY KEY, accountBalance INT, accountName VARCHAR(255), cardPassword VARCHAR(255), currency VARCHAR(255), login VARCHAR(255), CONSTRAINT FOREIGN KEY (login) REFERENCES users (login) )"))
    {
        finish_with_error(con, 5);
    }

    if (mysql_query(con, "DROP TABLE IF EXISTS transfers"))
    {
        finish_with_error(con, 6);
    }

    if (mysql_query(con, "CREATE TABLE transfers(fromAccountNumber VARCHAR(255), toAccountNumber VARCHAR(255), transferDate VARCHAR(255), amount INT)"))
    {
        finish_with_error(con, 7);
    }

    disconnectDB(con);
}

int populateDb()
{
    MYSQL *con = connectDB();

    if (mysql_query(con, "USE testdbProd"))
    {
        finish_with_error(con, 2);
    }
    if (mysql_query(con, "INSERT INTO users VALUES('Damir@gmail.com','Damir', '123', '121313')"))
    {
        finish_with_error(con, 44);
    }

    addUser("Abbos@gmail.com", "Abbos", "123", "121313");

    addAccount("86009090909090", (int)1000, "VISA", "2323", "$", "Damir@gmail.com");
    addAccount("86009090909080", (int)2000, "VISA", "2525", "$", "Abbos@gmail.com");

    addTransfer("86009090909090", "86009090909080", "030121", (int)50);
    addTransfer("86009090909080", "86009090909090", "030121", (int)50);

    disconnectDB(con);
}

int main()
{
    createDB();
    createTables();
    populateDb();

    // getUser("Damir@gmail.com");
    // getAccountsForUser("Damir@gmail.com");
    //getTransfersForAccount("86009090909080");
    int answer = isUserAuthorized("Damir@gmail.com", "12333");
    printf("\nis authorised = %d", answer);
    printf("\nmain exiting fine\n");
    return 0;
}