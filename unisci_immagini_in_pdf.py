from fpdf import FPDF
import os
from PIL import Image


listfiles = os.listdir("/Volumes/RAM Disk/teoria riassunta")

listfiles.remove('unisci_immagini_in_pdf.py')

# $PWD per il percorso da shell

count = 0
altezza_pagina = 2550
larghezza_pagina = 3512
pdf = FPDF(unit="pt", format=[altezza_pagina, larghezza_pagina])

for fil in listfiles:
    # imagelist is the list with all image filenames
    pdf.add_page()
    img = Image.open(fil)
    margine_sinistro = 0
    margine_destro = 0
    # stampo dimensione immagine
    height, width = img.size
    print(img.size)
    pdf.image(fil, margine_sinistro, margine_destro)

pdf.output("/Volumes/RAM Disk/teoria riassunta/yourfile.pdf", "F")
