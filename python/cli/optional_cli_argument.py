import typer
import random
from typing import Optional

def get_greeting():
    return random.choice(["Hello", "Welcome", "Good Bye", "Good day", "Hi"])

def main(name:str = typer.Argument("Rohit"), 
lastname : Optional[str] = typer.Argument(None), 
greet:str = typer.Argument(get_greeting)):
    if lastname is None:
        typer.echo(f"{greet} {name}")
    else:
        typer.echo(f"{greet} {name} {lastname}")



if __name__ == "__main__":
    typer.run(main)