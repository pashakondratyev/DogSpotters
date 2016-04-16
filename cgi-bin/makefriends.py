#!/usr/bin/python
import cgi
import cgitb
cgitb.enable()
form = cgi.FieldStorage()
loggedInUser = form.getvalue("username")

print "Content-Type:text/html\r\n\r\n"
#Header of page
webpage = """
<!Doctype html>
<html>
<font face="Courier New" color: "0E3E05">
<title> Dogspotters </title>

<div><h1> Dogspotters! </h1></div>
<h3> Here are other people who like to spot dogs. Go connect with them! </h3>"""

#Here it should check if user is logged in
#Will implement
#Opens users.txt file
try: 
	users=open("../data/users.txt","r")
	usersList = users.readlines()
	index = 0
	webpage += '<form action="newfriends.py" method="post"><table>'
	while index in range(0, len(usersList)):
		username = usersList[index]
		webpage += "<tr><td>" + username +"</td>"
		index += 1
		index += 1
		webpage += "<td>" + usersList[index] +"</td>"
		index += 1
		index += 1
		webpage += '<td><input type="checkbox" name="newfriends" value=' + '"' + username + '"></td></tr>'
	webpage +='</table>'
	webpage +='<input type="hidden" name="username" value="' + loggedInUser + '">'
	webpage +='<input type="submit" Value="Add friends!"></form>'
	users.close()

except IOError:
	print("Cannot open file")



##Should return to dashboard using a hidden field to keep the username in hidden field
#Footer of the page
webpage +="""<style>
html{
background-color: linen;
}
div{
background-color: 8BBCFC;
width: 20000px;
padding:13px;
}
</style>
</html>"""
print webpage
