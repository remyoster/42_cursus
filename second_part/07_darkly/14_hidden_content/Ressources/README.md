# Get the flag
Page : `/.hidden/`

Theese routes are "protected" from crawlers by the robots.txt file. We can see that there are only README when we travel trough a pass. So we can crawl manually into each of theese
routes and then check all README files.

Run `./getflag.sh`

# Security issue
Here there isn't asny security issue, just a curious pattern. It the goal was to hide something it's simplier and much safier to put some backend restriction on routes

# Fix it
1. Put the "secret" content into a protected route (either with backend logic like role or auth, either with a .htaccess file if the webserver is hosted on apache etc...)