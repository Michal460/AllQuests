import requests
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
import os
import json

# def give_all_urls():
#     driver = webdriver.Chrome()
#
#     url = "https://afisha.yandex.ru/moscow?rubric=cinema"
#     driver.get(url)
#
#     show_more_selector = ".button2.button-more"
#
#     num_clicks = 21
#
#     for _ in range(num_clicks):
#         show_more_button = WebDriverWait(driver, 5).until(
#             EC.visibility_of_element_located((By.CSS_SELECTOR, show_more_selector))
#         )
#         show_more_button.click()
#         time.sleep(2)
#
#     event_links = driver.find_elements(By.CSS_SELECTOR, ".events-list__item a")
#     event_links = [link.get_attribute("href") for link in event_links]
#
#     event_set = set(event_links)
#     event_mas=[]
#     for link in event_set:
#         if "#schedule" not in link:
#             event_mas.append(link)
#
#     driver.quit()
#     return event_mas
# all_hrefs = give_all_urls()
# def write_hrefs_in_block(mas):
#     with open('D:/PythonProject/hrefs.txt', 'w', encoding='utf-8') as file:
#         for link in mas:
#             file.write(link + '\n')
# write_hrefs_in_block(all_hrefs)
count = 0
def write_html_file_data(url, count):
    headers = {
        "User-Agent" : "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.140 Safari/537.36"
    }
    req = requests.get(url, headers=headers)

    time.sleep(5)

    soup = BeautifulSoup(req.text, "lxml")

    with open(f"/home/michael/PycharmProjects/pythonProject/data3/{count}theatre.html", "w", encoding="utf-8") as file:
        file.write(soup.prettify())

    if check_file_size("/home/michael/PycharmProjects/pythonProject/data3/", count) < 17*1024:
        write_html_file_data(url, count)
        print(f"{count} captcha")

def check_file_size(file_path, count):
    file_path = file_path + f'{count}theatre.html'
    file_size = os.path.getsize(file_path)
    return file_size

with open('/home/michael/PycharmProjects/pythonProject/hrefs1.txt', 'r', encoding='utf-8') as file:
    lines = file.readlines()
    lines = [line.strip() for line in lines]


for href in lines:
    write_html_file_data(href, count)
    count+=1
    print(f"{count} file is writed")

# def read_all_cinema():
#     for name in range(292):
#         with open(f"/home/michael/PycharmProjects/pythonProject/data1/{name}cinema.html", encoding="utf-8") as file:
#             src = file.read()
#         dict_all_char={}
#         soup = BeautifulSoup(src, "lxml")
#         title_name = soup.find("div", class_="event-concert-description__title-info")
#         title_afisha = soup.find("div", class_="event-concert-description__argument yandex-sans")
#         about_name = soup.find("div", class_="concert-description__text-wrap")
#         all_charact = soup.find_all("div", class_="event-attributes__row")
#         poster = soup.find("img", class_="image event-concert-heading__poster")
#         all_img = soup.find_all("img", class_="image event-concert-gallery__image")
#         all_img = [item.get("style").strip('background-image: url(').rstrip(')') for item in all_img]
#         backprekol = soup.find("div", class_="promo-media-background")
#         if title_name != None:
#             dict_all_char["Название"] = " ".join(title_name.text.split())
#         else:
#             dict_all_char["Название"] = "None inf"
#         if title_afisha != None:
#             dict_all_char["Описание"] = " ".join(title_afisha.text.split())
#         else:
#             dict_all_char["Описание"] = "None inf"
#         if about_name != None:
#             dict_all_char["О фильме"] = " ".join(about_name.text.split())
#         else:
#             dict_all_char["О фильме"] = "None inf"
#         if poster != None:
#             dict_all_char["Постер"] = poster["src"]
#         else:
#             dict_all_char["Постер"] = "None inf"
#         if all_img != None:
#             dict_all_char["Изображения"] = all_img
#         else:
#             dict_all_char["Изображения"] = "None inf"
#         if backprekol != None and isinstance(backprekol, str):
#             dict_all_char["Задний фон"] = backprekol.get("style").strip('background-image: url(').rstrip(');')
#         else:
#             dict_all_char["Задний фон"] = "None inf"
#         for item in all_charact:
#             name_item = " ".join(item.find("dt", class_="event-attributes__category").text.split())
#             charact_item = " ".join(item.find("dd", class_="event-attributes__category-value").text.split())
#             dict_all_char[name_item] = charact_item
#         print(dict_all_char)
#         with open(f"/home/michael/PycharmProjects/pythonProject/data1j/{name}cinema.json", "w", encoding="utf-8") as file:
#             json.dump(dict_all_char, file, indent=4, ensure_ascii=False)
# 
# read_all_cinema()

# def write_event():
#     for item in range(1):
#         with open(f"D:/PythonProject/data/{item}cinema.json", encoding="utf-8") as file:
#             event = json.load(file)
#
# write_event()



# def get_data(url):
#     headers = {
#         "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.5993.732 YaBrowser/23.11.1.732 Yowser/2.5 Safari/537.36"
#     }
#     req = requests.get(url,  headers=headers)
#     soup = BeautifulSoup(req.text,'lxml')
#
#     with open(f"D:/PythonProject/cinema.html", "w", encoding='utf-8') as file:
#         file.write(soup.prettify())

    # with open(f"D:/PythonProject/cinema.html", encoding='utf-8') as file:
    #     src = file.read()
    #
    # soup = BeautifulSoup(src, 'lxml')
    # all_categories = soup.find_all("div", class_="events-list__item")
    #
    # all_hrefs = []
    # all_names = []
    # for item in all_categories:
    #     item_href = "https://afisha.yandex.ru" + item.find("div", class_="Inner-sc-1x07jll-1 bIhOwB").find("a").get("href")
    #     item_name = item.find("h2", class_="Title-fq4hbj-3 hponhw")
    #     all_hrefs.append(item_href)
    #     all_names.append(item_name.text)
    # new_names = []
    # for item in all_names:
    #     item = ' '.join(item.split())
    #     new_names.append(item)
    # length = len(new_names)
    # all_dict = {}
    # for item in range(length):
    #     all_dict[new_names[item]] = all_hrefs[item]
    # for name, href in all_dict.items():
    #     # req = requests.get(href, headers).text
    #     # soup = BeautifulSoup(req, "lxml")
    #     # with open(f"D:/PythonProject/data/{name}.html", "w", encoding="utf-8") as file:
    #     #     file.write(soup.prettify())
    #
    #
    #     with open(f"D:/PythonProject/data/{name}.html", encoding="utf-8") as file:
    #         src = file.read()
    #
    #     soup = BeautifulSoup(src, "lxml")
    #     project_name = ' '.join(soup.find("div", class_="event-concert-description__title-info").text.split())
    #     project_afisha = ' '.join(soup.find("div", class_="event-concert-description__argument yandex-sans").text.split())
    #     project_poster = soup.find("img", class_="image event-concert-heading__poster").get("src")
    #     print(project_name)
    #     print(project_afisha)
    #     print(project_poster)
    #     break

# get_data("https://afisha.yandex.ru/moscow?rubric=cinema")

#/////////////////////////////////// CONCERT

