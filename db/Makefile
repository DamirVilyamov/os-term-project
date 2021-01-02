components = CreateDB DatabaseUtils
DatabaseManager: $(components)
	c99 DatabaseManager.c -o dbMan  `mysql_config --cflags --libs`

CreateDB: DatabaseUtils
	c99 createdb.c -o createdb  `mysql_config --cflags --libs`

DatabaseUtils:
	c99 DatabaseUtils.c -o dbUtils  `mysql_config --cflags --libs`

