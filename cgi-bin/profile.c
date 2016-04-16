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
	printf("<html> <body>");
	searchForUser(name);
	printf("<p>Username: %s</p>",file_username);
	printf("<p>Name: %s </p>", file_fullname);
	printf("<p>Favorite Dog: %s </p>", file_favoritedog);
	//Add a return button
	
	printf("<form action=\"seefriends.cgi\" method=\"post\">");
	printf("<input type=\"hidden\" name=\"username\" value=\"%s\">", username);
	printf("</input><input type=\"submit\" value=\"Go Back\"></input>");
	printf("</form>");
	printf("</body></html>");


	// Put in the style sheet
	FILE *fpointer;
	fpointer = fopen("../style.html", "r");
	if(fpointer == NULL){
		printf("<p>error</p>");
	}
	char c;
	c = fgetc(fpointer);
	while(feof(fpointer) == 0){
		printf("%c",c);
		c = fgetc(fpointer);
	}
	fclose(fpointer);
	return 0;

}

