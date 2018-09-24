intimport re

cookie_iniziale = open("cookie.txt", mode="r")
cookie_finale = open("cookie.json", mode="w")

for line in cookie_iniziale:
    informations = line.split("\t")
    if informations[0] == ".netflix.com" or informations[0] == ".www.netflix.com":
        for information in informations:
            print("informazione: " + information)

cookie_esempio = open("codebeautify.xml", mode="r")

for line in cookie_esempio:
    re.
    print(re.split(r'<*>', string, maxsplit=0, flags=0))
