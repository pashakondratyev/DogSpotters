/*generate profile*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse.h"

char file_username[MAXLEN];
char file_password[MAXLEN];
char file_fullname[MAXLEN];
char file_favoritedog[MAXLEN];

int searchForUser (char *user){
	/* need to display:
	>username :every 1st line
	>fullname : every 3rd line
	>fav dog  :every 4th line*/

	FILE *users;
	char username[MAXLEN];
	strcat(username, user);
	users = fopen(USERFILE, "r");
	if(users == NULL){
		printf("<p>ERROR: users.txt failed to open</p>");
	}
	do{
		fgets(file_username, MAXLEN, users);
		fgets(file_password, MAXLEN, users);
		fgets(file_fullname, MAXLEN, users);
		fgets(file_favoritedog, MAXLEN, users);
		
		if(strncmp(user, file_username, strlen(user)) == 0){
			fclose(users);
		return 1;
		}		
	}while(feof(users) == 0);	
	fclose(users);
	return 0;
}
int main(){
	int n = atoi(getenv("CONTENT_LENGTH"));
	char input[MAXINPUT];
	char username[MAXLEN];
	char name[MAXLEN];
	fgets(input, n+1, stdin);
	sscanf(input, "user=%[^&]&username=%[^&]", name, username);
	unencode(username, username + strlen(username), username);
	unencode(name, name + strlen(name), name);
	printf("content-type: text/html\n\n");
	printf("<!Doctype html>");
	searchForUser(name);
	printf("Username: %s \n",file_username);
	printf("Name: %s \n", file_fullname);
	printf("Favorite Dog: %s \n", file_favoritedog);
	return 0;
}

