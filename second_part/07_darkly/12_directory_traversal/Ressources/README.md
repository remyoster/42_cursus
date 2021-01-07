# Get the flag

Page : `/index.php?page=../../../../../../../../../../../../etc/passwd%00`

When we navigate through the site we can see that the page is generate with query parameters. If we try to modify it we got an alert error and we are redirect to '/'.
We can try a path traversal attack with well known path.
[_source_](https://github.com/xmendez/wfuzz/blob/master/wordlist/Injections/Traversal.txt)

Run `./getflag.sh`

# Security issue
>It may be possible to access arbitrary files and directories stored on file system including application source code or configuration and critical system files.
[_source_](https://owasp.org/www-community/attacks/Path_Traversal)

# Fix it
1. NEVER TRUST USER INPUT ! (example : use a white list of accepted path)
2. Use access policies to restrict where the files can be obtained or saved to