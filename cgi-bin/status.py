#! /usr/bin/python
"""
THIS IS THE STATUS PROGRAM
"""
import cgitb
import cgi
import sys
cgitb.enable()

form = cgi.FieldStorage(keep_blank_values=1)

print "Content-type: text/html \r\n\r\n"
print "<title>CGI output</title>"
print "<p>Something</p>"

if not form["status"].value:
	print "nothing to show"
	#Return because it failed to validate
else:
	#append status to status.txt
	print "something to show"
	print form["username"].value

