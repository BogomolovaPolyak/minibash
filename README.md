# minibash
Basic bash reimplementation in C
### How to build:
Readline install command: `$ brew install readline`

Then: `$ make all`
### What we did:
* Builtins: `echo`, `pwd`, `cd`, `env`, `export`, `unset` and `exit`
* Redirections, pipes, signals, single and double quotes (but without backslash)
* Command history
* Environment variables and `$?`
* Launch commands and executable files (based on the PATH variable or by using relative or absolute path)
* Error handler ofc
* Leak-free (except readline leaks) and norminette code-style
### Authors:
* [BogomolovaPolyak](https://github.com/BogomolovaPolyak)
* [MikavaN](https://github.com/MikavaN)

![](https://github.com/BogomolovaPolyak/minibash/blob/master/screencast/screencast.gif)
