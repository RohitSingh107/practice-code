
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

let is_shop_open = false

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

function timef(ms : number) : Promise<void> {
	return new Promise( (resolve, reject) => {
      	if(is_shop_open){
      		setTimeout(resolve, ms)
      	}
      	else{
      		reject(console.log("Shop is closed"))
      	}
	} )
}

async function kitchen() : Promise<void> {
	try{
		await timef(2000);
		console.log(`${stocks.Fruits[0]} was selected`);
	
		await timef(0);
		console.log("Start the Production");	
	
		await timef(2000);
		console.log("cut the fruit");	
	
		await timef(0);
		console.log(`${stocks.Liquid[0]} and ${stocks.Liquid[1]} was added`);	

		await timef(1000);
		console.log("Start the machine");	

		await timef(2000);
		console.log(`Icecream placed on ${stocks.Holder[0]}`);

		await timef(3000);
		console.log(`${stocks.Toppings[0]} was selected`);

		await timef(2000);
		console.log("serve the icecream");

	}

	catch(error){
		console.log("Customer left", error)
	}

	finally{
		console.log("Day ended, shop closed");
		
	}
}

kitchen()
