from guizero import App, Text, TextBox, PushButton, info

app = App(title="This is my first GUI")

firstmessage = Text(app, text="This is Big text.")
secondmessage = Text(app, text="This is Green.")

firstmessage.text_size = 40
firstmessage.text_color = "red"
secondmessage.bg = "green"
secondmessage.font = "Times New Roman"

def btn_go_clicked():
    info("Greetings", "Hello, " + txt_name.value + " - I hope you're having a nice day")

def highlight():
    txt_name.bg = "light blue"
def lowlight():
    txt_name.bg = None

lbl_name = Text(app, text="Hello, What's your Name?")
txt_name = TextBox(app)
btn_go = PushButton(app, command=btn_go_clicked, text="Done")

txt_name.when_mouse_enters = highlight
txt_name.when_mouse_leaves = lowlight

def sb_go_cl():
    info("Hello", "Your name is " + name.value + " and you live in " + place.value )
def tb_go_cl():
    info("Help", "Fill your name in first box and place in second box")
lbl = Text(app, text="Fill your Details")
name = TextBox(app,)
place = TextBox(app)
sb_go = PushButton(app, command=sb_go_cl, text="Filled")
tb_go = PushButton(app, command=tb_go_cl, text="Help")



app.display()