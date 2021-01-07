# Get the flag
Page : `/index.php?page=media&src=nsa`

Inspect the nsa logo displayed and discover that it is served in a object tag with a local link (http://192.168.122.49/images/nsa_prism.jpg).
Change the src value with 42 (or anything else) and you get a wrong answer img. When inspecting we discover that there is still the object tag in the page with the data value egual to src. So if you put `/images/42.jpeg` you can include the 42's logo on the page.
let's try some XSS injection.


- <script>alert('xss')</script> || javascript:alert('xss')
=> we got nothing

Let's try with data URI (`data:[<mediatype>][;base64],<data>`) :
- data:text/html,<script>alert('xss')</script>
=> we got the alert but no flag (so xss vulnerability)

- data:text/html;base64,PHNjcmlwdD5hbGVydCgneHNzJyk8L3NjcmlwdD4=
=> Eureka

# Security issue
An attacker may execute any file he created by using this page as playground.

# Fix it
1. Sanitize and escape special chars
2. Don't use URL based src in a data field, generate the link on the back-end and serve it to the front.
3. Restrict the type of the object (with MIME)
