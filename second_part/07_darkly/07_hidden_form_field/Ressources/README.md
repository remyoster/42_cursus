# Get the flag
Page : `/index.php?page=recover`

Inspect the form and discover a hidden field of type mail with "webmaster@borntosec.com" value. Edit it with anything else (even not a email) and submit the form

# Security issue
Hidden fields can be usefull to provide some data to the back-end BUT it can be manipulate as everything else in the front. So if a business logic depends on it, it can lead to unexpected and unwanted behavior.

# Fix it
1. NEVER TRUST USER INPUT ! Don't rely on the front-end informations (even in hidden fields you put there). Always check on back-end the validity of these inputs.
2. Add some CRSF tokens
