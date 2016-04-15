/*generate profile*/
#include <stdlib.h>
#include <stdio.h>
int main (int argc,char *username){

/* need to display:
>username
>fullname
>fav dog*/
/*needs to read username and generate a profile accordingly
 these are random profiles i guess
*/


char *firstname[10];
char *lastname[10];
char *dog[10];

firstname[]={Rosa,Darrell,Barden,Deeb,Augustus,Mary,Jane,Alec,Park,Jack};
lastname[]={Flannery,Rude,Hansford,Grogg,Callejas,Rivers,Anaya,Mcvea,Gordan,Barboza};
dog[]={Akita,Basset,Basenji,Chihuahua,Collie,Dachsund,Dalmation,Whippet,Husky,Pug};

int n= rand()%10;
prinf("%s\n %s %s\n %s\n", username, firstname[n], lastname[n],dog[n]);

return 0;
}
