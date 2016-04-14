#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
#define EXTRA 10
#define MAXINPUT MAXLEN+EXTRA
#define USERFILE "../data/users.txt"

/*validateUsername
 *Takes a *char name
 *Returns 1 if the username exists in the file
 *Returns 0 if the username does not yet exist in the file
 */
int validateUsername(char *name){
	FILE *f = fopen(USERFILE, "r");
	char *currentLine;
	//These are not necessary pointers, but
	//make keeping track of the current line much easier
	char *username = fgets(currentLine, MAXLEN, f);
	char *password = fgets(currentLine, MAXLEN, f);
	char *fullName = fgets(currentLine, MAXLEN, f);
	char *jobDescription = fgets(currentLine, MAXLEN, f);
	while(currentLine != NULL){
		if(strcmp(name, username) == 0 ){
			fclose(f); 
			return 1;
		}
		else{
			char *username = fgets(currentLine, MAXLEN, f);
			char *password = fgets(currentLine, MAXLEN, f);
			char *fullName = fgets(currentLine, MAXLEN, f);
			char *jobDescription = fgets(currentLine, MAXLEN, f);		
		}
	}
	fclose(f);
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
	fputs(fullname, f);
	fclose(f);
	//Should print a confirmation
}

void unencode(char *src, char *last, char *dest){
 for(; src != last; src++, dest++)
    if(*src == '+') *dest = ' ';
    else if(*src == '%') {
	int code;
	if(sscanf(src+1, "%2x", &code) != 1) code = '?';
		*dest = code;
		src +=2;}
	     
	else *dest = *src;
	*dest = '\n';
	*++dest = '\0';
 }


int main(){
 char *lenstr;
 char input[MAXINPUT], data[MAXINPUT];
 long len;
 printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
 printf("<TITLE>Response</TITLE>\n");
 lenstr = getenv("CONTENT_LENGTH");
 if(lenstr == NULL || sscanf(lenstr,"%ld",&len)!=1 || len > MAXLEN)
 printf("<P>Error in invocation - wrong FORM probably.");
 else {
	fgets(input, len+1, stdin);
	unencode(input+EXTRA, input+len, data);
	printf("<P>Thank you! Your contribution has been stored.");
 }
 return 0;
}
