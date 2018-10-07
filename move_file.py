import glob
import time
from random import randint
import os

for i in range(0,1000):
	for f in glob.glob("/Volumes/RAM Disk/*.pdf"):
		last_file=f[0:f.rfind("/")]
		cmd = "mv " + "\"" + str(f) + "\" \"" + last_file + "/temps/" + str(randint(0, 100000000)) + ".pdf\""
		os.system(cmd)

	time.sleep(1)