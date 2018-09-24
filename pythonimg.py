from PIL import Image
import os


def crop(Path, input, height, width, k, page, area):
    im = Image.open(input)
    imgwidth, imgheight = im.size
    for i in range(0, imgheight, height):
        for j in range(0, imgwidth, width):
            box = (j, i, j + width, i + height)
            a = im.crop(box)
            try:
                o = a.crop(area)
                o.save(os.path.join(Path, "PNG", "%s" % page, "IMG-%s.png" % k))
            except:
                pass
            k += 1


listfiles = os.listdir("/Volumes/RAM Disk/ilovepdf_extract_pdf_images")

listfiles.remove('pythonimg.py')

# $PWD per il percorso da shell

count = 0

for file in listfiles:
    im = Image.open(str(file))
    print(im.size)

    bbox = (0, 0, 1655, 2410)
    working_slice = im.crop(bbox)
    working_slice.save(os.path.join("/Volumes/RAM Disk/ilovepdf_extract_pdf_images", "slice_" + str(count) + ".jpg"))

    count += 1

    bbox = (1755, 0, 3437, 2410)
    working_slice = im.crop(bbox)
    working_slice.save(os.path.join("/Volumes/RAM Disk/ilovepdf_extract_pdf_images", "slice_" + str(count) + ".jpg"))

    count += 1
    #crop("/Volumes/RAM Disk/ilovepdf_extract_pdf_images", file, im.size[0], im.size[1], 100, 2, 1000)
