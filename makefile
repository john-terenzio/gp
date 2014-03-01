gp: stringrand.c gp.c
	cc -std=c99 -Wall -O2 gp.c main.c stringrand.c -o gp && strip gp

install:
	mkdir -p /usr/local/bin/
	cp gp /usr/local/bin/gp

uninstall:
	rm /usr/local/bin/gp

clean:
	rm gp
