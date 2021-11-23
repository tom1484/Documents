import random as rd

N = 100000
modes = ['insert ', 'delete ', 'query ']
nums = set()

print(N)
for i in range(N):
	s = ''
	mode = rd.randint(0, 2)
	while len(nums) == 0 and (mode == 1 or mode == 2):
		mode = rd.randint(0, 2)
	s += modes[mode]
	if mode == 0:
		num = rd.randint(-1000000000, 1000000000)
		nums.add(num)
		s += str(num)
	elif mode == 1:
		num = rd.choice(tuple(nums))
		nums.remove(num)
		s += str(num)
	else:
		num = rd.randint(-1000000000, 1000000000)
		s += str(num)
	print(s)
