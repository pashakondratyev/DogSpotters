#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

char file_username[MAXLEN];
char file_password[MAXLEN];
char file_fullname[MAXLEN];
char file_favoritedog[MAXLEN];

/*validateUsername
 *Takes a *char name
 *Returns 1 if the username exists in the file
 *Returns 0 if the username does not yet exist in the file
 */
/* 	scan users.txt to search for username and password	*/
int validate_username(char*username){
	FILE *fpointer;
	fpointer = fopen(USERFILE, "r");
	if(fpointer == NULL){
		printf("<p>ERROR: users.txt failed to open</p>");
	}
	do{
		fgets(file_username, MAXLEN, fpointer);
		if(strcmp(username, file_username) == 0){
			fclose(fpointer);
			return 1;
		}
		fgets(file_password, MAXLEN, fpointer);
		fgets(file_fullname, MAXLEN, fpointer);
		fgets(file_favoritedog, MAXLEN, fpointer);
	}while(feof(fpointer) == 0);
	
	fclose(fpointer);
	return 0;
}

/*registerUser
 *appends the user's information to the end of the users.txt file
 */
void registerUser(char *name, char *password, char *favoritedog, char *fullName){
	FILE *f = fopen(USERFILE, "a");
	fputs(name, f);
	fputs(password, f);
	fputs(favoritedog, f);
	fputs(fullName, f);
	fclose(f);
	//Should print a confirmation
}
int main(){
	
	int n = atoi(getenv("CONTENT_LENGTH"));
	char input[MAXINPUT];
	char username[MAXLEN], password[MAXLEN], fullname[MAXLEN], favoritedog[MAXLEN];
	fgets(input, n+1, stdin);
	sscanf(input, "username=%[^&]&password=%[^&]&fullname=%[^&]&favoritedog=%s", username, password, fullname, favoritedog);
	unencode(password, password + strlen(password), password);
	unencode(username, username + strlen(username), username);
	unencode(fullname, fullname + strlen(fullname), fullname);
	unencode(favoritedog, favoritedog + strlen(favoritedog), favoritedog);	
	/*	Here we have the username and password variables	*/
	
	printf("Content-type: text/html\n\n");
/*	Check the users.txt for the username and password	*/	
	 
	if(validate_username(username) == 1){
		FILE *f;
		f=fopen("../register-error.html", "r");
		if(f == NULL){
			printf("<p>Error opening the error file</p>");
		}
		char c;
		c=fgetc(f);
		while(feof(f) == 0){
			printf("%c",c);
			c= fgetc(f);
		}
	}
	else{
		registerUser(username, password, favoritedog, fullname);
		FILE *f;
		f=fopen("../register-success.html", "r");
		if(f == NULL){
			printf("<p>Error opening the error file</p>");
		}
		char c;
		c=fgetc(f);
		while(feof(f) == 0){
			printf("%c",c);
			c= fgetc(f);
		}
	}
}
