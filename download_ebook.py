import bs4
import urllib2
from bs4 import BeautifulSoup as soup

file_d = open("file_downloads")

# leggo le linee del file e le metto in una lista
strings = file_d.readlines()

# faccio il mapping per ogni elemento dell'elemento
# a cui applico la funzione strip partendo dall'
# indirizzo della funzione strip
map(lambda it: it.strip(), strings)

for s in strings:
    try:
        file_url_download = open('url_downloads', 'a+')
        # you must setting up connections setting, like
        # data sent, header ecc ecc...
        url_request = urllib2.Request(url=s)

        content_http = urllib2.urlopen(url_request).read()

        # primo parametro il contenuto, secondo il tipo di
        # parsing
        page_soup = soup(content_http, "html.parser")

        ebooks = page_soup.find("span", {"class": "download-links"})
        file_url_download.write(ebooks.a["href"] + str("\n"))
        file_url_download.close()
    except Exception as e:
        continue
