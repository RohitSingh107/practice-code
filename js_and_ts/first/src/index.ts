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

// Objects
// const user: {
// 	id: number,
// 	name: string,
// } = {
// 	id: 1,
// 	name: 'John',
// }

type User = {
	id: number
	name: string
}

const user: User = {
	id: 1,
	name: 'John',
}

interface UserInterface  {
	readonly id: number
	name: string
	age?: number
}

const user1: UserInterface = {
	id: 1,
	name: 'John',
}

user1.name = "Rohit"
// user1.id = 7; // can't be assigned to read only


// Tye Assertion
let cid: any = 1;
// let customerId = cid as number
let customerId = <number>cid

function addNum(x: number, y:number) : number {
	return x + y
}

function log(message: string | number): void {
	console.log("Message is " + message);
}

interface MathFunc {
	(x: number, y: number): number
}

const add: MathFunc = (a: number, b: number) : number => a + b;
const sub: MathFunc = (a: number, b: number) : number => a - b;


class Person{
	private id: number
	name: string

	constructor(id: number, name: string){
		console.log("Constructor called")
		this.id = id
		this.name = name
	}
	
	register(){

		return `${this.name} is now registered`
	}

}


const rohit = new Person(1, "Rohit")
const singh = new Person(2, "Singh")


interface PersonInterface  {
	id: number
	name: string
	register(): string
}

class PersonImp implements PersonInterface {
	id: number
	name: string
	constructor(id: number, name: string){
		this.id = id
		this.name = name
	}
	register(): string {
		return `${this.name} is now registered`
	}

}

class Employee extends PersonImp {
	position: string

	constructor(id: number, name: string, position: string){
		super(id, name)
		this.position = position
	}

}

const emp = new Employee(3, "Shawn", "Developer")

// Generics
function getArray<T>(items: T[]) : T[] {
	return new Array().concat(items)
}
let numArray = getArray<number>([1,2,3,4])
let strArray = getArray<string>(["d","v","b","a"])
// numArray.push('hello')

console.log(isPublished)
console.log(x)
console.log(arr)
console.log(person)
console.log(employee)
console.log(pid)
console.log(Directions.Down)
console.log(Directions2.Left)
console.log(user)

console.log(addNum(7, 8))

log("JavaScript")
log(7)

console.log(rohit, singh)
console.log(rohit.register())

console.log(emp.register())
