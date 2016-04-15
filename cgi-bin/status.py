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
print "<title>VALIDATE STATUS</title>"

if not form["status"].value:
	print "nothing to show"
	#Return because it failed to validate
else:
	#append status to status.txt
#	print "<h4>something to show</h4>"
	print "<p>User: %s</p>" % form["username"].value
	print "<p>Status: %s</p>" % form["status"].value
	try:
		myfile = open("../data/status.txt", "a+")
		myfile.write("%s %s" % (form["username"].value, form["status"].value))
	except IOError:
		print "<p>Error opening file</p>"
	except:
		print "<p>other error</p>"
	finally:
		myfile.close()
	#go back to dashboard?
