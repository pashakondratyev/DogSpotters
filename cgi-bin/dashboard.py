import cgi

#print "Content-type: text/html \n\n"

try:
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

