#include <stdio.h>
#include "parse.h"
#include <stdlib.h>
#include <string.h>


int listFriends(char *myname){
/*lists all user names
allows you to chose one and bring up their profile*/

FILE *friends;
int MAXLEN=100;
char username[MAXLEN];

friends = fopen("../data/friends.txt","r");
if(friends == NULL){
	printf("<p>Error opening friend file</p>");
}

char ch = fgetc(friends);
if(ch == NULL){
        printf("LOL you have no friends. Go find some");
}


while(!feof(friends)){
	fgets(username,MAXLEN,friends);
	//get the usernames here
	if(strncmp(myname, username, strlen(myname)) == 0){
		printf(
	}

}



fclose(friends);
return 0;
}

int main(){
 
/*choose one friend to view*/
printf("To view a friend enter their number here:");
char *friend;
scanf("%s", friend);
system("../profile.c searchForUser(friend)");

return 0;
}
