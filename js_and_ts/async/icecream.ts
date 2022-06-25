
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

let is_shop_open = true;

let order = (time : number, work) : Promise<any> => {
	return new Promise( (resolve, reject) => {

		if(is_shop_open){
			setTimeout( () => {
				resolve( work() )
			}, time);
		}
		else{
			reject(console.log("Our shop is closed"))
		}

	} )
}

order(2000, ()=>console.log(`${stocks.Fruits[0]} was selected`))
.then(()=>{
	return order(0, () => console.log("Prodcution has started"))
})

.then(()=>{
	return order(0, () => console.log("The fruit was chopped"))
})

.then( ()=>{

	return order(1000, ()=>{

		console.log(`${stocks.Liquid[0]} and ${stocks.Liquid[1]} was selected`)
	})
})

.then(()=>{
	return order(1000, () => console.log("start the machine"))
})

.then(()=>{

	return order(2000, () => console.log(`Icecream placed on ${stocks.Holder[0]}`))

})

.then(()=>{

	return order(3000, () => console.log(`${stocks.Toppings[0]} was selected`))
})

.then(()=>{
	return order(1000, () => console.log("Icecream was served"))
})

.catch(() => {
	console.log("Custome left")
})

.finally(() => {
	console.log("Day ended, shop is closed")
});
