# -*- coding: utf-8 -*-
import requests
import json
from bs4 import BeautifulSoup
count = 1
url = "https://afisha.yandex.ru/moscow?rubric=cinema&page="
agent = {
    "Accept" : "*/*",
    "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.5993.732 YaBrowser/23.11.1.732 Yowser/2.5 Safari/537.36"
}
req = requests.get(url + '1', headers=agent)
src = req.text

soup = BeautifulSoup(src, 'lxml')

with open("D:/PythonProject/Cinema.html", "w", encoding="utf-8") as file:
     file.write(soup.prettify())

with open("D:/PythonProject/Cinema.html", encoding="utf-8") as file:
    src = file.read()

soup = BeautifulSoup(src, "lxml")

all_hrefs = soup.find_all(class_="Inner-sc-1x07jll-1 bIhOwB")
dict_hrefs = {}

for item in all_hrefs:
    item_name = item.find("div", class_="Root-fq4hbj-4 iFrhLC").text
    item_href = "https://afisha.yandex.ru" + item.find("a").get("href") + "-date=2023-12-14"
    item_name = ' '.join(item_name.split()[:-3])
    dict_hrefs[item_name] = item_href

for category_name, category_href in dict_hrefs.items():
    req = requests.get(url=category_href, headers=agent)
    src = req.text

    soup = BeautifulSoup(src, "lxml")
    with open(f"D:/PythonProject/data/{category_name}.html", "w", encoding="utf-8") as file:
        file.write(soup.prettify())
count+=1
url = url + str(count)
print(count)

    # with open(f"D:/PythonProject/data/{category_name}.html", encoding="utf-8") as file:
    #     src = file.read()
#     soup = BeautifulSoup(src,"lxml")
#
#     all_c = []
#
#     all_categories = soup.find_all("div", class_="event-attributes__row")
#     dict_categories = {}
#
#     item_name = soup.find("h2", class_="concert-description__title").text
#     item_name = ' '.join(item_name.split())
#
#     item_haras = soup.find("div", class_="concert-description__text-wrap").text
#     item_haras = ' '.join(item_haras.split())
#
#     dict_categories[item_name] = item_haras
#
#     for item in all_categories:
#         item_name = ' '.join(item.find("dt").text.split())
#         item_haras = ' '.join(item.find("dd").text.split())
#         dict_categories[item_name] = item_haras
#
#     all_c.append(dict_categories)
#     dict_categories.clear()
#     count+=1
#     if count == 2: break
# with open(f"D:/PythonProject/data/all_categories.json", "w", encoding="utf-8") as file:
#     json.dump(all_c, file, indent=4, ensure_ascii=False)
#
