import re
from lxml import html
from bs4 import BeautifulSoup

with open("D:/PythonProject/index.html") as file:
    src = file.read()

soup = BeautifulSoup(src, "lxml")

# title = soup.title
# print(title.text)

# .find() .find_all()
# page_h1 = soup.find("h1")
# print(page_h1)
# page_all_h1 = soup.find_all("h1")
# print(page_all_h1)

# user_name = soup.find("div", class_="user__name")
# print(user_name.text)

# user_name = soup.find(class_="user__name").find("span").text
# print(user_name)

# find_all_spans_in_user_info = soup.find(class_="user__info").find_all("span")
# print(find_all_spans_in_user_info)

# social_links = soup.find(class_="social__networks").find("ul").find_all("a")
# print(social_links)

# all_a = soup.find_all("a")
# print(all_a)

# .find_parent(), .find_parents()

# post_div = soup.find(class_="post__text"). find_parent("div", "user__post")
# print(post_div)

# post_divs = soup.find(class_="post__text").find_parents()
# print(post_divs)

# .next_element .previous_element

# next_el = soup.find(class_="post__title").next_element.next_element.text
# print(next_el)

# next_el = soup.find(class_="post__title").find_next().text
# print(next_el)