
type Stock = {
	Fruits : string[]
	Liquid : string[]
	Holder : string[]
	Toppings : string[]
}

let stocks : Stock = {
	Fruits: ["stawberry", "grapes", "banana", "apple"],
	Liquid: ["water", "ice"],
	Holder: ["cone", "cup", "stick"],
	Toppings: ["chocolates", "peanuts"]
}

let is_shop_open = true

// async function order() {
// 	try{
// 		await abc;
// 	}

// 	catch(error){
// 		console.log("Runs code anyway")
// 		console.error(error)
// 	}

// 	finally{
// 		console.log("Runs code anyway");
		
// 	}
// }

let toppings_choice = () : Promise<void> => {
	return new Promise( (resolve, reject) => {
		setTimeout(() => {
			resolve(console.log("Which topping would ypu love? "))
		}, 3000)
	} )
}

let tmp = () : Promise<void> => {
	return new Promise( (resolve, reject) => {
		setTimeout(() => {
			resolve(console.log("Temp function"))
		}, 2000)
	} )
}

let tmp2 = () : Promise<void> => {
	return new Promise( (resolve, reject) => {
		setTimeout(() => {
			resolve(console.log("Temp 2 function"))
		}, 4000)
	} )
}
let tmp4 = () : Promise<void> => {
	return new Promise( (resolve, reject) => {
		setTimeout(() => {
			resolve(console.log("Temp 4 function"))
		}, 5000)
	} )
}
async function kitchen() : Promise<void> {
	console.log(" A ")
	console.log(" B ")
	console.log(" C ")

	await tmp()
	await tmp4()
	await tmp2()

	console.log(" D ")
	console.log(" E ")
}

async function tmp3() {
	await toppings_choice()
}

kitchen()
tmp3()
console.log("Cleaning the dishes");
console.log("Cleaning the tables");
console.log("Taking other orders");


