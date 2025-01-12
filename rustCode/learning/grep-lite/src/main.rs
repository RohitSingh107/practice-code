use regex::Regex;
use clap::Parser;
use std::fs::File;
use std::io::BufReader;
use std::io::prelude::*;

#[derive(Parser, Debug)]
#[command(version, about, long_about = None)]
struct Args {
    #[arg(short, long, default_value_t = String::from("diam"))]
    pattern: String,

    #[arg(short, long, default_value_t = 1)]
    contex: usize,

    #[arg(short, long)]
    file: String,
}

fn main() {
    let args = Args::parse();

    let needle = args.pattern;
    let ctxln = args.contex;

    let re = Regex::new(&needle).unwrap();

    let f = File::open(&args.file).unwrap();
    let reader = BufReader::new(f);

    let mut haystack = reader;


    let mut tags: Vec<usize> = vec![];
    let mut context : Vec<Vec<(usize, String)>> = vec![];

    let mut line = String::new();
    let mut i = 0;
    loop {
        let len = haystack.read_line(&mut line).unwrap();
        if len == 0 {
            break;
        }
        match re.find(&line) {
            Some(_) => {
                tags.push(i);
                let v = Vec::with_capacity(2 * ctxln + 1);
                context.push(v);
            },
            None => ()

        }
        
        // println!("{} ({} bytes long)", line, len);
        line.truncate(0);
        i = i + 1;
    }



    let f = File::open(args.file).unwrap();
    let reader = BufReader::new(f);

    let haystack = reader;
    for (i, line_result) in haystack.lines().enumerate() {
        if let Ok(line) = line_result {
            for (j, tag) in tags.iter().enumerate() {
                let lower_bound = tag.saturating_sub(ctxln);
                let upper_bound = tag + ctxln;

                if lower_bound <= i && i <= upper_bound {
                    context[j].push((i, line.to_string()));
                }
            }
        }
    }

    for match_tag in context.iter() {
        for (l, line) in match_tag.iter() {

            println!("{}:\t{}", l+1, line)

        }
        println!("\n")

    }

    // println!("{:?}", tags);
    // println!("{:?}", context);





}
