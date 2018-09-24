import urllib2
from bs4 import BeautifulSoup
import wget
import img2pdf
import os


web_page = "https://www.mangaeden.com/en/it-manga/shingeki-no-kyojin/"
pages = []

for x in range(11, 104):
    stringa = str(x) + "/"
    pages.append(web_page + stringa )


# per mandare affanculo il controllo che tu non sia un robot
hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
       'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
       'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
       'Accept-Encoding': 'none',
       'Accept-Language': 'en-US,en;q=0.8',
       'Connection': 'keep-alive'}

x = 0

print(pages)




for page in pages:
    print("scarico: " + page)

    pagina_vecchia = ""

    page2 = page + str(x)

    req = urllib2.Request(page2, headers=hdr)


    pagina_nuova = urllib2.urlopen(req)

    while pagina_vecchia != pagina_nuova:
        pagina_vecchia = pagina_nuova
        

    while req != pagina_vecchia:


        soup = BeautifulSoup(page)

        immagini = soup.find_all("img")

        immagini_da_comprimere = []

        for immagine in immagini:
            img = immagine['src']
            if ('.gif' not in img):
                filename = wget.download(img)
                immagini_da_comprimere.append(filename)

    with open("capitolo" + "%03d" % x + ".pdf", "wb") as f:
        f.write(img2pdf.convert(immagini_da_comprimere))

    for i in immagini_da_comprimere:
        os.remove(i)