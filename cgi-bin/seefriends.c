#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int findFriends(char *myname){
/*lists all user names
allows you to chose one and bring up their profile*/

FILE *friends;
int count=0;
char ch;
char *usernames[10];

friends = fopen("../data/friends.txt","r");
if(friends == NULL){
	printf("<p>Error opening friend file</p>");
}
ch = fgetc(friends);
while(!feof(friends)){
	//get the usernames here
	
}
if(ch == NULL){
        printf("LOL you have no friends. Go find some");
    }   


	
	fscanf(friends,"%s %s %s",usernames[0],usernames[1],usernames[2]);
	printf("%s %s %s",usernames[0],usernames[1],usernames[2]);

	/*if(ch =='\n'){
    	break;
	}*/



fclose(friends);

/*choose one friend to view*/
printf("To view a friend enter their number here:");
char *friend;
scanf("%s", friend);
system("../profile.c searchForUser(friend)");

return 0;
}
