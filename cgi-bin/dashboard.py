#!/usr/bin/python
"""
THIS IS THE DASHBOARD.PY PROGRAM
"""
import cgi
import sys
import cgitb
cgitb.enable()

#make username either from login.c or from post

form = cgi.FieldStorage()
if len(sys.argv) > 1:
	username = sys.argv[1]

else:
	print "Content-Type:text/html\r\n\r\n"
	username = form.getvalue("username")

def make_html():
	print "<!Doctype html>\n<html><body>\n"
	print """
	<title>Dashboard</title>
	<ul>
		<li><a href="../index.html">logout</a></li>
		<li>
		<form action="makefriends.py" method="post">
			<input type="hidden" name="username" value ="%s"></input><input type="submit" value="make a friend"</input>
		</form>
		</li>
		<li>
		<form action="./seefriends.cgi" method="post">
			<input type="hidden" name="username" value ="%s"></input><input type="submit" value="see a friend"</input>
		</form>
		</li>

	</ul>
	""" % (username, username )
	print """
	<form action="status.py" method="get">
	<input type="hidden" name="username" value="%s">
	<textarea name="status" cols=40 rows=6></textarea>
	</br>
	<input type="submit" name="submit"></input>
	</form>
	""" % username

make_html()
#read lines from status, store them into an array
try:
	friend_file = open("../data/friends.txt", "r")
	friend_list = friend_file.read().splitlines()
	friend_file.close()
	#Gets friendslist where 0th index is user
	for line in friend_list:
		splitLine = line.split()
		if splitLine[0] == username:
			break
	friend_list = splitLine
	status_file = open("../data/status.txt", "r")
	status_list = status_file.read().splitlines()
	status_file.close()
	statusToDisplay = []
	for line in status_list:
		splitLine = line.split()
		if(splitLine[0] in friend_list):
			statusToDisplay.append(line)
	for i in range(0,20):
		display = statusToDisplay.pop()
		print "<p>%s</p>" % display

except:
	print "cannot open file"

print"</body></html>"
