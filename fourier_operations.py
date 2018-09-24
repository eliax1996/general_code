import math

def downscale_vector(vector,final_size):
	i = -2
	vector_t = []
	
	for j in range(0,final_size):
		i = i + 2
		vector_t.append(vector[i])
		
	vector = vector_t
	return vector
	
def center_convolution(vector,final_size,second_vector):
	start = 0
	end = len(vector)-1
	continua = True
	
	while continua:
		if (vector[start] != 0):
			continua = False
		else:
			start = start + 1
	
	continua = True
	
	while continua:
		if (vector[end] != 0):
			continua = False
		else:
			end = end - 1
			
	# centrato rispetto al secondo vettore
	
	da_aggiungere = final_size - (end - start)
	ret = []
	
	for i in range(0,int(da_aggiungere/2)):
		ret.append(0)
		
	for i in range(0,end-start):
		ret.append(vector[i+start])
	
	for i in range(0,int(da_aggiungere/2)):
		ret.append(0)
		
	if len(ret) != final_size:
		ret.append(0)
		
	return ret
		

def upscale_vector(vector,final_size):
	size = len(vector)
	for i in range(0,final_size-size):
		vector.append(0)

# c(k) = integrale(x(k)*x(-k+r))
def linear_convolution(vector_1,vector_2):
	
	len_1 = len(vector_1)
	len_2 = len(vector_2)
	
	if (len(vector_1) > len(vector_2)):
		size = 2*len(vector_1)
		upscale_vector(vector_1, size)
		upscale_vector(vector_2, size)
	else:
		size = 2*len(vector_2)
		upscale_vector(vector_1, size)
		upscale_vector(vector_2, size)
	
	result = []
	
	iniziato = False
	da_appendere = 0
	
	print(len(vector_1))
	
	for i in range(0,size):
		sum = 0
		for j in range(0,size):
			sum = sum + vector_1[j]*vector_2[(-j+i)]
		result.append(sum)
		
	for i in range(0,size-len_1):
		vector_1.pop()
	
	for i in range(0,size-len_2):
		vector_2.pop()
	
	return downscale_vector(result, int(size/2))
	
