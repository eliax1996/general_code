from fpdf import FPDF
import os
from PIL import Image

# os.path.dirname(os.path.abspath(__file__)) current script path
# os.getcwd() current directory path

listfiles = os.listdir(os.getcwd())

listfiles.remove('unisci_immagini_in_pdf_ebook_late.py')
try:
    listfiles.remove('.DS_Store')
    listfiles.remove('bac')
except:
    print()

print("converting files:")
print(listfiles)

# $PWD per il percorso da shell

count = 0
altezza_pagina = 1690
larghezza_pagina = 2410
pdf = FPDF(unit="pt", format=[altezza_pagina, larghezza_pagina])

margine_sinistro = 0
margine_destro = 0
i = 0

for fil in listfiles:
    # imagelist is the list with all image filenames
    pdf.add_page()
    img = Image.open(fil)

    i = i + 1

    width, height = img.size   # Get dimensions

    # for standard ebook latex crop
    if i < 9:
        left = 390
        top = 600
        right = 390
        bottom = 500
    elif i % 2 == 0:
        # pari
        left = 320
        top = 600
        right = 470
        bottom = 500
    else:
        left = 470
        top = 600
        right = 320
        bottom = 500

    img = img.crop((left, top, width - right, height - bottom))
    img.save(fil)

    pdf.image(fil, margine_sinistro, margine_destro)

print("created file " + os.getcwd() + "/yourfile.pdf")

pdf.output(os.getcwd() + "/yourfile.pdf", "F")
