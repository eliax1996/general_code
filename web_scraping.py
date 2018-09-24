import urllib2
from bs4 import BeautifulSoup
import wget
import img2pdf
import os


web_page = "http://ww1.read7deadlysins.com/chapter/nanatsu-no-taizai-chapter-"
pages = []

for x in range(1, 236):
    str = "%03d" % x
    pages.append(web_page + str + "/")


# per mandare affanculo il controllo che tu non sia un robot
hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
       'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
       'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
       'Accept-Encoding': 'none',
       'Accept-Language': 'en-US,en;q=0.8',
       'Connection': 'keep-alive'}

x = 0

for page in pages:
    print("scarico: " + page)
    req = urllib2.Request(page, headers=hdr)
    x = x + 1
    page = urllib2.urlopen(req)

    soup = BeautifulSoup(page)

    immagini = soup.find_all("img")

    immagini_da_comprimere = []

    for immagine in immagini:
        img = immagine['src']
        # if ('http://2.bp.blogspot.com' in img): per evitare porcate ma chissene
        if ('.gif' not in img):
            filename = wget.download(img)
            immagini_da_comprimere.append(filename)

    with open("capitolo" + "%03d" % x + ".pdf", "wb") as f:
        f.write(img2pdf.convert(immagini_da_comprimere))

    for i in immagini_da_comprimere:
        os.remove(i)
