# Get the flag
/?page=e43ad1fdc54babe674da7c7b8f0127bde61de3fbe01def7d00f151c2fcca6d1c
(which is the one displayed when clicking on copyright, carefull, it launchs some music)

Inspect the page and discover some huge comments. After a good reading you notice two interesting leaking comments :
>You must cumming from : "https://www.nsa.gov/" to go to the next step
>Let's use this browser : "ft_bornToSec". It will help you a lot.

When doing a http request, we can manipulate the url we came from (=referer) and the browser we use (=user-agent). So with theese hints we can deduce that the first one in the referer and the second one the user-agent. By doing so with curl (cf man) it gaves us :
`curl -H "User-Agent:ft_bornToSec" -e https://www.nsa.gov/ http://192.168.122.49/\?page\=e43ad1fdc54babe674da7c7b8f0127bde61de3fbe01def7d00f151c2fcca6d1c`

The server respond with the same html page but one line is new :
```
<center><h2 style="margin-top:50px;"> The flag is : f2a29020ef3132e01dd61df97fd33ec8d7fcd1388cc9601e7db691d17d4d6188</h2><br/><img src="images/win.png" alt="" width=200px height=200px></center>
```

# Security issue
1. User-agent
There isn't any security issue here, it's just a bad practice to serv different content depending on the user-agent.
>The Web is meant to be accessible to everyone, regardless of which browser or device they're using. There are ways to develop your website to progressively enhance itself based on the availability of features rather than by targeting specific browsers.
[_source_](https://developer.mozilla.org/en-US/docs/Web/HTTP/Browser_detection_using_the_user_agent)

2. Referer
A user can access a restricted page based on his previous nagivation

# Fix it
user-agent and referer headers can be manipulate so don't rely on it.

1. User-agent
Don't provide different content based on user-agent, it's a bad practice. If there is a problem with a specif user-agent, make some research, maybe your problem as already been solved.

2. Referer
Don't rely on the referer to send back response, use other mechanism on the back (jwt, auth, bearer....)