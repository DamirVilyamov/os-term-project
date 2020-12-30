#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "createdb.h"
#include "DatabaseUtils.h"

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
        finish_with_error(con);
    }
    //need to make the name of db dynamic(pass it as a parameter)
    if (mysql_query(con, "CREATE DATABASE testdb"))
    {
        finish_with_error(con);
    }

    mysql_close(con);
    exit(0);
}