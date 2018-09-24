def gauss_sum(x,pow):
	if(pow <= 0):
		return 1
	
	return x**pow+gauss_sum(x, pow-1)
	

# sum from k into (0,n) (x^n) = x^(n+1)-1/abs(x-1)
print((7**65-1)/(7-1))


print(gauss_sum(7, 64))

print((7**65-1)/(7-1)/gauss_sum(7, 64))