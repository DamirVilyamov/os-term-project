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

void addUser(MYSQL *con, char *login, char *name, char *password, char *passportNumber)
{
    char query[100];
    sprintf(query, "INSERT INTO users VALUES('%s','%s', '%s', '%s')", login, name, password, passportNumber);

    if (mysql_query(con, query))
    {
        finish_with_error(con, 44);
    }
}

void addAccount(MYSQL *con, int accountNumber, int accountBalance, char *accountName, char *cardPassword, char *currency, char *login)
{
    char query[100];
    sprintf(query, "INSERT INTO accounts VALUES('%d','%d', '%s', '%s', '%s', '%s')", accountNumber, accountBalance, accountName, cardPassword, currency, login);

    if (mysql_query(con, query))
    {
        finish_with_error(con, 44);
    }
}
//fromAccountNumber INT, toAccountNumber INT, transferDate VARCHAR(255), amount INT
void addTransfer(MYSQL *con, int fromAccountNumber, int toAccountNumber, char *transferDate, int amount)
{
    char query[100];
    sprintf(query, "INSERT INTO transfers VALUES('%d','%d', '%s', '%d')", fromAccountNumber, toAccountNumber, transferDate, amount);

    if (mysql_query(con, query))
    {
        finish_with_error(con, 44);
    }
}

int createTables()
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

    if (mysql_query(con, "USE testdbProd"))
    {
        finish_with_error(con, 2);
    }

    if (mysql_query(con, "DROP TABLE IF EXISTS USERS"))
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

    if (mysql_query(con, "CREATE TABLE accounts(accountNumber INT PRIMARY KEY, accountBalance INT, accountName VARCHAR(255), cardPassword VARCHAR(255), currency VARCHAR(255), login VARCHAR(255), CONSTRAINT FOREIGN KEY (login) REFERENCES users (login) )"))
    {
        finish_with_error(con, 5);
    }

    if (mysql_query(con, "DROP TABLE IF EXISTS transfers"))
    {
        finish_with_error(con, 6);
    }

    if (mysql_query(con, "CREATE TABLE transfers(fromAccountNumber INT, toAccountNumber INT, transferDate VARCHAR(255), amount INT)"))
    {
        finish_with_error(con, 7);
    }

    mysql_close(con);
}

int populateDb()
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

    if (mysql_query(con, "USE testdbProd"))
    {
        finish_with_error(con, 2);
    }
    if (mysql_query(con, "INSERT INTO users VALUES('Damir@gmail.com','Damir', '123', '121313')"))
    {
        finish_with_error(con, 44);
    }

    addUser(con, "Abbos@gmail.com", "Abbos", "123", "121313");

    addAccount(con, (int)86009090909090, (int)1000, "VISA", "2323", "$", "Damir@gmail.com");
    addAccount(con, (int)86009090909080, (int)2000, "VISA", "2525", "$", "Abbos@gmail.com");

    addTransfer(con, (int)86009090909090, (int)86009090909080, "030121", (int)50);
    addTransfer(con, (int)86009090909080, (int)86009090909090, "030121", (int)50);

    mysql_close(con);
}

int main()
{
    createDB();
    createTables();
    populateDb();
    return 0;
}