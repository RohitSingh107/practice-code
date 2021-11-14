class Human:
    # Class Attribute
    species = "Homo Sapiens"
    count = 0
    population_in_billions = 7

    # Instance Attribute
    def __init__(self, name, age):
        self.name = name
        self.age = age
        Human.count += 1

    # Instance Method
    def __str__(self):
        return f"{self.name} whose best or only quality is {self.species} have age {self.age} years old"

    def speak(self, sound):
        return f"{self.name} says {sound}"

    # Class Method
    @classmethod
    def change_population(cls, new_value):
        cls.population_in_billions = new_value

    @classmethod
    def human_alternate_constructor(cls, person):
        name, age = person.split("-")
        return cls(name, age)

    # Independent- Neither Class nor Instance
    @staticmethod
    def animal_kingdom_check(value):
        return bool(value == "Apes")

    @staticmethod
    def info():
        return """
        Humans (Homo sapiens) are the most abundant and widespread species of primate, 
        characterized by bipedality, large and complex brains enabling the development of advanced tools, 
        culture and language. 
        Humans are highly social beings and 
        tend to live in complex social structures composed of many cooperating and competing groups, 
        from families and kinship networks to political states. 
        Social interactions between humans have established a 
        wide variety of values, social norms, and rituals, which bolster human society. 
        Curiosity and the human desire to understand and influence the environment 
        and to explain and manipulate phenomena have motivated 
        humanity's development of science, philosophy, mythology, religion, and other fields of knowledge.
        
        Source: https://en.wikipedia.org/wiki/Human
        """

class Female(Human):
    gender = "Female"

    def speak(self, sound= "Hi"):
        return "High Pitch Sound: " +  super().speak(sound)

class Male(Human):
    gender = "Male"

    def speak(self, sound= "Hello"):
        return "Low Pitch Sound: " + super().speak(sound)

class Worker(Human):
    def __init__(self, name, age, exp, salary):
        super().__init__(name, age)
        self.exp = exp
        self.salary = salary

print(Human.count)

rose = Human(age="25", name="Rose")

minakxi = Female(name= "Minakxi", age = 20)

rohit = Male(age="21", name="Rohit")

happy = Male.human_alternate_constructor("Happy-28")

puja = Worker("Puja", 25, 2, 50000)

print(Human.count)

# help(Worker)
#print(puja.salary)
# print(puja)
# print(Human.info())
# print(Female.animal_kingdom_check("Apes"))
# print(happy.name)
# print(happy)
# print(happy.gender)
# print(rose)
# print(rohit)
# print(rohit.name)
# print(rohit.age)
# print(rohit.species)
# print(rose.speak("Hello"))
# print(rohit.speak())
# print(rohit.gender)
# print(minakxi)
# print(minakxi.species)
# print(minakxi.speak())
# print(rohit.__dict__)
# rohit.new_var = 4
# print(rohit.__dict__)
# print(Human.population_in_billions)
# Human.change_population(8)
# print(Human.population_in_billions)
