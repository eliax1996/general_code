import os

for filename in os.listdir("."):
    if filename.endswith(".mp3"):
        os.rename(filename, filename[:filename.rfind("-")].strip().capitalize() + ".mp3")
