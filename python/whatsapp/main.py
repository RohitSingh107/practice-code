from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

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




# <span dir="auto" title="Garbage " class="ggj6brxn gfz4du6o r7fjleex g0rxnol2 lhj4utae le5p0ye3 l7jjieqr i0jNr">Garbage </span>

# <div tabindex="-1" class="p3_M1"><div class="g0rxnol2"><div class="fd365im1 to2l77zo bbv8nyr4 mwp4sxku gfz4du6o ag5g9lrv" contenteditable="true" role="textbox" spellcheck="true" title="Type a message" data-testid="conversation-compose-box-input" data-tab="10" data-lexical-editor="true" style="user-select: text; white-space: pre-wrap; word-break: break-word;"><p class="selectable-text copyable-text"><br></p></div><div class="lhggkp7q qq0sjtgm jxacihee qzp46edm b9fczbqn bze30y65 jgi8eev7 t35qvd06 m62443ks rkxvyd19 c5h0bzs2">Type a message</div></div></div>

# tvf2evcx oq44ahr5 lb5m6g5c svlsagor p2rjqpw5 epia9gcq
