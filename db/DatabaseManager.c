#include "createdb.h"
#include "DatabaseUtils.h"
#include <mysql.h>


int main(){
    MYSQL *con = mysql_init(NULL);
    createDB(con);

    mysql_close(con);
    return 0;
}