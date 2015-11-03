server: tcp_server_select.c boningen.o game.o inet.h tcp_client.c
	gcc -O2 tcp_server_select.c boningen.o game.o -o server
	gcc -O2 tcp_client.c boningen.o game.o -o client
boningen.o: boningen.c boningen.h
	gcc -O2 -c boningen.c
game.o: game.h game.c
	gcc -O2 -c game.c
