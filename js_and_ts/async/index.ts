async function rohit() {
	console.log('Insize Rohhit function')

	const response : Response = await fetch("https://api.github.com/users");
	console.log("Before response");
	const users = await response.json();
	console.log("After response");
	return users
}

console.log("Before calling rohit")
let a = rohit();
console.log("After calling rohit")
console.log(a);
a.then(data => console.log(data))
console.log("Last line")
