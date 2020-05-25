
def fact(n):
	ans = 1;
	for int i in range(1, n + 1):
		ans = ans * i;
	return ans;


n = input()
ans = fact(n)
print(ans)