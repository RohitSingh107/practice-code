declare var require: any
const Twilio = require("twilio");

const client = new Twilio("AC99f661c5ca90b4ba6e26c6d14f90b0c7", "1c0ef4477157a21ac033ed7f26489601")

client.messages
	.list()
	.then(messages => console.log(`The most recent message is ${messages[0].body}`));

console.log("Gathering messages")


