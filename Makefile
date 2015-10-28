server: tcp_server_select.c boningen.o game.o
	gcc -O2 tcp_server_select.c boningen.o game.o -o server
boningen.o: boningen.c boningen.h
	gcc -O2 -c boningen.c
game.o: game.h game.c
	gcc -O2 -c game.c
