# Get the flag
Page : `/index.php?page=redirect&site=42`

Inspect the social network icons on the footer of any page and discover that links to the site is dynamic and depending on the URL parameters to perform the redirection.
So by changing the value of the site key (example : 42) we get the flag

# Security issue
If the back doesn't handle the query for each error case it can crash the serv
If the back is corrupted, an attacker may generate a link to anywhere

# Fix it
- Use static link instead
* https://www.facebook.com/42born2code/
* https://twitter.com/42born2code
* https://www.instagram.com/42born2code/

- Return a 404 page