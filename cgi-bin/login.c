#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100
#define EXTRA 10
#define MAXINPUT MAXLEN+EXTRA
#define USERFILE "../data/users.txt"
#define VARLEN 8
#include <string.h>


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

/*	unencode the username and password
	check if username and password exist in users.txt
	if success: load dashboard
	else return an error page (link back to home and login)
*/
int main(){
	
	int n = atoi(getenv("CONTENT_LENGTH"));
	char input[MAXINPUT], data[MAXINPUT];
	char username[MAXLEN], password[MAXLEN];
	fgets(input, n+1, stdin);
	sscanf(input, "username=%[^&]&password=%s", username, password);
	char *password_var = strstr(username, "&password=");
	unencode(password, password + strlen(password), password);
	unencode(username, username + strlen(username), username);
	printf("Content-type: text/html\n\n");
	printf("<html>\n<body>");
	printf("<title>Response</title>");
	printf("<p>input: %s</p>", input);
	printf("<p>username: %s</p>",username);
	printf("<p>password: %s</p>",password);
	printf("</body>\n</html>");
}
