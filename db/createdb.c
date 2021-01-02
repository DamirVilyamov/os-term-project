#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "createdb.h"
#include "DatabaseUtils.h"


void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int createDB(MYSQL *con)
{
    //MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "password", NULL, 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
    //need to make the name of db dynamic(pass it as a parameter)
    if (mysql_query(con, "CREATE DATABASE testdbProd"))
    {
        finish_with_error(con);
    }


    if (mysql_query(con, "DROP TABLE IF EXISTS USERS")) {
      finish_with_error(con);
    }

    if (mysql_query(con, "CREATE TABLE USERS(login VARCHAR(255) PRIMARY KEY , name VARCHAR(255), password VARCHAR(255), passportNumber VARCHAR(255))")) {
        finish_with_error(con);
    }




    if (mysql_query(con, "DROP TABLE IF EXISTS ACCOUNTS")) {
      finish_with_error(con);
    }

    if (mysql_query(con, "CREATE TABLE ACCOUNTS(accountNumber UNSIGNED INT PRIMARY KEY, accountBalance UNSIGNED INT, accountName VARCHAR(255), password VARCHAR(255), currency VARCHAR(255), FOREIGN KEY (passport_number) REFERENCES USERS(passport_number) )")) {
        finish_with_error(con);
    }

    
    
    
    if (mysql_query(con, "DROP TABLE IF EXISTS TRANSFERS")) {
      finish_with_error(con);
    }

    if (mysql_query(con, "CREATE TABLE TRANSFERS(fromAccountNumber UNSIGNED INT, toAccountNumber UNSIGNED INT, transferDate VARCHAR(255), amount UNSIGNED INT)")) {
        finish_with_error(con);
    }

    //mysql_close(con);

    exit(0);
}

int populateDb(MYSQL *con){
    // MYSQL *con = mysql_init(NULL);
    // //todo later
    // mysql_close(con);
    exit(0);
}
int main(){
    return 0;
}