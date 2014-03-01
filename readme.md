#### gp
This is how I generate passwords.

##### Install
```
$ cd gp/
$ make
$ sudo make install
```

##### Use
```
$ gp --help
usage: gp [-l num] [-n num] [--lowercase] [--numeric] [--symbols]
$ gp
B9867cShclXj
$ gp -l 8
OZ0W1HGs
$ gp -l 8 -n 3
XprFit0n
7Tla87jg
zlVt9fCk
$ gp --lowercase
3rju0q8xr03n
$ gp --symbols
$3x@G*#W.5Ea
$ gp -l 4 --numeric
2085
```
