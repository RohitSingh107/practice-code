import typer

def main(name : str = typer.Argument("World", envvar= "TERM")):
    typer.echo(f"Helllo Mr. {name}")

if __name__ == "__main__":
    typer.run(main)

