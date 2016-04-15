#!/usr/bin/python
"""
THIS IS THE DASHBOARD.PY PROGRAM
"""
import cgi
import sys
import cgitb
cgitb.enable()

username = sys.argv[1]
#print username
print "<!Doctype html>\n<html><body>\n"
#print "<input type="hidden" name="username" value="%s">" % username
"""try:
	file_name = "../dashboard.html"
	input_file = open(file_name, "r")
	lines=input_file.readlines()
	i = 0
	while i in range(0, len(lines)):
		print lines[i]
		i += 1
except:
	print "<p> Cannot open file! </p>"
finally:
	input_file.close()
"""
print """
	<title>Dashboard</title>
	<ul>
		<li>logout</li>
		<li>make a friend</li>
		<li>see a friend</li>
	</ul>
	<form action="status.py" method="post">
	<input type="hidden" name="username" value="%s">
	<textarea name="status" cols=40 rows=6></textarea>
	</br>
	<input type="submit" name="submit"></input>
	</form>
	""" % username
