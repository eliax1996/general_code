import urllib2
import threading

# funzione di download


def download_ebook(url):
    try:
        PDFfile = urllib2.urlopen(url)

        k = url.rfind("/")
        name = url[k + 1:]

        with open(name.replace('?', ''), 'wb') as output:
            output.write(PDFfile.read())
    except:
        print("non sono riuscito a scaricare -->  " + url)


# esecuzione dei thread
file = open("url_downloads")
threads = []
max_thread = 5
actual_thread = 0

for line in file:
    download_ebook(line)
#    actual_thread += 1

#    if (actual_thread == 5):
#        for i in range(0, actual_thread):
#            t = threads.pop
#            t.join()

#        actual_thread = 1

#    t = threading.Thread(target=download_ebook, args=(line,))
#    threads.append(t)
#    t.start()


#mp3file = urllib2.urlopen()

# with open('JavaFX 9 by Example, 3rd Edition.pdf', 'wb') as output:
#    output.write(mp3file.read())
