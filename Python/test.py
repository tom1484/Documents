A = "F G H I J K L M N O P Q R S T U V W X Y Z AA AB".split(' ')
R = ""
for i in range(31):
	c = input()
	if c == "":
		R += "\n"
	else:
		n = int(c)
		R += A[n] + "\n"
print(R)