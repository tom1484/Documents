a = 0

def f():
	global a
	a += 1
	return True

def check(i):
	return i % 3 == 0

# a = 1

# def f():
# 	global a
# 	a *= 2
# 	return True

# def check(i):
# 	return True

N = 10000
M = 950

def r(i, I):
	return (i <= I and i <= N) and ((check(i) and f() or True) and r(i + 1, I))

def R(i, I):
	return i <= I and ((r(i * M, (i + 1) * M - 1) or True) and R(i + 1, I))

R(0, N // M)
print(a)