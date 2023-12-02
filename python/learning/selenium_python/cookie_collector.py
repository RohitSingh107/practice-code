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
    driver.get("https://orteil.dashnet.org/cookieclicker/")

    WebDriverWait(driver, 15).until(
        EC.presence_of_all_elements_located((By.XPATH, "//*[contains(text(), 'English')]"))
    ) # Ensures the element is present
    language = driver.find_element(By.XPATH, "//*[contains(text(), 'English')]")
    language.click()

    WebDriverWait(driver, 15).until(
        EC.presence_of_all_elements_located((By.ID, "bigCookie"))
    ) # Ensures the element is present

    cookie = driver.find_element(By.ID, "bigCookie")
    time.sleep(5)
    cookie.click()

    product_price_prefix = "productPrice"
    product_prefix = "product"



    while True:
        cookie.click()
        cookies_count = int(driver.find_element(By.ID, "cookies").text.split(" ")[0].replace(",", ""))
        print("cookies count: ", int(cookies_count))

        for i in range(4):
            product_price = driver.find_element(By.ID, product_price_prefix + str(i)).text.replace(",","")

            if not product_price.isdigit():
                continue
            product_price = int(product_price)

            if cookies_count >= product_price:
                product = driver.find_element(By.ID, product_prefix + str(i))
                product.click()
                break

    # # input_element = driver.get_element(By.CLASS_NAME, "gLFyf")
    # # input_element = driver.find_elements(By.CLASS_NAME, "gLFyf")
    # input_element = driver.find_element(By.CLASS_NAME, "gLFyf")
    # input_element.send_keys("internet bots" + Keys.ENTER)



 

    time.sleep(20)


# driver.quit()
