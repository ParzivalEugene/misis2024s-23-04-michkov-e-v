if [ -z "$1" ]; then
    echo "Required command. Usage: q_cli <command> (commands: run, build, module)"
    exit 1
fi

location=$PWD
cd $(git rev-parse --show-toplevel)
# if run or build
if [ "$1" == "run" ] || [ "$1" == "build" ] || ["$1" == "module"]; then
  . ./scripts/$1.sh
fi

cd $location
