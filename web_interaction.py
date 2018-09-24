from selenium import webdriver
from getpass import getpass

print('selenium ce')

#usr = input("insert your user")
#pass = getpass("enter your password")

driver = webdriver.Chrome('/Users/eliamigliore/Desktop/web scraping/chromedriver') #(driverLocation) 
driver.get('https://twitter.com/login?lang=it')
login_form = driver.find_element_by_xpath('//*[@id="page-container"]/div/div[1]/form/fieldset/div[2]/input')
login_form.click()
login_form.send_keys("dio porco")
html = driver.page_source
print(html.encode('ascii', 'ignore').decode('ascii'))