import typer

def main(name: str = typer.Argument("World", help="The name of user to greet", show_default="Your Nice Name", metavar="✨username✨"), 
lastname: str = "" , 
formal: bool = False):
    """
    Say hi to NAME, optionally with a --lastname.

    If --formal is used, say hi very formally.
    """
    if formal:
        typer.echo(f"Good day {name} {lastname}.")
    else:
        typer.echo(f"Hello {name} {lastname}")



if __name__ == "__main__":
    typer.run(main)