#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n position:", mysql_error(con));
    mysql_close(con);
    exit(1);
}