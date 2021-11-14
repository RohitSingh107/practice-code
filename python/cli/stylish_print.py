import typer

def main(good: bool= True):
    message_start = "everything is "
    if good:
        ending = typer.style("good", fg=typer.colors.GREEN, bold=True)
    else:
        ending = typer.style("bad", fg=typer.colors.RED,bg= typer.colors.YELLOW , bold=True)
    message = message_start + ending
    typer.echo(message)
    typer.secho("Done", fg= typer.colors.BLUE, bg= typer.colors.MAGENTA, bold=True)

if __name__ == "__main__":
    typer.run(main)