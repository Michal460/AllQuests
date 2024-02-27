from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

def give_all_urls(): #url,selector,count_step,css_selector for future
    driver = webdriver.Chrome()

    url = "https://afisha.yandex.ru/moscow?rubric=concert"
    driver.get(url)

    show_more_selector = ".button2.button-more"

    num_clicks = 30

    for _ in range(num_clicks):
        show_more_button = WebDriverWait(driver, 10).until(
            EC.visibility_of_element_located((By.CSS_SELECTOR, show_more_selector))
        )
        show_more_button.click()
        time.sleep(2)

    event_links = driver.find_elements(By.CSS_SELECTOR, ".events-list__item a")
    event_links = [link.get_attribute("href") for link in event_links]

    event_set = set(event_links)
    event_mas=[]
    for link in event_set:
        if "#schedule" not in link:
            event_mas.append(link)
            print(link)

    driver.quit()
give_all_urls()