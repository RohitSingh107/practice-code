import typer

def main(
    name: str = typer.Argument(...,),
    lastname : str= typer.Option(... , prompt="Please tell me your last name", help= "Last name of person"),
    action : str = typer.Option(..., prompt=True, confirmation_prompt=True),
    formal: bool = typer.Option(False, help= "Say hi formally"),   
):
    """
    Say hi to NAME, optionally with a --lastname.

    If --formal is used, say hi very formally.
    """

    if formal:
        typer.echo(f"Good day {name} {lastname}. You are {action}")
    else:
        typer.echo(f"Hello {name} {lastname}. You are {action}")


if __name__ == "__main__":
    typer.run(main)

