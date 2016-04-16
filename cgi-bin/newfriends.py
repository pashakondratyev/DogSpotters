#!/usr/bin/python
import cgi
import cgitb
cgitb.enable()
form = cgi.FieldStorage()

#Username of currently logged in user, needs an error
#if not logged in
loggedInUser = form.getvalue("username")
loggedInUser.replace("%0D%0A","")

#Gets a list of all the user it needs to add
#And cleans up the input getting rid of the extra spaces
toAdd = form.getlist("newfriends")
tempString = ' '.join(toAdd)
tempString.replace("%0D%0A","")
toAdd = tempString.split()

print "Content-Type:text/html\r\n\r\n"
#Header of page
print """
<!Doctype html>
<html>
<font face="Courier New" color: "0E3E05">
<title> Dogspotters </title>
<div><h1> Dogspotters! </h1></div>"""

#Around here it should check if the user is logged in properly

def addFriends():
	#Here it adds the friends
	try:
		friendsFile=open("../data/friends.txt","r")
		friendsList = friendsFile.read().splitlines();
		toEdit = friendsList
		friendsFile.close();
		lineNumber = 0
		for line in friendsList:
			splitLine = line.split()
			if splitLine[0].replace('\r','').replace('\n','') == loggedInUser.replace('\r','').replace('\n',''):
				break
			lineNumber += 1
		for name in toAdd:
			if (name not in splitLine):
				splitLine.append(name)
		#SplitLine will contain all users
		newFriends = ' '.join(splitLine)
		toEdit[lineNumber] = newFriends
		friendsFile=open("../data/friends.txt","wb")
		for line in toEdit:
			friendsFile.write(line+"\n")
		friendsFile.close()
	except IOError:
		print("Error opening file??")

#Runs add friends 
addFriends()

#Builds the body and adds it to the webpage
body = """
<H1>Friends Added!</H1>
<form action="dashboard.py" method ="get">
	<input type="hidden" name ="username" value= %s></input>
	<input type="submit" value="Back to Dashboard"></input>
</form>
""" % loggedInUser

webpage = body

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
