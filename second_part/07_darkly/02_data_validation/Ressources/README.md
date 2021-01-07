# Get the flag
Page : `/index.php?page=survey`

Inspect one of the form and see that for each subjet there are values on a select.
Change the value of the select to a higher number than 10 and select the corresponding value.

# Security issue
Informations on the front end can always be manipulated by the client before sending them back to server. The server needs to check the coherence of informations it expected to have with the one he got.

# Fix it
1. Never trust user input, always put a back-end logic behind
In this case, it's more an easter egg than a real security issue because even if we get the flag by changing the value on the client side we can see that the value on the survey
hasn't change at all. So the back is really checking option val and does nothing else than sending the flag.
For better UX purpose the back can send an error message with the correct accepted value