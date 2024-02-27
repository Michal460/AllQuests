import time

import requests
from bs4 import BeautifulSoup

url = 'https://afisha.yandex.ru/moscow?rubric=cinema&page=5'

headers = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 YaBrowser/24.1.0.0 Safari/537.36'}

req = requests.get(url, headers=headers)

time.sleep(30)

soup = BeautifulSoup(req.text, 'lxml')

data = soup.find_all('div', class_='Inner-sc-1x07jll-1 bIhOwB')

all_hrefs = []

for href in data:
    print(href.find('a').get('href'))