from twilio.rest import Client

client = Client(
        "AC99f661c5ca90b4ba6e26c6d14f90b0c7",
        "1c0ef4477157a21ac033ed7f26489601"
        )

for msg in client.messages.list():
    print(msg.body)


# msg = client.messages.create(
#         to = "+919319126891",
#         from_ = "+17156016815",
#         body = "Hello from Python",
#         )

# print(f"Created a new message: {msg.sid}")


# for msg in client.messages.list():
#     print(f"Deleting {msg.body}")
#     msg.delete()
