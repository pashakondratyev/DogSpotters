/*generate profile*/
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
int searchForUser (char *user){

/* need to display:
>username :every 1st line
>fullname : every 3rd line
>fav dog  :every 4th line*/
/*needs to read username and generate a profile accordingly
 these are random profiles i guess
*/
char temp[500];
char line[500];
char *name;
char *dog;
int numline, count, linename, linedog;

FILE *users; 
fopen("users.txt", "r");
while(fgets(temp,500,users) != NULL){
	if((strstr(temp,user)) != NULL) {
		linename=numline+2;
		linedog=numline+3;
		break;
	}
	numline++;
}
while(fgets(line,sizeof(line),users) != NULL){
	if(count==numline){
		printf("Username: %s \n",line);
	}
 	if(count==linename){
		printf("Name: %s \n", line);
        }
 	if(count==linedog){
		printf("Favorite Dog: %s \n",ling);
        }
	count++;
}
fclose(users);

return 0;
}
