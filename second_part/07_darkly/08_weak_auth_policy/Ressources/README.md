# Get the flag
Page : `/index.php?page=signin`

Here there isn't any possibility of SQL injection so we can try some brute force to see if there is a weak login/password policy.
To do that we are going to use the most famous credentials (cf passwords.txt and usernames.txt) [_source_](https://github.com/danielmiessler/SecLists)

As the page redirect us to an error page we just have to test if we are not on
this error page as long as we try with different credentials.
Run `./getflag.sh`

# Security issue
An attacker can be logged on the app and do whatever he can with his privilege.
(access private data, manipulate app through the admin panel etc...)
Here it's even worst as the credentials seems to be the root access.

# Fix it
1. Adopt a strong password policy (especialy for ROOT/ADMIN...)
2. Put a max attemp counter and block the user's IP for a amount of time
3. Limit attempt on the login page for an IP (example 2 / sec)
4. Don't expose credentials on URL (use POST instead)

