#include <stdio.h>

int main(int argc){
/*lists all user names
allows you to chose one and bring up their profile*/

FILE *friends;
int ch,count=0;
do 
{
    ch = fgetc(friends);
    if(ch == ' ')
    	count++;
} while (ch != EOF);

char *usernames[count];

friends=fopen("../data/friends.txt","r");
if(count=1)
	printf("LOL you have no friends. Go find some");
else
	int x;
	for(x=1; x<count; x++)
		fgets(usernames,count,friends);
		printf("%d. %s \n", x, usernames[x]);
fclose(friends);

/*choose one friend to view*/
printf("To view a friend enter their number here:");
int numfriend;
scanf("%d", &numfriend);
system("../profile.c username[numfriend]");

return 0;
}
