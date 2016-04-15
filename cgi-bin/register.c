#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

char file_username[MAXLEN];
char file_password[MAXLEN];
char file_fullname[MAXLEN];
char file_jobthing[MAXLEN];

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
		printf("<p>%s %s</p>", username, file_username);
		if(strcmp(username, file_username) == 0){
			fclose(fpointer);
			return 1;
		}
		fgets(file_password, MAXLEN, fpointer);
		fgets(file_fullname, MAXLEN, fpointer);
		fgets(file_jobthing, MAXLEN, fpointer);
	}while(feof(fpointer) == 0);
	
	fclose(fpointer);
	return 0;
}

/*registerUser
 *appends the user's information to the end of the users.txt file
 */
void registerUser(char *name, char *password, char *jobDescription, char *fullName){
	FILE *f = fopen(USERFILE, "a");
	fputs(name, f);
	fputs(password, f);
	fputs(jobDescription, f);
	fputs(fullName, f);
	fclose(f);
	//Should print a confirmation
}
int main(){
	
	int n = atoi(getenv("CONTENT_LENGTH"));
	char input[MAXINPUT];
	char username[MAXLEN], password[MAXLEN], fullname[MAXLEN], jobdescription[MAXLEN];
	fgets(input, n+1, stdin);
	sscanf(input, "username=%[^&]&password=%[^&]&fullname=%[^&]&jobdescription%s", username, password, fullname, jobdescription);
	unencode(password, password + strlen(password), password);
	unencode(username, username + strlen(username), username);
	unencode(fullname, fullname + strlen(fullname), fullname);
	unencode(jobdescription, jobdescription + strlen(jobdescription), jobdescription);	
	/*	Here we have the username and password variables	*/
	
	printf("Content-type: text/html\n\n");
	printf("<html>\n<body>");
/*	Check the users.txt for the username and password	*/	
	 
	if(validate_username(username) == 1){
		printf("<title>ERROR</title>");
		printf("<p>Username already exists, please create a unique username!</p>");
	}
	else{
		registerUser(username, password, jobdescription, fullname);
		printf("<title>Response</title>");
		printf("<p>Registration successful</p>");
		printf("</body>\n</html>");
	}
}
