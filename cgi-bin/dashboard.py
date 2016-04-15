#!/usr/bin/python
"""
THIS IS THE DASHBOARD.PY PROGRAM
"""
import cgi
import sys
import cgitb
cgitb.enable()

username = sys.argv[1]
def make_html():
	print "<!Doctype html>\n<html><body>\n"
	print """
	<title>Dashboard</title>
	<ul>
		<li><a href="../index.html">logout</a></li>
		<li>
		<form action="makefriends.py" method="post">
			<input type="hidden" name="username" value = %s></input><input type="submit" value="make a friend"</input>
		</form>
		</li>
		<li>
		<form action="seefriends.c" method="post">
			<input type="hidden" name="username" value = %s></input><input type="submit" value="see a friend"</input>
		</form>
		</li>

	</ul>
	""" % (username, username )
	print """
	<form action="status.py" method="post">
	<input type="hidden" name="username" value="%s">
	<textarea name="status" cols=40 rows=6></textarea>
	</br>
	<input type="submit" name="submit"></input>
	</form>
	""" % username

make_html()
"""
#read lines from status, store them into an array
try:
	myfile = open("../data/status.py", "r")
	lines = myfile.readlines()
	i = 0
	while i in range(0, len(lines)):
		
except:
	print "cannot open file"
finally:
	myfile.close()
"""
