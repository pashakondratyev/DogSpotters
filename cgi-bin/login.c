#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100
#define EXTRA 10
#define MAXINPUT MAXLEN+EXTRA
#define USERFILE "../data/users.txt"


void unencode(char *src, char *last, char *dest)
{
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
 	FILE *f;
	fgets(input, len+1, stdin);
	unencode(input+EXTRA, input+len, data);
	f = fopen(DATAFILE, "a");
	if(f == NULL) printf("<P>Sorry, cannot store your data.");
	else fputs(data, f);
	fclose(f);
	printf("<P>Thank you! Your contribution has been stored.");
 }
 return 0;
}
