# importing module and library required
from scipy.fftpack import fft, fftfreq, fftshift
from scipy.fftpack import dct, idct
import numpy as np
import matplotlib.pyplot as plt

f = 0.1
Fs = 10
t = np.linspace(-10,10,Fs*20)
s = np.cos(2*np.pi*f*t)

# Take fft
U = np.fft.fft(s)

# Transform again
u_t = np.fft.fft(U)

# Reverse and normalize

s_new = np.divide(u_t[-np.arange(u_t.shape[0])],s.shape[-1])

# Finally slice for easier viewing
plt.figure(figsize=(12,4))
plt.grid()
plt.plot(t,s_new)
plt.show()
plt.figure(figsize=(12,4))
plt.grid()
plt.plot(t,s)
plt.show()










exit(1)

# importing module and library required
from scipy.fftpack import fft, fftfreq, fftshift
from scipy.fftpack import dct, idct
import numpy as np
import matplotlib.pyplot as plt

#definisco gli estremi di campionamento della funzione
inizio_funzione_tempo = -10
fine_funzione_tempo = 10
N = 4000 #numero di campioni


#definisco le funzioni nel tempo
def funzione_gradino(x):
	if (x>=0):
		return 1
	return 0
	
a = 0
b = 2

def funzione_porta(x):
	print(x)
	if (x<=a):
		return 0
	if (x>=b):
		return 0
	return 1

k = 2

def funzione_costante(x):
	return k

gradino = np.vectorize(funzione_gradino)
porta = np.vectorize(funzione_porta)
costante = np.vectorize(funzione_costante)

# frequenza di campionamento
x1 = np.linspace(inizio_funzione_tempo,fine_funzione_tempo, N)
x2 = np.linspace(inizio_funzione_tempo,fine_funzione_tempo, N)

y1 = porta(x1)
y2 = costante(x2)

conv = np.convolve(y1, y2)

y3 = np.multiply(y1,y2)

yf = fft(y1)
xf = fftfreq(N, 1)
xf = fftshift(xf)
yplot = fftshift(yf)
inverted_function = np.fft.ifft(xf)

plt.plot(inverted_function, 1.0/N * np.abs(yplot))
plt.grid()
plt.show()






















