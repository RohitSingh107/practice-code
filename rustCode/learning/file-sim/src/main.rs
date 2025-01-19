
use core::fmt;
use std::fmt::Display;

// use rand::{random};

#[derive(Debug, PartialEq)]
pub enum FileState {
    OPEN,
    CLOSE
}

#[derive(Debug)]
pub struct File {
    name: String,
    data : Vec<u8>,
    state: FileState
}

impl Display for FileState {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {

        match *self {
            FileState::OPEN => write!(f, "OPEN"),
            FileState::CLOSE => write!(f, "CLOSED")
        }

    }
}


impl Display for File {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {

        write!(f, "<{} ({})>", self.name, self.state)

    }
}

impl File {

    pub fn new(name: &str) -> Self {
        Self { data : vec![], name:  String::from(name), state: FileState::CLOSE}
    }

    pub fn new_with_data(name: &str, data: &Vec<u8>) -> Self {
        let mut file = Self::new(name);
        file.data = data.clone();

        file

    }

    pub fn open(self: &mut Self) -> Result<bool, String> {
        self.state = FileState::OPEN;
        Ok(true)
    }

    pub fn read(self : &Self, save_to : &mut Vec<u8>) -> Result<usize, String> {


        if self.state != FileState::OPEN {
            return Err(String::from("File is not open for reading."));
        }

        let mut tmp = self.data.clone();

        let l = self.data.len();

        save_to.reserve(l);
        save_to.append(&mut tmp);

        Ok(l)
    }

    pub fn close(self: &mut Self) -> Result<bool, String> {
        self.state = FileState::CLOSE;
        Ok(true)
    }
}

fn main() {
    let mut f = File::new_with_data("f1.txt", &vec![114, 117, 115, 116, 33]);
    let mut buffer: Vec<u8> = vec![];


    f.open().unwrap();
    // println!("{}", f);
    let size = f.read(&mut buffer).unwrap();
    f.close().unwrap();

    // println!("{:?}", f);
    println!("{}", f);

    let text = String::from_utf8_lossy(&buffer);
    println!("{:?}, size: {} bytes", text, size);
    // println!("{}, size: {} bytes", text, size);
}
