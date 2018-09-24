import googlemaps
import json
from datetime import datetime
from geopy.distance import vincenty

luoghi = ("Via Biancamano 10", "Corso Galileo Ferraris 290", "Via Balla 13", "Via Modigliani 25", "Corso Sebastopoli 260", "Corso Galileo Ferraris 294", "Via V.Alecsandri 29", "Via Vigone 70", "Strada Antica di Collegno 211", "Corso Appio Claudio 110", "Corso Lombardia 95", "Via Massari 114", "Via Sospello 118", "Via Tollegno 83", "Via Gottardo 10", "Via Ragazzoni 5/7", "Via Cecchi 14", "Via Villa Glori 21", "Via Tiziano 39", "Via Pasquale Paoli 17 - Via Tunisi 102", "Via Olivero 32/A", "Strada Castello di Mirafiori 55", "Via Torrazza Piemonte 14")

gmaps = googlemaps.Client(key='AIzaSyCyTPLJDOf_mULnRqFLuPyCPvpeMW8dfCI')

x = -1

for luogo in luoghi:
    try:
        # Geocoding an address
        geocode_result = gmaps.geocode(str(luogo))

        continua = True
        pos = 0
        
        while continua:
            primo_luogo = geocode_result[pos]["geometry"]["location"]

            lat = primo_luogo["lat"]
            lon = primo_luogo["lng"]

            km = vincenty((lat, lon), (45.0403884, 7.6511319)).kilometers

            if km < 100:
                continua = False
            else:
                pos += 1

        x += 1

        print(str(x) + "   " + luogo + str(lat) + "," + str(lon))
    except:
        print(luogo + "  --> ha fallito!")
        pass
