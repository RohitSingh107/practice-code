from room import Room
from character import Enemy, Friend
from rpginfo import RPGInfo
from item import Item
spooky_castle = RPGInfo("The spooky Castle")
spooky_castle.welcome()
RPGInfo.info()

ballroom = Room("ballroom")
kitchen = Room("kitchen")
dining_hall = Room("dining_hall")

print("There are " + str(Room.number_of_rooms) + " rooms to explore.")

ballroom.set_description("A vast room with a shiny wooden floor; huge candlesticks guard the entrance")
dining_hall.set_description("A large room with ornate golden decoration on each wall")
kitchen.set_description("Current Room: A dark and dirty room buzzing with files")

kitchen.describe()

kitchen.link_room(dining_hall, "south")
dining_hall.link_room(kitchen, "north")
dining_hall.link_room(ballroom, "west")
ballroom.link_room(dining_hall, "east")



dave = Enemy("Dave", "A smelly zombie")
dave.set_conversation("You look tasty")
dave.weaknesses = "Cheese"
#dave.set_weakness("cheese")
dining_hall.set_character(dave)

cheese = Item("Cheese")
cheese.set_description("Here is Cheese!!")
ballroom.set_item(cheese)

maps =Item("Map")
maps.set_description("Here is a Map!!")
kitchen.set_item(maps)


current_room = kitchen
dead = False
backpack = []
#items = current_room.get_item()
while dead == False:
        print('\n')
        current_room.get_details()
        inhabitant = current_room.get_character()
        if inhabitant is not None:
            inhabitant.describe()
        items = current_room.get_item()
        if items is not None:
            items.describe()
        command = input("> ")
        if command in ["north", "south", "east", "west"]:
            current_room = current_room.move(command)
            current_room.describe()

        elif command == "talk":
            if current_room.character is not None:
                inhabitant.talk()
            else:
                print("You are alone")

        elif command == "fight":
            if current_room.character is not None:
                combat_with = input("choose your weapon/item > ")
                if combat_with in backpack:

                    if inhabitant.fight(combat_with) == True:
                        print("Hooray, you win")
                        current_room.set_character(None)
                        if Enemy.enemies_to_defeat == 0:
                            print("Congratulation you finished the game")
                            dead = True

                    else:
                        print("You lost the fight")
                        print("Game Over")
                        dead = True
                else:
                    print("You lost the fight")
                    print("Game Over")
                    dead = True

        elif command == "hug":
            if inhabitant is not None:
                if isinstance(inhabitant, Enemy):
                    print("I would'nt do that if I were you...")
                else:
                    inhabitant.hug()
            else:
                print("There is no one to hug :")

        elif command == "take":
            if items is not None:
                backpack.append(items.get_name())
                current_room.set_item(None)
            else:
                print("Nothing to take")

        elif command == "backpack":
            print(backpack)
        else:
            print("Please enter valid command")


RPGInfo.author = "Rohit Singh"
RPGInfo.credits()

