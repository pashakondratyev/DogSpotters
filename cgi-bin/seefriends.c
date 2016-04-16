#include <stdio.h>
#include <string.h>
#include "parse.h"

int listFriends(char* name){
	/*lists all user names
	allows you to chose one and bring up their profile*/

	FILE *fpointer;
	fpointer = fopen("../data/friends.txt", "r");
	if(fpointer == NULL){
		printf("<p>Error: friends.txt failed to open</p>");
	}
	char tempString[MAXLEN*100];
	char *userName;
	char *tempName;
	printf("<form action=\"profile.cgi\" method=\"post\"><table>");
	do{
		fgets(tempString, MAXLEN * 100, fpointer);
		tempName = strtok(tempString," ");
		if(strncmp(tempName,name, strlen(tempName)) == 0){
			while(tempName != NULL){
				printf("<tr><td><input type=\"radio\" name=\"user\" value=\"%s\"></td><td>%s</input></td></tr>",tempName, tempName);
				tempName = strtok(NULL," ");
			}
		}
	}while(feof(fpointer)==0);
	printf("<input type=\"hidden\" name=\"username\" value=\"%s\"></input>",name);
	printf("<input type=\"submit\" value=\"See profile!\"></input>");
	printf("</form>");
	return 0;
}

int main(){
	int n = atoi(getenv("CONTENT_LENGTH"));
	char input[MAXINPUT];
	char username[MAXLEN];
	fgets(input, n+1, stdin);
	sscanf(input, "username=%[^&]", username);
	unencode(username, username + strlen(username), username);
	printf("content-type: text/html\n\n");
	printf("<!Doctype html>");
	listFriends(username);
	return 0;
	/*

choose one friend to view
printf("To view a friend enter their number here:");
int numfriend;
scanf("%d", &numfriend);
system("../profile.c username[numfriend]");

return 0;
*/
}
