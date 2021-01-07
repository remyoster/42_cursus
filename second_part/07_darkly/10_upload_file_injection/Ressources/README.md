# Get the flag
Page : `/index.php?page=upload`

By trying to upload a real img and an empty (fake) img we discover that both worked.
When we try to upload a valid png file we get an error.
So we can deduce that the server only check the *MIME type* which is automatically added by the front based on the file name. But what if we send another file with the correct mime type ?
Run `./getflag.sh`

# Security issue
An attacker can upload any file that doesn't exceed the size limit. It the file is later used in the site it can lead to serious injection.

# Fix it
1. Check image validity (using Image constructor in JS, exif_imagetype in PHP, imghdr in Python...)
2. (good practice) : Limit the filename length both client / server sides. Fullfill the accept attribute on the input type with the mimetype you expect