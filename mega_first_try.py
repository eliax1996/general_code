from mega import Mega

email = 'oewk@crusthost.com'
password = 'ciaociaociao'

m = Mega.from_credentials(email, password)

m.uploadfile("utilizzo_thread.py")

# list of files
files = m.get_files()

print(files)
