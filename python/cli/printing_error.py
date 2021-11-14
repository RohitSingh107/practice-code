import typer


def main():
    typer.secho(f"Here is something written to std error", 
    fg = "red",
    err=True)


if __name__ == "__main__":
    typer.run(main)