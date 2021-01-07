# Get the flag
Pages : `/whatever` and `/admin`

By getting the robots.txt file we can see 2 disallow paths for crawlers.
Here we're going to focus on `/whatever`. There is a htpasswd file that we can dl.
There is some root credentials that we can decrypt with https://hashtoolkit.com/
and it gives us : `dragon`.
Generally htpasswd give access to admin page, so by typing `/admin` we fall directly on it. Put root and dragon and gotcha

# Security issue
Anyone can find this file and can log as an admin. So depending on what admin can do on your application, it can be really severe.


# Fix it
1. Restrict access to such file
2. Don't store credentails in a file but into a secure cloud space.
3. Hash the login and the pass with a strong algorithm (sha512, whirlpool...)