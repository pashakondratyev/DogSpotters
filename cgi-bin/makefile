#Makefile

all : 
	chmod 755 *
	chmod 755 ../*
	chmod 755 ../data/*

profile.cgi : profile.c 
	gcc -g -o profile.cgi profile.c

login.cgi : login.c parse.h
	gcc -g -o login.cgi login.c

register.cgi : register.c parse.h
	gcc -g -o register.cgi register.c

seefriends.cgi : seefriends.c
	gcc -g -o seefriends.cgi seefriends.c

cleanFiles : 
	rm ../data/*

makeEmpty :
	touch ../data/friends.txt
	touch ../data/users.txt
	touch ../data/status.txt
