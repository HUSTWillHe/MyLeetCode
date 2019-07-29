#!/usr/bin/env bash -e

MY_NAME=$0
INDEX=''
PROBLEM_NAME=''
CREATE_FILE="/Users/heliwei/Workspace/Projects/ShellScripts/create"
GREP_OPT="-P"
if [[ $(uname) == "Darwin" ]]; then
    GREP_OPT="-E"
fi

# change directory
change_dir(){
    cd $(dirname $0)
}

# check wether create shell exist:
check_file(){
    if [[ ! -f ${CREATE_FILE} ]]; then
        echo "Can't Find File \'create\'! "
    fi
}

# create new solution:
create_new(){
    bash ${CREATE_FILE} $1
}

Help(){
    echo
    echo "Usage: ${MY_NAME} [-i | --index] index [-n | --name] solution_name "
    echo
    exit 1
}

# parse options:
parse_opt(){
    while [[ $1 != "" ]];do
        if [[ `echo ${${i}} | grep ${GREP_OPT} '^-'` ]];then 
            case "${${i}}" in
                -h | --help ) 
                    Help;;
                -i | --index ) 
                    INDEX=$2
                    shift
                    ;;
                -n | --name ) 
                    PROBLEM_NAME=$2
                    shift
                    ;;
            esac
        else
            if [[ ${${i}} ]]; then
                echo
            fi
        fi

        shift
    done
}

# BEGIN OF THE PROGRAM
change_dir

