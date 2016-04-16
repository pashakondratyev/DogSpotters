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
	print "<p>User: %s</p>" % form.getvalue("username")
	print "<p>Status: %s</p>" % form.getvalue("status")
	username = form.getvalue("username")
	username = username.replace('\r','').replace('\n','')
	try:
		status_file = open("../status.html", "r")
		for lines in status_file:
			printf lines
	except:
		print "can't open the style sheet"
	finally:
		status_file.close()
	try:
		myfile = open("../data/status.txt", "a+")
		myfile.write("%s %s\n" % (username, form.getvalue("status")))
	except IOError:
		print "<p>Error opening file</p>"
	except:
		print "<p>other error</p>"
	finally:
		myfile.close()
	#go back to dashboard?
	print """
	<form action="dashboard.py" method="get">
	<input type="hidden" name="username" value="%s"></input>
	<input type="submit" value="see your post!"></input>
	</form>
	""" % username
