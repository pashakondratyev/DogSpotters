#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include <string.h>

char file_username[MAXLEN];
char file_password[MAXLEN];
char file_fullname[MAXLEN];
char file_jobthing[MAXLEN];

/* 	scan users.txt to search for username and password	*/
int validate_credentials(char*username, char*password){
	FILE *fpointer;
	fpointer = fopen(USERFILE, "r");
	if(fpointer == NULL){
		printf("<p>ERROR: users.txt failed to open</p>");
	}
	do{
		fgets(file_username, MAXLEN, fpointer);
		fgets(file_password, MAXLEN, fpointer);

		if(strcmp(username, file_username) == 0 && 
		   strcmp(password, file_password) == 0){
			fclose(fpointer);
			return 1;
		}
		fgets(file_fullname, MAXLEN, fpointer);
		fgets(file_jobthing, MAXLEN, fpointer);
	}while(feof(fpointer) == 0);
	
	fclose(fpointer);
	return 0;
}


/*	unencode the username and password
	check if username and password exist in users.txt
	if success: load dashboard
	else return an error page (link back to home and login)
*/
int main(){
	
	int n = atoi(getenv("CONTENT_LENGTH"));
	char input[MAXINPUT], data[MAXINPUT];
	char username[MAXLEN], password[MAXLEN];
	fgets(input, n+1, stdin);
	sscanf(input, "username=%[^&]&password=%s", username, password);
	unencode(password, password + strlen(password), password);
	unencode(username, username + strlen(username), username);
/*	Here we have the username and password variables	*/
	
	printf("Content-type: text/html\n\n");
/*	Check the users.txt for the username and password	*/	
	 
	if(validate_credentials(username, password) == 0){
		FILE *f;
		f = fopen("../login-error.html", "r");
		if(f == NULL){
			printf("error opening error file");
		}
		char c;
		c = fgetc(f);
		while(feof(f) == 0){
			printf("%c",c);
			c = fgetc(f);
		}
	}
	else{
/*		FILE *f;
		f = fopen("../dashboard.html", "r");
		if(f == NULL){
			printf("error opening dashboard file");
		}
		char c;
		c = fgetc(f);
		while(feof(f) == 0){
			printf("%c",c);
			c = fgetc(f);
		}
*/		int pid = fork();
		if( pid == 0 ){
			// child process
			system("python dashboard.py");
		}
		else{
			return EXIT_SUCCESS;
		}
	}

}
