import bs4
import urllib2
from bs4 import BeautifulSoup as soup

# per il printing degli url di download
for i in range(1, 731):
    url = "http://www.allitebooks.com/page/"
    url = url + str(i) + "/"

    # you must setting up connections setting, like
    # data sent, header ecc ecc...
    url_request = urllib2.Request(url=url)

    content_http = urllib2.urlopen(url_request).read()

    # primo parametro il contenuto, secondo il tipo di
    # parsing
    page_soup = soup(content_http, "html.parser")

    ebooks = page_soup.findAll("article")

    for ebook in ebooks:
        print(ebook.find("div", {"class": "entry-body"}).header.h2.a["href"])
