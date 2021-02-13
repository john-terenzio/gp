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
usage: gp [-l <int>] [-n <int>] [--pin] [--nouppers] [--nolowers] [--nodigits] [--nosymbols]
$ gp
YQ6Lu*ufE18T
$ gp -l 8
^v72DJHx
$ gp -n 3
ooSPoREV-q^2
Fizcd&d%wLd5
B^pPcE08BU+3
$ gp --nosymbols
ygIrFoUL4MHo
$ gp --pin
6860
```
