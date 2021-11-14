import typer

existing_username = ["rick", "morty"]

def maybe_create_user(username: str):
    if username in existing_username:
        typer.secho("The user already exist", fg = "magenta")
        raise typer.Exit()

    elif username.lower() == "root":
        typer.secho("The root user is reserved", fg= "red")
        raise typer.Exit(code=1)
    
    elif username.lower() in ["user", "users", "new_user"]:
        typer.secho(f"this is not valid username: {username}", fg = "red")
        raise typer.Abort()

    else:
        typer.secho(f"User Created: {username}", fg="green")

def send_new_user_notification(username : str):
    typer.secho(f"Notification sent for new user: {username}", fg="blue")

def main(username: str):
    maybe_create_user(username=username)
    send_new_user_notification(username=username)


if __name__ == "__main__":
    typer.run(main)



