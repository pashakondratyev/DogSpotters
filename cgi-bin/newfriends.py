#!/usr/bin/python
import cgi
import cgitb
cgitb.enable()
form = cgi.FieldStorage()

#Username of currently logged in user, needs an error
#if not logged in
loggedInUser = form.getvalue("username")

#Gets a list of all the user it needs to add
toAdd = form.getlist("newfriends")

print "Content-Type:text/html\r\n\r\n"
#Header of page
webpage = """
<!Doctype html>
<html>
<font face="Courier New" color: "0E3E05">
<title> Dogspotters </title>

<div><h1> Dogspotters! </h1></div>"""

#Around here it should check if the user is logged in properly

#Here it adds the friends


