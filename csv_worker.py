import csv
import sys

print("opening " + sys.argv[1])

with open(sys.argv[1], 'rb') as csvfile:
	spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
	for row in spamreader:
		print ', '.join(row)