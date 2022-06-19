"use strict";
// Basic Types
let id = 3;
let company = 'Rohit';
let isPublished = true;
let x = 'Hello';
x = 7;
let ids = [1, 2, 3, 4];
let arr = [1, false, 'Hello'];
//Tuple
let person = [1, 'Rohit', true];
// Tuple Array
let employee;
employee = [
    [1, "A"],
    [2, "B"],
    [3, "C"],
];
let pid = 22;
pid = "Dfsa";
// enum (named constants)
var Directions;
(function (Directions) {
    Directions[Directions["Up"] = 1] = "Up";
    Directions[Directions["Down"] = 2] = "Down";
    Directions[Directions["Left"] = 3] = "Left";
    Directions[Directions["Right"] = 4] = "Right";
})(Directions || (Directions = {}));
var Directions2;
(function (Directions2) {
    Directions2["Up"] = "Up";
    Directions2["Down"] = "Down";
    Directions2["Left"] = "Left";
    Directions2["Right"] = "Right";
})(Directions2 || (Directions2 = {}));
const user = {
    id: 1,
    name: 'John',
};
const user1 = {
    id: 1,
    name: 'John',
};
user1.name = "Rohit";
// user1.id = 7; // can't be assigned to read only
// Tye Assertion
let cid = 1;
// let customerId = cid as number
let customerId = cid;
function addNum(x, y) {
    return x + y;
}
function log(message) {
    console.log("Message is " + message);
}
const add = (a, b) => a + b;
const sub = (a, b) => a - b;
class Person {
    constructor(id, name) {
        console.log("Constructor called");
        this.id = id;
        this.name = name;
    }
    register() {
        return `${this.name} is now registered`;
    }
}
const rohit = new Person(1, "Rohit");
const singh = new Person(2, "Singh");
class PersonImp {
    constructor(id, name) {
        this.id = id;
        this.name = name;
    }
    register() {
        return `${this.name} is now registered`;
    }
}
class Employee extends PersonImp {
    constructor(id, name, position) {
        super(id, name);
        this.position = position;
    }
}
const emp = new Employee(3, "Shawn", "Developer");
console.log(isPublished);
console.log(x);
console.log(arr);
console.log(person);
console.log(employee);
console.log(pid);
console.log(Directions.Down);
console.log(Directions2.Left);
console.log(user);
console.log(addNum(7, 8));
log("JavaScript");
log(7);
console.log(rohit, singh);
console.log(rohit.register());
console.log(emp.register());
