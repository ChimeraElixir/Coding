from bs4 import BeautifulSoup
import requests

html_text=requests.get('')
soup = BeautifulSoup(html_text, 'lxml')

