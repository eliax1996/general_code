from bs4 import BeautifulSoup
import sqlite3
import requests

def define_request(url):
	page = requests.get(url,auth=('d3ll4', '6nWvKtiw'),verify=False)

	return page

def is_valid_link(url):
	return (not str(url).startswith("?sort") and not str(url) == "..")

def download_pdf(url):
	r = requests.get(url, allow_redirects=True,auth=('d3ll4', '6nWvKtiw'),verify=False)
	open('my_pdf.pdf', 'wb').write(r.content)


def update_book_list():
	base_url = "https://node.nova-labs.ch/warez/Giornali%20-%20Riviste/"

	page = define_request(base_url)
	soup = BeautifulSoup(page.content,from_encoding="utf-8",features="lxml")

	all_url = []

	for link in soup.find_all('a'):
		if (is_valid_link(link["href"])):
			second_part_url = str(link["href"])

			url = base_url + second_part_url
			page = define_request(url)

			soup = BeautifulSoup(page.content,from_encoding="utf-8",features="lxml")
			for link in soup.find_all('a'):
				if (is_valid_link(link["href"])):
					all_url.append([url + str(link["href"])])


	return all_url


def save_books(books):
	books = [books]
	conn = sqlite3.connect('telegram_turbocattolicesimoedicola.db')
	cur = conn.cursor()

	cur.execute("DELETE FROM book_url")
	cur.executemany('INSERT INTO book_url VALUES (null,?)',books)
	conn.commit()
	conn.close()
	print("done")

def update_list():
	book = update_book_list()
	save_books(books)

