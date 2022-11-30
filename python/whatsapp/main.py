from selenium import webdriver
from selenium.webdriver.common import options
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

# options = webdriver.ChromeOptions()
# options.add_argument("/home/rohits/.config/google-chrome/Default")

# driver = webdriver.Chrome(options=options)
driver = webdriver.Chrome()
print(driver)


driver.get("https://web.whatsapp.com/")

def send_message(text_box, message, username= ""):
    text_box.send_keys(username + Keys.ENTER)
    text_box.send_keys(message)
    text_box.send_keys(Keys.ENTER)
    
def msg():
    # name = input("\nEnter Group/User Name: ")
    # message = input("Enter your message to group/user: ")


    name = "Garbage "
    message = "Thanks for cooperating"
    username = "@Abhishek Yadav IT MAIT"

    count = int(input("Enter the message count: "))

    user = driver.find_element(By.XPATH, '//span[@title = "{}"]'.format(name))
    user.click()

    text_box = driver.find_element(By.CLASS_NAME, 'p3_M1')

    for _ in range(count):
        send_message(text_box, message, username)
        time.sleep(0.5)
    
if __name__ == "__main__":
    
    while True:
        msg()
        ask = input("Do you want to re-run the program? : ")
        
        if ask == 'no':
            break;




