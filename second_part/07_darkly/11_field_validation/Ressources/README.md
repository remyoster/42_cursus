# Get the flag
Page : `/?page=feedback`

Try to submit the form without anything and we get an alert error that tells us to fullfill the name input.
Put some unique value like s, r, e in it and submit the form again.

# Security issue
Attacker can broke the server if the inputs variable are not handle correctly on the back (null, big length...). 
Furthermore the name input isn't protected against XSS injection (ex: <img src='xssinjection' onerror="alert('xss')">).

# Fix it
1. NEVER TRUST USER INPUT. Sanitize and validate inputs on the back. Always, even if there are some controls on the front (because the front can be manipulated)
2. Don't put some custom javascript function to validate something that default attributes handle (like required, minlength ...)