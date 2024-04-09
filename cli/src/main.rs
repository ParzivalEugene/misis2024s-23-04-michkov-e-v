use clap::{Parser, Subcommand};
use std::path::PathBuf;

pub mod validators {
    pub mod file_validator;
    pub mod module_validator;
}
pub mod services {
    pub mod add_service;
    pub mod build_service;
}

// use validators::file_validator::file_validator;
use validators::module_validator::validate_module_name;

/// Fast cli for building, running and adding modules to your project
#[derive(Debug, Parser)]
#[command(name = "q")]
#[command(about = "Fast cli for building, running and adding modules to your project", long_about = None)]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Debug, Subcommand)]
enum Commands {
    /// Build the whole project
    Build,

    /// Add a new module to the project
    #[command(arg_required_else_help = true)]
    Add {
        /// The name of the module
        name: String,
    },

    /// Run codeforces solution file (only .cpp files in prj.codeforces folder are allowed)
    Run {
        /// The path to the file
        file: PathBuf,
    },
}

fn main() {
    let args = Cli::parse();

    match args.command {
        Commands::Build => {
            println!("Building project");
            services::build_service::build();
        }
        Commands::Add { name } => {
            match validate_module_name(&name) {
                Ok(_) => {}
                Err(e) => {
                    eprintln!("{}", e);
                    return;
                }
            }
            println!("Adding module: {}", name);
            services::add_service::add_module(&name);
        }
        Commands::Run { file } => {
            // match file_validator(&file) {
            //     Ok(_) => {}
            //     Err(e) => {
            //         eprintln!("{}", e);
            //         return;
            //     }
            // }
            // println!("Running file: {:?}", file);
            println!("Not implemented yet...")
        }
    }
}
