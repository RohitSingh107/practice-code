from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait

import time

# from selenium.webdriver.chrome.service import Service
# service = Service(executable_path="")
# driver = webdriver.ChromeService()


with webdriver.Firefox() as driver:
    driver.get("https://google.com")


    WebDriverWait(driver, 5).until(
        EC.presence_of_all_elements_located((By.CLASS_NAME, "gLFyf"))
    ) # Ensures the element is present

    # input_element = driver.get_element(By.CLASS_NAME, "gLFyf")
    # input_element = driver.find_elements(By.CLASS_NAME, "gLFyf")
    input_element = driver.find_element(By.CLASS_NAME, "gLFyf")
    input_element.send_keys("internet bots" + Keys.ENTER)



    WebDriverWait(driver, 10).until(
        EC.presence_of_all_elements_located((By.PARTIAL_LINK_TEXT, "internet bot"))
    ) # Ensures the element is present

    link = driver.find_elements(By.PARTIAL_LINK_TEXT, "internet bot")
    link[0].click()

 

    time.sleep(20)


# driver.quit()
