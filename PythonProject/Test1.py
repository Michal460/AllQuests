import requests
from bs4 import BeautifulSoup
import csv
import json

# url = "https://health-diet.ru/table_calorie/?utm_source=leftMenu&utm_medium=table_calorie"
#
agent = {
    "Accept" : "*/*",
    "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.5993.732 YaBrowser/23.11.1.732 Yowser/2.5 Safari/537.36"
}
#
# req = requests.get(url, 'lxml')
# src = req.text
#
# with open("D:/PythonProject/index1.html", "w") as file:
#     file.write(src)
# with open("D:/PythonProject/index1.html") as file:
#     src = file.read()
#
# soup = BeautifulSoup(src, 'lxml')
# all_products_hrefs = soup.find_all(class_="mzr-tc-group-item-href")
#
# all_categories_dict = {}
#
# for item in all_products_hrefs:
#     item_href = "https://health-diet.ru" + item.get("href")
#     item_text = item.text
#     all_categories_dict[item_text] = item_href
#
# with open("D:/PythonProject/all_categories.json", "w") as file:
#     json.dump(all_categories_dict, file, indent=4, ensure_ascii=False)

with open("D:/PythonProject/all_categories.json") as file:
    all_categories = json.load(file)

count = 0

for category_name, category_href in all_categories.items():
    if count == 0:
        rep = [",", " ", "-", "'"]
        for item in rep:
            if item in category_name:
                category_name = category_name.replace(item, "_")

        req = requests.get(url=category_href, headers=agent)
        src = req.text

        with open(f"D:/PythonProject/data/{count}_{category_name}.html", "w") as file:
            file.write(src)

        count+=1;