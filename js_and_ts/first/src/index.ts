// Basic Types

let id: number = 3
let company: string = 'Rohit'

let isPublished : boolean = true

let x: any = 'Hello'

x = 7

let ids: number[] = [1, 2, 3, 4]

let arr: any[] = [1, false, 'Hello']

//Tuple
let person: [number, string, boolean] = [1, 'Rohit', true]
// Tuple Array
let employee: [number, string][]

employee = [
	[1, "A"],
	[2, "B"],
	[3, "C"],
]

let pid: string | number = 22

pid = "Dfsa"

// enum (named constants)
enum Directions {
	Up = 1, // By default it's 0
	Down,
	Left,
	Right,
}
enum Directions2 {
	Up = 'Up', // By default it's 0
	Down = 'Down',
	Left = 'Left',
	Right = 'Right',
}


console.log(isPublished)
console.log(x)
console.log(arr)
console.log(person)
console.log(employee)
console.log(pid)
console.log(Directions.Down)
console.log(Directions2.Left)
