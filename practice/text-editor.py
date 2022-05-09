from guizero import (
    App,
    Box,
    TextBox,
    PushButton,
    Text,
    Combo,
    Slider,
    MenuBar,
    info,
    Window,
)


#def open_file():
#    with open(file_select.value, "r") as f:
#        editor.value = f.read()


def save_file():
    if file_select.text == "Open":
        file_select.text = app.question("File not saved", "Enter name of file")
    else:
        with open(file_select.text, "w") as f:
            f.write(editor.value)
        save_button.disable()


def background():
    if bg_color.value == "Default":
        app.bg = None
        editor.bg = None
    else:
        editor.bg = bg_color.value


def textcolor():
    if color_button.value == "Default":
        app.text_color = None
        editor.text_color = None
    else:
        editor.text_color = color_button.value


def textsize():
    editor.text_size = size_slider.value
    editor.resize(1, 1)
    editor.resize("fill", "fill")


def change_fonts():
    editor.font = font_button.value


def save_button_enable():
    save_button.enable()
    # confirm_save.enable()


def exit_app():
    if save_button.enabled == True:
        exit_window.show(wait=True)
    else:
        app.destroy()
        exit()


def exit_confirm():
    app.destroy()
    exit()


def clear_text():
    global cleared_text
    cleared_text = editor.value
    editor.value = ""


def save_and_exit():
    save_file()
    exit_confirm()


def restore_text():
    editor.value = cleared_text


def dark_theme():
    app.bg = "Black"
    app.text_color = "White"
    bg_color.value = "Black"
    color_button.value = "White"


def red_and_yelloe_theme():
    app.bg = "Yellow"
    app.text_color = "Red"
    bg_color.value = "Yellow"
    color_button.value = "Red"


def default_theme():
    app.bg = None
    app.text_color = None
    bg_color.value = "White"
    color_button.value = "Black"
def file_sel_fun():
    fs = " "
    fs = app.select_file()
    with open(fs, "r") as f:
        editor.value = f.read()
    file_select.text = fs


app = App(title="My Text Editor")

exit_window = Window(app, title="confirm", height=100, width=300)
exit_window.hide()


confirm_save = PushButton(exit_window, text="Save and Exit", command=save_and_exit)
confirm_exit = PushButton(exit_window, text="Exit Without Saving", command=exit_confirm)


menubar = MenuBar(
    app,
    toplevel=["File", "Edit", "Theme"],
    options=[
        [["Open", file_sel_fun], ["Save", save_file], ["Exit", exit_app]],
        [["Clear Editor", clear_text], ["Restore Text", restore_text]],
        [
            ["Dark Theme", dark_theme],
            ["Red and Yellow Theme", red_and_yelloe_theme],
            ["Default Theme", default_theme],
        ],
    ],
)


top_panel = Box(app, width="fill", border=2)

save_button = PushButton(
    top_panel, text="Save", align="left", command=save_file, enabled=False
)
#open_button = PushButton(top_panel, text="Open", align="left", command=open_file)
file_select = PushButton(
    top_panel, text="Open", align="right", height="fill", command=file_sel_fun
)
editor = TextBox(
    app, multiline=True, height="fill", width="fill", command=save_button_enable
)
bottom_panel = Box(app, width="fill", border=2, align="bottom")
font_button = Combo(
    bottom_panel,
    options=["Bitstream Vera Sans Mono", "courier", "times new roman", "verdana"],
    align="left",
    command=change_fonts,
)
bg_color = Combo(
    bottom_panel,
    options=[
        "Default",
        "White",
        "Black",
        "Red",
        "Yellow",
        "Blue",
        "Orange",
        "Green",
        "Purple",
        "Grey",
    ],
    align="right",
    command=background,
)
color_button = Combo(
    bottom_panel,
    options=["Default", "Black", "White", "Red", "Yellow", "Blue", "Orange", "Green", "Purple"],
    align="right",
    command=textcolor,
)
size_slider = Slider(
    bottom_panel, start=10, end=30, horizontal=True, width="fill", command=textsize
)


app.when_closed = exit_app
app.display
