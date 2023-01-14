from guizero import App, Text, ButtonGroup, Combo, PushButton,TextBox, CheckBox, ListBox, system_config, Picture, Box

#print(system_config.supported_image_types)

app = App(title="Heroes Name Generator", width=400, height=600)

box = Box(app, align="bottom")
box.bg = "Green"
box.text_size = 20
box.text_color ="Blue"

def make_hero():
    adjective = bga.value
    animal = bca.value
    color = bbc.value
    another_adjective = blb.value
    hero = adjective + " " + another_adjective + " " + color + " " + animal
    output.value = "You are... The " + hero + "."

def theme_color():
    if bt.value == 1:
        app.bg = "Black"
        app.text_color = "White"
        box.bg = "Blue"
        box.text_color ="Green"
    else:
        app.bg = None
        app.text_color = None
        box.bg= "Green"
        box.text_color ="Blue"

picture = Picture(app, image="Data/deb_image.png", width=150, height=60)

theme = Text(app, text="Choose Color Theme")
bt = CheckBox(app, command=theme_color, text ="Dark Mode")


box1 = Box(app, align="top")

box2 = Box(box1, align = "left", height="fill", border=2)
box3 = Box(box1, align = "right", height="fill", border=2)

text5 = Text(box2, text = "Choose an adjective")
bga = ButtonGroup(box2, options= ["Amazing", "Funny", "Charming", "Femenine", "Delightful"], selected ="Amazing")

text6 = Text(box3, text="Choose another adjective")
blb = ListBox(box3, items=["Fast", "Lightening", "Ugly", "Brave", "Couragios"])

text7 = Text(app, text="Enter a colour?")
bbc = TextBox(app)

text8 = Text(app, text="Pick an animal")
bca = Combo(app, options=["Starfish", "Cammel", "Dolphin", "Bat", "Tiger", "Mantis"],selected="Tiger", width=20)


bf = PushButton(app, text="Make me a hero", command = make_hero)


box = Box(app)
box.bg = "Green"
box.text_size = 20
box.text_color ="Blue"
output = Text(box, text="A hero name will appear here")



app.display()