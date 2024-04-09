cd $(git rev-parse --show-toplevel)/cli
cargo build --release
if [ $? -ne 0 ]; then
    exit 1
fi
cd ..

alias br="$(git rev-parse --show-toplevel)/cli/target/release/cli"
echo "Successfully added alias 'br' to run the CLI"
