#!/usr/local/bin/python3.6


def bin_to_dec(binary_vector,size,x):
	if (size<=0):
		return 0
	
	return binary_vector[x]*(2**(size-1)) + bin_to_dec(binary_vector, size-1,x+1)


def print_subnet_mask(size):
	vect = []
	printed = 0
	for x in range(0,size):
		if (x>0 and x%8==0):
			printed+=1
			print(str(bin_to_dec(vect, 8, 0)) + ".",end="")
			vect = []
		vect.append(1)
		
	if (len(vect) > 0):
		while len(vect) < 9:
			vect.append(0)
		
		printed+=1
		print(str(bin_to_dec(vect, 8, 0)) + ".",end="")
			
		
	while printed < 4:
		printed+=1
		print(str(bin_to_dec([0,0,0,0,0,0,0,0], 8, 0)),end="")
		if printed < 4:
			print(".",end="")
	print("")
	
print("digita il numero che rappresenta la subnetmask: ")
text = input()
print("subnetmask: ",end="")
print_subnet_mask(int(text))
