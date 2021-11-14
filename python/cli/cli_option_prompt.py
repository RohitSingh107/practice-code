import typer

def main(name: str, email: str = typer.Option(None, prompt=True, confirmation_prompt=True), password: str = typer.Option(..., "--pass", prompt=True, confirmation_prompt=True, hide_input=True)):

    typer.echo(f"Hello {name}, your email is  {email}. Doing something with very secure with password.")
    typer.echo(f"...just kidding, here it is, very insecure: {password}")


if __name__ == "__main__":
    typer.run(main)