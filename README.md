# myDatabase


## How I want it to work ##


## How to create a new database ##


### CLI ###



### In code ###


```cpp

#include "DatabaseManager.hpp"

int main(void) {

    DatabaseManager mydb();

    Database *db = mydb.createDatabase();

    if (dbStatus == FAILED)
        return ;

    if (dbStatus == ALREADY_EXISTS)
    {
        // ...
    }

    if (dbStatus == SUCCESS)
    {
        // ...
    }

    return (0);

}

```


## How to create a table in the database ##


```cpp

int main(void)
{
    Database db;

    DBSTATUS dbStatus = db.getDatabase("database_name");

    if (dbStatus == NOT_FOUND)
        return ;

    if (dbStatus == SUCCESS)
    {
        db.loadEntities({new User("User"), new Room("Room")});
        
    }

}

```
