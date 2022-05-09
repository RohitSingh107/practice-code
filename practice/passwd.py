from guizero import App, Text, TextBox, PushButton, info

app = App(title="This is password check app")

labl = Text(app, text="Enter password twice")
pass1 = TextBox(app)
pass2 = TextBox(app)

def check():
    if pass1.value == pass2.value:
        info("Summary", "Good Password")
    else:
        info("Summary", "Passwords don't match, try again")

btn = PushButton(app, command=check, text="Done")

app.display()