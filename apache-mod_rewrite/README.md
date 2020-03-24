# Apache mod_rewrite
mod_rewrite is an Apache module for manipulating (rewriting) URLs. With this you do all types of URL rewritings you may need.


#### RewriteBase /
[StackOverflow: What does RewriteBase do and how to use it?](https://stackoverflow.com/a/21348047/11720080)

```bash
root
  ├── subdir1
  ├── subdir2
  │  ├── subsubdir
```


The URI that gets sent through a `RewriteRule` is relative to the directory. So if you have:

    RewriteRule ^(.*)$ - 

in the root, and the request is `/a/b/c/d`, then the captured URI (`$1`) is `a/b/c/d`. But if the rule is in `subdir2` and the request is `/subdir2/e/f/g` then the captured URI is `e/f/g`. The rewrite base has no affect on this.

What the rewrite base *does* do, is provide a URL-path base (*not* a file-path base) for any relative paths in the rule's target.
So say you have this rule which is bar.php in relative path, it’s based on the directory that the rule is in. So if

    RewriteRule ^foo$ bar.php [L]
    
is in the "subdir1" directory, and you go to `http://example.com/subdir1/foo`, you get served `http://example.com/subdir1/bar.php`. 

The `bar.php` is a relative path, as opposed to:

    RewriteRule ^foo$ /bar.php [L]

where the `/bar.php` is an absolute path. The absolute path will *always* be the "root" (in the directory structure above). That means if the rule is in the "root", "subdir1", "subsubdir", etc. The `/bar.php` path always maps to `http://example.com/bar.php`. 

`RewriteBase` The directive tells mod_rewrite what to append to the beginning of every relative path. So if I have:

    RewriteBase /blah/
    RewriteRule ^foo$ bar.php [L]

and that rule is in "subsubdir", going to `http://example.com/subdir2/subsubdir/foo` will actually serve me `http://example.com/blah/bar.php`. The "bar.php" is added to the end of the base.

In most cases, it is used this way, where the htaccess is in the "subdir1" directory

    RewriteEngine On
    RewriteBase /subdir1/
    RewriteRule ^foo$ bar.php [L]
    ...

And then when you needed to move those files and the rules to another directory, just change the base:

    RewriteBase /subdir2/subsubdir/
    
    
#### RewriteRule

[![N|Solid](https://httpd.apache.org/docs/2.4/images/syntax_rewriterule.png)](https://httpd.apache.org/docs/2.4/rewrite/intro.html)

***Examples***

> Assume .htaccess in the root(www.example.com)
   
---
`www.example.com/api/some`  rewrites to `www.example.com/anotherapi.php`

    RewriteRule ^api/some$ anotherapi.php

---
`www.example.com/somedir`, `www.example.com/somedir/`, `www.example.com/somedir/<anything>` Rewrites to `www.example.com/anotherapi.php`

    RewriteRule ^somedir/?|somedir/.*$ somed.php
    
---
`www.ex.com/args1/val1/args2/val2` Rewrites to `www.ex.com/index.php?arg1=val1&arg2=val2`

    RewriteRule ^[a-zA-Z0-9]+/([a-zA-Z0-9]+)/[a-zA-Z0-9]+/([a-zA-Z0-9]+)$ index.php?arg1=$1&arg2=$2 [NC]

> `[NC]` mean **NoCase** that is case insensitive.


### rewrite cond
[![N|Solid](https://httpd.apache.org/docs/2.4/images/syntax_rewritecond.png)](https://httpd.apache.org/docs/2.4/rewrite/intro.html)
One or more RewriteCond directives can be used to restrict the types of requests that will be subject to the following RewriteRule. The first argument is a variable describing a characteristic of the request, the second argument is a regular expression that must match the variable, and a third optional argument is a list of flags that modify how the match is evaluated.


#### [OR]
`ornext|OR` (or next condition) Use this to combine rule conditions with a local OR instead of the implicit AND. Typical example:

    RewriteCond %{REMOTE_HOST}  ^host1  [OR]
    RewriteCond %{REMOTE_HOST}  ^host2  [OR]
    RewriteCond %{REMOTE_HOST}  ^host3
    RewriteRule ...some special stuff for any of these hosts...

[OR] is used when you want to have, one OR another OR another condition, trigger the rewriterule. Otherwise the default behavior is 'AND' All of the RewriteConds have to be true in order to trigger the rule.

##### !-F &  !-d

If the requested filename is no real file on the harddisk, this condition is true.

    RewriteCond %{REQUEST_FILENAME} !-f

If the requested filename is no real directory, this condition is true.

    RewriteCond %{REQUEST_FILENAME} !-d


### Example
```html
<IfModule mod_rewrite.c>
  RewriteEngine On
  RewriteBase /
  RewriteRule ^index\.html$ - [L]
  RewriteCond %{REQUEST_FILENAME} !-f
  RewriteCond %{REQUEST_FILENAME} !-d
  RewriteRule . /index.html [L]
</IfModule>
```

    RewriteEngine On
    RewriteBase /

Initialize rewrite engine and set rewrite base to root directory

    RewriteRule ^index\.html$ - [L]
    
If request is `www.example.com/index.html` then do nothing(dash). The flag `[L]` means that if the rule matches, no further rules will be processed.

    RewriteCond %{REQUEST_FILENAME} !-f
    RewriteCond %{REQUEST_FILENAME} !-d
    RewriteRule . /index.html [L]

… means that if the file with the specified name in the browser doesn’t exist, or the directory in the browser doesn’t exist then procede to the rewrite rule below, that is rewrite `www.example.com/<anything>` to `www.example.com/index.html`.

## Other Related Links
[mod rewrite cheatcheat](https://mod-rewrite-cheatsheet.com/)
[apache-rewrite-cheatcheat](https://github.com/headsnet/apache-rewrite-cheatsheet)
[Apache Mod Rewrite Introduction](https://httpd.apache.org/docs/2.4/rewrite/intro.html)





