#define MAXLEN 100
#define EXTRA 10
#define MAXINPUT MAXLEN+EXTRA
#define USERFILE "../data/users.txt"
#define VARLEN 8

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


