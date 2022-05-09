class Character():

    # Create a character
    def __init__(self, char_name, char_description):
        self.name = char_name
        self.description = char_description
        self.conversation = None

    # Describe this character
    def describe(self):
        print( self.name + " is here!" )
        print( self.description )

    # Set what this character will say when talked to
    def set_conversation(self, conversation):
        self.conversation = conversation

    # Talk to this character
    def talk(self):
        if self.conversation is not None:
            print("[" + self.name + " says]: " + self.conversation)
        else:
            print(self.name + " doesn't want to talk to you")

    # Fight with this character
    def fight(self, combat_item):
        print(self.name + " doesn't want to fight with you")
        return True

class Enemy(Character):

    enemies_to_defeat = 0

    def __init__(self, char_name, char_description):
        super().__init__(char_name, char_description)
        self._weakness = None
        Enemy.enemies_to_defeat = Enemy.enemies_to_defeat + 1

    @property
    def weaknesses(self):
        return self._weakness

    @weaknesses.setter
    def weaknesses(self, value):
        self._weakness = value

    #def set_weakness(self, weakness):
        #self.weakness = weakness

    #def get_weakness(self):
        #return self.weakness

    def fight(self, combat_item):
        if combat_item == self._weakness:
            print("You fend " + self.name + " off with the " + combat_item)
            Enemy.enemies_to_defeat = Enemy.enemies_to_defeat - 1
            return True
        else:
            print(self.name + " crushes you, punny adventurer")
            print("GAME OVER")
            return False
class Friend(Character):

    def __init__(self, char_name, char_description):

        super().__init__(char_name, char_description)
        self.feeling = None

    def hug(self):
        print(self.name + " hugs you back!")