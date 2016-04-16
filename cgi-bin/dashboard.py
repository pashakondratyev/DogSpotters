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

#read lines from status, store them into an array
status_to_show = []
try:
	friend_file = open("../data/friends.txt", "r")
	friend_line = friend_file.readlines()
	def find_friends(user_to_search):
		i = 0
		while i in range(0, len(friend_line)):
			first_space = friend_line[i].find(" ")
			if( friend_line[i][:first_space] == user_to_search):
				return friend_line[i][first_space:]
			i+=1
	#now have an array with all the usernames
	user_friends = find_friends(username)
	array_friends = user_friends.split()

	print "<p>FRIENDS: %s</p>" % user_friends
	print "<p>ARRAY:</p>"
	for friend in array_friends:
		print "<p>%s\n</p>" % friend
	"""
	status_file = open("../data/status.txt", "r")
	line = status_file.readlines()
	i = 0
	while i in range(0, len(line)):
		first_space = line[i].find(" ")
		if(line[i][:first_space] is in array_friends or
		   line[i][:first_space] == username):
			status_to_show.append(line[i])
		i+=1
	print status_to_show
	#now have array with all relevant stati
#	for i in range(0,20):
#		print status_to_show[len(status_to_show) - i]
"""
except:
	print "cannot open file"
finally:
#	status_file.close()
	friend_file.close()
print"</body></html>"

