#include <mysql.h>
#ifndef CREATEDB_H_INCLUDED
#define CREATEDB_H_INCLUDED
/* ^^ these are the include guards */

/* Prototypes for the functions */
int createDB(MYSQL *con);

int populateDB(MYSQL *con);

#endif