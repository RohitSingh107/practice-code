var Twilio = require("twilio");
var client = new Twilio("AC99f661c5ca90b4ba6e26c6d14f90b0c7", "1c0ef4477157a21ac033ed7f26489601");
client.messages
    .list()
    .then(function (messages) { return console.log("The most recent message is ".concat(messages[0].body)); });
console.log("Gathering messages");
