from guizero import App, Box, PushButton, Picture, Text, Window, ButtonGroup, info
import os
from random import shuffle, randint
# set the path to the emoji folder on your computer
emojis_dir = "emojis"
# create a list of the locations of the emoji images
emojis = [os.path.join(emojis_dir, f) for f in os.listdir(emojis_dir) if os.path.isfile(os.path.join(emojis_dir, f))]

# shuffle the emojis
shuffle(emojis)

consecutive_score = 0

def emoji_match(matched):
    global consecutive_score
    if matched:
        result.value = "Correct"

        score_no.value = int(score_no.value) + 1
        consecutive_score = consecutive_score + 1
    else:
        result.value = "Incorrect"
        if int(score_no.value) > 0:

            score_no.value = int(score_no.value) - 1
        consecutive_score = 0

    setup_round()

def counter():
    timer.value = int(timer.value) - 1
    if int(timer.value) == 0:
        timer.cancel(counter)
        result.value = "Game Over"

        confirm_window = app.yesno("Confirm", "Your score is: " + score_no.value + " Do you want to continue")
        if confirm_window == False:
            info("score", "You scored: " + score_no.value)
            app.destroy()
        else:
            timer.value = 30
            result.value = " "
            setup_round()
            #stop previous runnig timer
            #timer.cancel(counter)
            timer.repeat(1000, counter)
            round_no.value = int(round_no.value) + 1
            score_no.value = "0"


def setup_round():


    for picture in pictures:
        picture.image = emojis.pop()

    for button in buttons:
        button.image = emojis.pop()
        button.update_command(emoji_match, [False])

    matched_emoji = emojis.pop()


    random_picture = randint(0,8)
    pictures[random_picture].image = matched_emoji

    random_button = randint(0,8)
    buttons[random_button].image = matched_emoji
    buttons[random_button].update_command(emoji_match, [True])



app = App(title="Emoji Matching Game", height = 700, width=700, bg="White")



extra_features = Box(app, layout="grid")
time_label = Text(extra_features, text="Time remaining", grid=[0,0])
timer = Text(extra_features, text = "Get Ready", grid=[1,0])


round_txt = Text(extra_features, align="left", text="Round NO", grid=[0,1])
round_no = Text(extra_features, text = "0", grid=[1,1])

scoreboard = Box(app)
score_text = Text(scoreboard, text="Score", align= "left")
score_no = Text(scoreboard, text = "0", align = "left")



result = Text(app)

game_box = Box(app)

pictures_box = Box(game_box, layout="grid", align="left")

button_box = Box(game_box, layout="grid", border=3, align="right")

pictures = []
buttons = []

for x in range(0,3):
    for y in range(0,3):
        picture = Picture(pictures_box, grid=[x,y])
        pictures.append(picture)
        button = PushButton(button_box, grid=[x,y])
        buttons.append(button)









setup_round()
timer.value = 30
timer.repeat(1000, counter)

round_no.value = int(round_no.value) + 1



app.display