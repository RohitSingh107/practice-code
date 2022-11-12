pub trait Vehicle {
    fn forward(&self) -> String;
    fn backward(&self) -> String;

    fn turn_ignition() -> String {
        String::from("vromm croom")
    }
}

pub struct Car {
    color: String,
}

impl Vehicle for Car {
    fn forward(&self) -> String {

        String::from(format!("{} car Going Forward", self.color))

    }
    fn backward(&self) -> String {
        String::from(format!("{} car Going Backward", self.color))

    }
}

pub struct Truck {
    color: String,
}

impl Vehicle for Truck {
    fn forward(&self) -> String {
        String::from(format!("Driving my {} truck Forward", self.color))

    }
    fn backward(&self) -> String {
        String::from(format!("Driving my {} truck Backward", self.color))
    }

    fn turn_ignition() -> String {
        String::from("Turning truck")
    }
}
fn main(){

    let car = Car{color: String::from("Red")};
    let truck = Truck{color: String::from("Blue")};

    println!("{}", Car::turn_ignition());
    println!("{}", car.forward());
    println!("{}", car.backward());

    println!("\n");

    println!("{}", Truck::turn_ignition());
    println!("{}", truck.forward());
    println!("{}", truck.backward());
}
